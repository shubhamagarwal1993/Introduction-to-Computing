.ORIG x3000

;BASIC IDEA: if the input number -5 is 0, then we have x5 ****** and we subtract the memory address x4108 from R3 which if 0, we will know there is no x0005 in the 8 memory locarions.


;PURPOSE OF EACH REGISTER
;R1 - will be a pointer to input numbers
;R2 - will contain the NOT of number x0005
;R3 - copy of R1
;R4 - will be 1 if x5 exists or else 0
;R5 - contains number-x5 

;CLEARING THE REGISTERS
	AND R1,R1,#0		;clear register
	AND R2,R2,#0		;clear register
	AND R3,R3,#0		;clear register
	AND R4,R4,#0		;clear register
	AND R5,R5,#0		;clear register
	
;LOADING THE REGISTERS
	ADD R2,R2,#5		;put x0005 in R2
	NOT R2,R2		;-ve of x0005
	ADD R2,R2,#1		;2's complememt of -ve x0005

	LD R3,#15		;will tell us when the 8 memory locations end
	NOT R3,R3
	ADD R3,R3,#1


LOOP2	LDI R1,PTR		;R1 is a pointer to input numbers
	ADD R1,R1,#1

	AND R3,R3,#0	
	ADD R3,R1,R3			;if we get 0 in R3, we will go to halt
	BRz STOP
	
	
;ADDING THE NUMBER AND -5
	ADD R5,R1,R2	
	BRz LOOP1
	BRnp LOOP2
	


LOOP1	ADD R4,R4,#1
	BRnzp STOP


STOP	TRAP x25
PTR	.FILL x4100
	.FILL x4108
.END
