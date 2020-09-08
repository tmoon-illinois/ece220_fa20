        .ORIG       x3000
        ;assume 0-9 and +,=
        LEA     R1, MyExp
LOOP
        LDR     R0, R1, #0
        LD      R2, NegEq
        ADD     R2, R0, R2      ;compare '='
        BRz     DONE
        LD      R2, NegPlus
        ADD     R2, R0, R2      ;compare '+'
        BRz     DO_ADD
        LD      R2, Neg0
        ADD     R0, R0, R2      ;actual number
        JSR     PUSH            ;push a number
        ADD     R1, R1, #1
        BRnzp   LOOP
DO_ADD
        JSR     POP
        ADD     R5, R5, #0      ;chekc underflow
        BRp     ERR
        ADD     R2, R0, #0
        JSR     POP
        ADD     R5, R5, #0      ;check underflow
        BRp     ERR
        ADD     R3, R0, #0
        ADD     R0, R2, R3
        JSR     PUSH
        ADD     R1, R1, #1
        BRnzp   LOOP
DONE
        JSR     POP
        HALT
ERR
        LEA     R0, ErrMsg
        PUTS
        HALT


;;PUSH subroutine
;IN: R0 (value)
;OUT: R5(0-success, 1-fail)
;R3: STACK_END
;R6: STACK_TOP
PUSH
;callee-save & initialize registers
        ST      R3, SaveR3
        ST      R6, SaveR6
        AND     R5, R5, #0
        LD      R3, STACK_END
        LD      R6, STACK_TOP
;overflow?
;Check if STACK_TOP = STACK_END - 1
;Or check if STACK_TOP - (STACK_END - 1) = 0
        ADD     R3, R3, #-1
        NOT     R3, R3
        ADD     R3, R3, #1
        ADD     R3, R3, R6
        BRz     OVERFLOW
;it is NOT overflow
        STR     R0, R6, #0
        ADD     R6, R6, #-1
        ST      R6, STACK_TOP
        BRnzp   DONE_PUSH
;it is overflow
OVERFLOW
        ADD     R5, R5, #1
;restore registers
DONE_PUSH
        LD      R3, SaveR3
        LD      R6, SaveR6
        RET

;;POP subroutine
;IN: none
;OUT: R0 (value)
;OUT: R5 (0: success, 1: fail)
;R3: STACK_START
;R6: STACK_TOP
POP
;callee-save & initialize registers
        ST      R3, SaveR3
        ST      R6, SaveR6
        AND     R5, R5, #0
        LD      R3, STACK_START
        LD      R6, STACK_TOP
;underflow?
;Check if STACK_TOP = STACK_START
;Or check if STACK_TOP - STACK_START = 0
        NOT     R3, R3
        ADD     R3, R3, #1
        ADD     R3, R3, R6
        BRz     UNDERFLOW
;it is NOT underflow
        ADD     R6, R6, #1
        LDR     R0, R6, #0
        ST      R6, STACK_TOP
        BRnzp   DONE_POP

;it is underflow
UNDERFLOW
        ADD     R5, R5, #1

;restore registers
DONE_POP
        LD      R3, SaveR3
        LD      R6, SaveR6
        RET
        

;temp memory
SaveR3	.BLKW	#1
SaveR6	.BLKW	#1
STACK_END	.FILL	x3F00
STACK_START	.FILL	x4000	
STACK_TOP	.FILL	x4000	


;MyExp   .STRINGZ "724++="
MyExp   .STRINGZ "7++="
NegPlus .FILL   #-43
NegEq   .FILL   #-61
Neg0    .FILL   #-48
ErrMsg  .STRINGZ "INvalid expression\n"
.END
