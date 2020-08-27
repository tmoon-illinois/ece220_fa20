        .ORIG x3000
        ;R1<-mem[mem[KBSRAddr]]
        LEA     R2, MyStr
LOOP
        LDR     R0, R2, #0
        BRz     POLL_IN
PROMPT
        LDI     R1, DSRAddr
        BRzp    PROMPT
        STI     R0, DDRAddr
        ADD     R2, R2, #1
        BRnzp   LOOP
POLL_IN
        LDI     R1, KBSRAddr
        BRzp    POLL_IN
        LDI     R0, KBDRAddr
        LD      R2, NegCR
        ADD     R2, R0, R2
        BRz     TERM
POLL_OUT
        LDI     R1, DSRAddr
        BRzp    POLL_OUT
        STI     R0, DDRAddr
        BRnzp   POLL_IN
TERM
        HALT
DSRAddr    .FILL   xFE04
DDRAddr    .FILL   xFE06
KBSRAddr    .FILL   xFE00
KBDRAddr    .FILL   xFE02
MyStr       .STRINGZ    "command> "
NegCR       .FILL   #-13
.END
