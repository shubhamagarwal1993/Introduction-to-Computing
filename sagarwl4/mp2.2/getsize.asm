; This file should be submitted in both mp2.1 and mp2.2
; Comments
.ORIG x3100

;SAVE ALL THE REGISTERS  
		ST R0,SAVE_0		;
		ST R1,SAVE_1		;
		ST R6,SAVE_6		;
		ST R7,SAVE_7		;


;PURPOSE OF REGISTERS
;R0 - will be used for all the input and output.
;R1 - copy of R0 where all the code will be executed.
;R6 - when the size is valid, the size is stored in R6. 
;R7 - has the PC value of the next instruction after this subroutine returns. 


;CLEAR REGISTERS
		AND R0,R0,#0		;clear
		AND R1,R1,#0		;clear 
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
		ADD R1,R1,#-2		;checking for lower limit.
		BRn INVALID		;
		BRzp UPPER_LIMIT	;	
		
INVALID		LEA R0,ERRORSIZE	;
		PUTS
		BRnzp LOOP_ST		;if the input is invalid, then ask for input again

UPPER_LIMIT	ADD R1,R1,#2		;get original value
		ADD R1,R1,#-9		;
		BRp INVALID		
		BRnz FINAL

FINAL		ADD R1,R1,#9		;input number

		ADD R6,R6,R1		;loads the final valid input into R6


;LOAD ALL THE REGISTERS TO THEIR INITIAL VALUE SO THAT NO VALUE HAS CHANGED AFTER THIS SUBROUTINE
		LD R0,SAVE_0		;load from x3150
		LD R1,SAVE_1		;load from x3151
		LD R6,SAVE_6		;load from x3152
		LD R7,SAVE_7		;load from x3153
		RET
ASKSIZE		.STRINGZ "\nPlease enter the size of your board[2..9]:\n" ; Words displayed to ask size
ERRORSIZE 	.STRINGZ "\nYour input is not valid!\n"	; Words that should be displayed if input is not valid
SAVE_0		.BLKW 1
SAVE_1		.BLKW 1
SAVE_6		.BLKW 1
SAVE_7		.BLKW 1
.END
