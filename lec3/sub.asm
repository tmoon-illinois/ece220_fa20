        .ORIG   x3000
        LD      R2, Value1
        LD      R3, Value2
        JSR     SUBT
        HALT
; R6 = -R0
NEG
        NOT     R6, R0
        ADD     R6, R6, #1
        RET
; R1 = R2 - R3
SUBT
        ;callee-save
        ST      R0, SaveR0_SUB
        ST      R6, SaveR6_SUB
        ST      R7, SaveR7_SUB
        ADD     R0, R3, #0
        JSR     NEG
        ;R6 = -R3
        ADD     R1, R2, R6
        LD      R0, SaveR0_SUB
        LD      R6, SaveR6_SUB
        LD      R7, SaveR7_SUB
        RET

Value1 .FILL #5
Value2 .FILL #3
SaveR0_SUB  .BLKW   #1
SaveR6_SUB  .BLKW   #1
SaveR7_SUB  .BLKW   #1

.END
