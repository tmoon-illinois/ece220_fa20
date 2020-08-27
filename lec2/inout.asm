        .ORIG x3000
        ;R1<-mem[mem[KBSRAddr]]
POLL_IN
        LDI     R1, KBSRAddr
        BRzp    POLL_IN
        LDI     R0, KBDRAddr
POLL_OUT
        LDI     R1, DSRAddr
        BRzp    POLL_OUT
        STI     R0, DDRAddr
        HALT
DSRAddr    .FILL   xFE04
DDRAddr    .FILL   xFE06
KBSRAddr    .FILL   xFE00
KBDRAddr    .FILL   xFE02

.END
