.ORIG x3000

;PURPOSE OF EACH REGISTER
;R0 - 
;R1 - 
;R2 - 
;R3 - will tell if the string is a palindrome(1) or not(0) 
;R4 - 
;R5 - 
;R6 - 

;CLEARING REGISTERS
	AND R0,R0,#0
	AND R1,R1,#0
	AND R2,R2,#0
	AND R3,R3,#0
	AND R4,R4,#0
	AND R5,R5,#0
	AND R6,R6,#0


        LDI    R2,STRING
	BRnzp LOOP
LOOP1   ADD   R2,R2,#1
        ADD   R5,R5,#1

LOOP    LDR   R4,R2,#0
        BRp   LOOP1
        AND   R7,R7,#0
        ADD   R7,R5,#-1
        NOT   R7,R7
        ADD   R7,R7,#1
        AND   R4,R4,#0
        ADD   R4,R4,R5
        LD    R2,STRING
        ADD   R4,R4,R2
        ADD   R4,R4,R5
        AND   R6,R6,#0
        ADD   R6,R6,R4
        ADD   R6,R6,R7

THIRD   LDR   R5,R2,#0
        BRz   BREAK
        STR   R5,R4,#0
        ADD   R4,R4,#-1
        ADD   R2,R2,#1
        BRnzp THIRD

BREAK   ADD   R4,R4,#0
        ADD   R5,R5,#0
        LD    R2,STRING

FOURTH  LDR   R4,R2,#0
        BRz   AGAIN
        LDR   R5,R6,#0
        NOT   R5,R5
        ADD   R5,R5,#1
        ADD   R2,R2,#1
        ADD   R6,R6,#1
        ADD   R7,R4,R5
        BRz   FOURTH
        AND   R3,R3,#0
        	
AGAIN   ADD   R3,R3,#0
        ADD   R3,R3,#1
        TRAP  x25

STRING  .FILL x4000
         
.END
