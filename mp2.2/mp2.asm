; This file should be submitted in mp2.2
; Comments
;this assmbles all the files together  
;it acts as the main function and loads all the subroutines
.ORIG x3000

		LD R1,GETSIZE
		JSRR R1

		LD R1,PRINTBOARD
		JSRR R1

REPEAT		LD R1,GETINPUT
		JSRR R1

		LD R1,UPDATEBOARD
		JSRR R1

		LD R1,PRINTBOARD
		JSRR R1

		LD R1,CHECKWIN
		JSRR R1
		ADD R0,R0,#0
		BRnp REPEAT
		LEA R0,WIN
		PUTS
		
		HALT

WIN .STRINGZ "\nCongratulations, you win!\n"	; The words you need to display if the player wins. 
GETSIZE 	.FILL x3100	; The location of the subroutine getsize which has 
			; output: R6 boardsize
PRINTBOARD 	.FILL x3200	; The location of the subroutine printboard which has 
			; input: R6 boardsize 
GETINPUT 	.FILL x3300	; The location of the subroutine getinput which has 
			;	 input: R6 boardsize output: R4 row R5 column
UPDATEBOARD .FILL x3400	; The location of the subroutine updateboard which has 
			; input: R4 row R5 column R6 boardsize
CHECKWIN 	.FILL x3500	; The location of the subroutine checkwin which has input: R6 boardsize 
			; output: R0 0 for win anyother for fail
GAMEBOARD 	.FILL x3600	; The location of the gameboard which starts at x3600
.END
