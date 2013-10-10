; This file should be submitted in both mp2.1 and mp2.2
; Comments
.ORIG x3200

;SAVE ALL THE REGISTERS since we dont want the value of registers to be lost when this subroutine works 
		ST R0,SAVE_0		;
		ST R1,SAVE_1		;
		ST R2,SAVE_2		;
		ST R3,SAVE_3		;
		ST R6,SAVE_6		;
		ST R7,SAVE_7		;

;PURPOSE OF REGISTERS
;R0 - will be used for all the input and output
;R1 - has the starting location of the gameboard
;R2 - will be used as a counter for the row
;R3 - will be used as a counter for the column
;R6 - contains the size of the game board 
 


;CLEAR REGISTERS
		AND R0,R0,#0		;clear
		AND R1,R1,#0		;clear 
		AND R2,R2,#0		;clear 
		AND R3,R3,#0		;clear 
		AND R6,R6,#0		;clear
		
		ADD R6,R6,#3

;add a blank line
	;	LEA R0,BLANK_L
	;	OUT
		
	
;CODE EXECUTOIN 
		LD R1,GAMEBOARD
		ADD R3,R3,R6		;put the input number in R2
		
		

LINE_AGAIN	ADD R2,R2,R6		;put the input number in R3
LOOP1		ADD R1,R1,#1
		LDR R0,R1,#0
		OUT
		
		ADD R2,R2,#-1
		BRnz BREAK_LINE
		BRp LOOP1

BREAK_LINE	LEA R0,NEXT_LINE
		OUT
		ADD R3,R3,#-1
		BRnz STOP
		BRp LINE_AGAIN


;add a blank line
STOP		LEA R0,BLANK_L
		OUT

;LOAD ALL THE REGISTERS TO THEIR INITIAL VALUE SO THAT NO VALUE HAS CHANGED AFTER THIS SUBROUTINE
		LD R0,SAVE_0		;load
		LD R1,SAVE_1		;load
		LD R2,SAVE_2		;load
		LD R3,SAVE_3 		;load
		LD R6,SAVE_6		;load
		LD R7,SAVE_7		;load

		RET

SAVE_0		.FILL x3150
SAVE_1		.FILL x3151
SAVE_2		.FILL x3152
SAVE_3		.FILL x3153
SAVE_6		.FILL x3154
SAVE_7		.FILL x3155

BLANK_L		.FILL x000A
NEXT_LINE	.FILL x000A
GAMEBOARD	.FILL x35FF

.END
