; This file should be submitted in both mp2.1 and mp2.2
; Comments
.ORIG x3300

;SAVE ALL THE REGISTERS since we dont want the value of registers to be lost when this subroutine works 
		ST R0,SAVE_0		;
		ST R1,SAVE_1		;
		ST R2,SAVE_2		;		
		ST R3,SAVE_3		;
		ST R7,SAVE_7		;

		ADD R6,R6,#3
;----------------------------------------------------------------------------------------------------------------------------------------
;------------------------row starts here-------------------------------------------------------------------------------------------------
;----------------------------------------------------------------------------------------------------------------------------------------

;SAVE ALL THE REGISTERS since we dont want the value of registers to be lost when this subroutine works 
				
		

;PURPOSE OF REGISTERS
;R0 - does all the input and output
;R1 - is a copy of R0 and all calculation is done on R1
;R3 - has the -ve of R1, used to determine if the row number entered is right or wrong
;R5 - stores the final value of the row number

;CLEAR REGISTERS
				

;CODE EXECUTION
LOOP_ST_R	AND R0,R0,#0		;clear
		AND R1,R1,#0		;clear 
		AND R3,R3,#0		;clear
		AND R5,R5,#0		;clear

		LEA R0,ASKROW		;asks the size from the user
		PUTS			;calls a system trap routine which outputs string
		GETC			;place ASCII value of input character into R1

		ADD R1,R1,R0
		OUT
		
;GETTING ACTUAL VALUE IN ASCII
		ADD R1,R1,#-15		;add 48 (x0030) to the input ASCII 
		ADD R1,R1,#-15		;
		ADD R1,R1,#-15		;R1 now contains the actual value	
		ADD R1,R1,#-3

;INVERT R1 AND STORE INTO R3
		NOT R3,R1		;
		ADD R3,R3,#1		;the -ve 2s complement is stored in R3

;CHECKING FOR VALID INPUT
		ADD R1,R1,#-1		;
		BRn INVALID_R		;
		BRzp UPPER_LIMIT_R	;	
		
INVALID_R	LEA R0,ERRORINPUT	;
		PUTS
		BRnzp LOOP_ST_R		;if the input is invalid, then ask for input again

UPPER_LIMIT_R	ADD R1,R1,#1		;get original value
		
		ADD R3,R3,R6		;the upper limit is R1 and the input is in R0.
		BRn INVALID_R		
		BRzp FINAL_R


FINAL_R		ADD R5,R5,R1		;loads the final valid input into R5
;-----------------------------------------------------------------------------------------------------------------------------------------
;------------------------row is done------------------------------------------------------------------------------------------------------
;-----------------------------------------------------------------------------------------------------------------------------------------






;-----------------------------------------------------------------------------------------------------------------------------------------
;-------------------------------column starts here----------------------------------------------------------------------------------------
;-----------------------------------------------------------------------------------------------------------------------------------------

;PURPOSE OF REGISTERS
;R0 - does all the input and output
;R1 - is a copy of R0 and all calculation is done on R1
;R3 - has the -ve of R1, used to determine if the column number entered is right or wrong
;R4 - stores the final value of the column number
;R7 - is not touced as it switched between subroutines. its value is however stored and returned just before RET

;CLEAR REGISTERS
		

;CODE EXECUTION
LOOP_ST		AND R0,R0,#0		;clear
		AND R1,R1,#0		;clear 
		AND R3,R3,#0		;clear
		AND R4,R4,#0		;clear

		LEA R0,ASKCOLUMN	;asks the size from the user
		PUTS			;calls a system trap routine which outputs string
		GETC			;place ASCII value of input character into R1

		ADD R1,R1,R0
		OUT
		
;GETTING ACTUAL VALUE IN ASCII
		ADD R1,R1,#-15		;add 48 (x0030) to the input ASCII 
		ADD R1,R1,#-15		;
		ADD R1,R1,#-15		;R1 now contains the actual value	
		ADD R1,R1,#-3

;INVERT R1 AND STORE INTO R3
		NOT R3,R1		;
		ADD R3,R3,#1		;the -ve 2s complement is stored in R3

;CHECKING FOR VALID INPUT
		ADD R1,R1,#-1		;
		BRn INVALID		;
		BRzp UPPER_LIMIT	;	
		
INVALID		LEA R0,ERRORINPUT	;
		PUTS
		BRnzp LOOP_ST		;if the input is invalid, then ask for input again

UPPER_LIMIT	ADD R1,R1,#1		;get original value
		
		ADD R3,R3,R6		;the upper limit is R1 and the input is in R0.
		BRn INVALID		
		BRzp FINAL


FINAL		ADD R4,R4,R1		;loads the final valid input into R4

;----------------------column is done ---------------------------------------------------------------------------------------------------


;LOADING BACK THE VALUES OF THE REGISTERS

		LD R0,SAVE_0		;
		LD R1,SAVE_1		;
		LD R2,SAVE_2		;
		LD R3,SAVE_3		;
		LD R6,SAVE_6		;	
		LD R7,SAVE_7		;
RET


ASKROW .STRINGZ "\nPlease input a valid row number:\n"	; The words that should be displayed to ask row number
ASKCOLUMN .STRINGZ "\nPlease input a valid column number:\n" ; The words that should be displayed to ask column number
ERRORINPUT .STRINGZ "\nYour input is not valid."	; The words that should be displayed if the input is not valid
SAVE_0		.FILL x33FA		;
SAVE_1		.FILL x33FB		;
SAVE_2		.FILL x33FC              ;
SAVE_3		.FILL x33FD		;
SAVE_6		.FILL x33FE		;
SAVE_7		.FILL x33FF		;
.END


