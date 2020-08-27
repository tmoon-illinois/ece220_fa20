        .ORIG x3000
        ;R1<-mem[mem[KBSRAddr]]
POLL
        LDI     R1, KBSRAddr
        BRzp    POLL
        LDI     R1, KBSRAddr    ;1000000....
        LDI     R0, KBDRAddr
        LDI     R1, KBSRAddr    ;0000000....
        HALT
KBSRAddr    .FILL   xFE00
KBDRAddr    .FILL   xFE02

.END
