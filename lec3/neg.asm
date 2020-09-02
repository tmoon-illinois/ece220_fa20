        .ORIG   x3000
        LD      R0, Value
        JSR     NEG
        ADD     R1, R6, R0
        HALT

NEG
        NOT     R6, R0
        ADD     R6, R6, #1
        RET

Value .FILL #5

.END
