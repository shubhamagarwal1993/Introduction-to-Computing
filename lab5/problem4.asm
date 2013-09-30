;Answer problem 4 here

 .ORIG x3000
       AND   R1,R1,#0
       ADD   R1,R1,#5
       LD    R2,NUM
       LD    R3,STORE
       AND   R6,R6,#0
       ADD   R6,R6,#4
       NOT   R1,R1
       ADD   R1,R1,#1
LOOP   LDR   R5,R2,#0
       ADD   R5,R5,R1
       BRp   BREAK
       ADD   R2,R2,#0
       ADD   R6,R6,#-1
       BRp   LOOP
       TRAP  x25
BREAK  LDR   R5,R2,#0
       STR   R5,R3,#0
       ADD   R3,R3,#1
       TRAP  x25
NUM    .FILL x40A0
STORE  .FILL x40AA
       .END
