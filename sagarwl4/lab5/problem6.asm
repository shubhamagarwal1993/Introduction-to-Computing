;Answer problem 6 here
.ORIG x3000
        LDI   R1,NUM
        LD    R2,ASIZE
        LD    R3,BSIZE
        AND   R6,R6,#0
        ADD   R6,R6,R3
        ADD   R3,R3,R1
        ADD   R4,R4,R1
        ADD   R4,R4,R1
        AND   R7,R7,#0
        ADD   R1,R6,#-1
LOOP    LDR   R5,R2,#0
        ADD   R7,R5,R7
        LDR   R5,R3,#0
        ADD   R7,R7,R5
        STR   R4,R7,#0
        ADD   R4,R4,#1
        ADD   R3,R3,#1
        ADD   R2,R2,#1
        ADD   R1,R1,#-1
        BRp   LOOP
        TRAP  x25
NUM     .FILL x4000
ASIZE   .FILL x4001
BSIZE   .FILL x4001
        .END
