; This file should be submitted in both mp2.1 and mp2.2
; Comments
.ORIG x3100

;save all the registers

;PURPOSE OF REGISTERS
;R0 - will 
;R1 - used to display a message 
;R2 - used to check if the size is from 2 to 9
;R3 - 
;R4 - 
;R5 - 
;R6 - when the size is valid, the size is stored in R6 
;R7 - 


;CLEAR REGISTERS
		AND R0,R0,#0
		AND R1,R1,#0		;clear 
		AND R2,R2,#0 		;clear
		;AASCII_L_DIF		;
		AND R3,R3,#0		;clear
		AND R6,R6,#0		;clear
				
;CODE EXECUTION
LOOP_ST		LEA R0,ASKSIZE		;asks the size from the user
		PUTS			;calls a system trap routine which outputs string
		GETC			;place ASCII value of input character into R1

		ADD R1,R1,R0
		OUT
		
;GETTING ACTUAL VALUE IN ASCII
		ADD R1,R1,#-15		;add 48 (x0030) to the input ASCII 
		ADD R1,R1,#-15		;
		ADD R1,R1,#-15		;R1 now contains the actual value	
		ADD R1,R1,#-3

;CHECKING FOR VALID INPUT
		ADD R1,R1,#-2		;
		BRn INVALID		;
		BRzp UPPER_LIMIT	;	
		
INVALID		LEA R0,ERRORSIZE	;
		PUTS
		BRnzp LOOP_ST		;if the input is invalid, then ask for input again

UPPER_LIMIT	ADD R1,R1,#2		;get original value
		ADD R1,R1,#-9		;clear R2 - will have previos loaded value
		BRp INVALID		
		BRnz FINAL

FINAL		ADD R1,R1,#9		;input number

		ADD R6,R6,R1		;loads the final valid input into R6


		;load all the registers back

		RET
ASKSIZE		.STRINGZ "\nPlease enter the size of your board[2..9]:\n" ; The words that should be displayed to ask size
ERRORSIZE 	.STRINGZ "\nYour input is not valid!\n"	; The words that should be displayed if the input is not valid
.END
