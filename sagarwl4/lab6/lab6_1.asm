.ORIG x3000				;code starts here

;PURPOSE OF REGISTERS
;R0 - used to pass parameter 'n' into to the subroutine
;R1 - used to pass the return value f(n) from sub to prog
;R2 - used as a counter for adding in the subroutine
;R4 - stores the final result(R1 has the final result but R4 is a copy of the answer)

;CLEARING ALL THE REGISTERS
		AND R0,R0,#0		;clear
		AND R1,R1,#0		;clear
		AND R2,R2,#0		;clear
		AND R3,R3,#0		;clear
		AND R4,R4,#0		;clear
		AND R5,R5,#0		;clear
		AND R6,R6,#0		;clear

;CODE EXECUTION

		LD R0, N		;load R0 with value to be passed into the subroutine
		STI R7,SaveReg		;we save the value of R7 		
		JSR SUB			;jump to the subroutine
		
		ADD R4,R4,R1		;we load the value of R1 into R4 to see if STI WORKS		

		HALT			;TRAPx25
SUB		
		ADD R2,R2,#3
loop1		ADD R1,R1,R0		;load R1 with N
		ADD R2,R2,#-1		;decrement counter
		BRp loop1		;go to loop1 if R2 is positive
		ADD R1,R1,#4		;load R1 with 3N+4
		RET			;loads saved value of R7 into the PC

N		.FILL #2		;
SaveReg		.FILL x0000		;
RESULT		.FILL x0000		;

		.END
						 
