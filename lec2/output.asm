        .ORIG x3000
        LD      R0, ASCII_0
POLL
        LDI     R1, DSRAddr
        BRzp    POLL
        STI     R0, DDRAddr
        HALT
DSRAddr    .FILL   xFE04
DDRAddr    .FILL   xFE06
ASCII_0     .FILL   x30
.END
