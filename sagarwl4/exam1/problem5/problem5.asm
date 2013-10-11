.ORIG x3000

;BASIC IDEA: A-B(A/B)=modulo


;PURPOSE OF EACH REGISTER
;R0 - a counter to find quotient of (A/B)
;R1 - contains A/B
;R2 - input A is stored here.
;R3 - input B is stored here.
;R4 - A modulo B is stored here
;R5 - acts as a counter for multiplication 
;R6 - (NOT+1) of R3 - -ve of R3
;R7 - copy of A

;CLEARING THE REGISTERS
	AND R0,R0,#0		;clear register
	AND R1,R1,#0		;clear register
	AND R2,R2,#0		;clear register
	AND R3,R3,#0		;clear register
	AND R4,R4,#0		;clear register
	AND R5,R5,#0		;clear register
	AND R6,R6,#0		;clear register
	AND R7,R7,#0

;LOADING A and B INTO R2,R3
	LD R2,#19
	LD R3,#19

;APPLYIING DIVISION OF A and B
	
	ADD R7,R7,R2		;copy of A
LOOP	NOT R6,R3		;-ve of B
	ADD R6,R6,#1		;2's complement of -B
	ADD R0,R0,#1		;counter for division	
	ADD R2,R2,R6		;A-B stored in A	
	BRp LOOP
	BRn LOOP1
	BRz STOP	

LOOP1	ADD R0,R0,#-1		;here R0 has A/B
	BRnzp LOOP2

LOOP2	ADD R5,R3,R5		;R5 has BxR0
	ADD R0,R0,#-1		
	BRp LOOP2
	BRz LOOP3
	
LOOP3	NOT R5,R5
	ADD R5,R5,#1
	ADD R4,R7,R5

STOP	TRAP x25
	.FILL x0007
	.FILL x0003
.END
