.ORIG x3000

;BASIC IDEA - we will AND the 'number N' and 'N-1'. If the AND is 0, then the number is a power of 2 or else not  **** R5


;PURPOSE OF EACH REGISTER
;R1 - contains N-1
;R2 - input N is stored here.
;R3 - tells if N is a power of 2(1) or not(0)
;R4 - contains AND of N and N-1
;R5 - checks for case when N is 0

;CLEARING THE REGISTERS
	AND R0,R0,#0		;clear register
	AND R1,R1,#0		;clear register
	AND R2,R2,#0		;clear register
	AND R3,R3,#0		;clear register
	AND R4,R4,#0		;clear register

;LOADING R5 with 0
	AND R5,R5,#0


;LOADING N INTO R2
	LD R2,#9		;load N in R2
	ADD R5,R5,R2
	BRz STOP


;FINDING N-1 
	ADD R1,R2,#-1		;add -1 to R2 and store in R1

;ANDING 'N' and 'N-1'
	AND R4,R1,R2
	BRz POWER
	BRnp STOP

;POWER OF 2
POWER	ADD R3,R3,#1
BRnzp	STOP



STOP	TRAP x25
	.FILL x0008
.END
