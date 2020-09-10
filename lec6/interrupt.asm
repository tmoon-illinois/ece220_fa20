.ORIG   x3000
;load ISR address to INTV (M[x0180] <- MYISR)
LEA     R0, MYISR
STI     R0, KBINTV 
;enable IE bit of KBSR
LD      R0, EN_IE
STI     R0, KBSR
;main loop to print 0 to 9
LD      R0, NUM0
DISP
LDI     R1, DSR
BRzp    DISP
STI     R0, DDR
LD      R1, NUM9
NOT     R1, R1
ADD     R1, R1, #1
ADD     R1, R0, R1
BRz     RESET
ADD     R0, R0, #1
BRnzp   DISP
RESET
LD      R0, NUM0
BRnzp   DISP

;; Your interrrupt service routine here
MYISR
ST  R0,SaveR0 ;callee-save
ST  R1,SaveR1 ;callee-save
ST  R7,SaveR7 ;callee-save
LDI R0,KBDR ;read a charcter from keyboard and clear ready bit
LD      R0, ALP_A
DISP_INT
;load DSR and if ready, write a character to DDR
LDI     R1, DSR
BRzp    DISP_INT
STI     R0, DDR
;compare the current char with ‘Z’
LD      R1, ALP_Z
NOT     R1, R1
ADD     R1, R1, #1 ;R1 = -Z
ADD     R1, R1, R0
BRz     DONE_INT
ADD     R0, R0, #1
BRnzp   DISP_INT
DONE_INT
LD  R0,SaveR0
LD  R1,SaveR1
LD  R7,SaveR7
RTI


EN_IE   .FILL   x4000 ;enable IE 0100_0000_0000_0000
NUM0    .FILL   x0030
NUM9    .FILL   x0039
ALP_A   .FILL   x41
ALP_Z   .FILL   x5A
KBSR    .FILL   xFE00
KBDR    .FILL   xFE02
DSR     .FILL   xFE04
DDR     .FILL   xFE06
KBINTV  .FILL   x0180 ;INT vector table address for keyboard
SaveR0  .BLKW   #1
SaveR1  .BLKW   #1
SaveR7  .BLKW   #1
.END


