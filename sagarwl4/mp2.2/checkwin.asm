; This file should be submitted in mp2.2
; Comments
;this checks if all the numbers are 0 or not
;if all are 0, then it prints win condition 
;if not, then it goes back to ask user input again
;PURPOSE OF REGISTERS
;R0 - checks if all the pieces are 0 or not (output)
;R1 - spare
;R2 - spare
;R3 - contains (R6)^2
;R4 - is the counter
;R5 - is a counter for decrementing (size)^2 
;R6 - contains game board size(not to be touched)

.ORIG x3500
;------------------SAVE ALL THE REGISTERS--------------------------
			ST R1,SAVE_1
			ST R2,SAVE_2
			ST R3,SAVE_3
			ST R4,SAVE_4
			ST R5,SAVE_5
			ST R7,SAVE_7

;-----------------CLEAR ALL REGISTERS------------------------------
			AND R0,R0,#0		;clear	
			AND R1,R1,#0		;clear
			AND R2,R2,#0		;clear
			AND R3,R3,#0		;clear
			AND R4,R4,#0		;clear
			AND R5,R5,#0		;clear
				 
;----------------making a counter-------------------------------------------------------------
			ADD R5,R6,#0		;R5 now has the size
		
LOOP2			ADD R3,R3,R6		;R3 now has the square of R6(size^2)
                        ADD R5,R5,#-1		;		
			BRp LOOP2		;R5 is a loop counter		
			ADD R3,R3,#-1		;we not have (size^2)-1 because we check x3600 outside the loop		
;---------------------------------------------------------------------------------------------
			AND R5,R5,#0		;clear - now we have R1,R2,R4,R5 FREE
		
			LD R1,GAMEBOARD		;the first memory location is stored in R1
			ADD R2,R2,#-1		;load R2 with -1
			
		
			LDI R4,GAMEBOARD	;load the value stored in x3600
			ADD R4,R4,#-16	        ;
			ADD R4,R4,#-16		;
			ADD R4,R4,#-16		;
			ADD R5,R4,R2		;we see if the result is -ve or 0
			BRzp STOP		;if it is 1, we go to halt straight

LOOP1			ADD R1,R1,#1		;R1 points to the next value
			ST R1,STORE		;store the memory location of new R1			
			AND R4,R4,#0		;clear R4
			LDI R4,STORE		;load value in memory of R1
			ADD R4,R4,#-16	        ;
			ADD R4,R4,#-16		;
			ADD R4,R4,#-16		;	
			BRp STOP		;we check the value in R4	
			
			ADD R3,R3,#-1		;decrement counter			
			BRp LOOP1		;exit loop when counter goes to zero
;if all are checked, we load R0 with 0 and halt

;--------------------------------------------------------------------------------------------
			AND R0,R0,#0		;load R0 with 0 when all the values are 0	
			BRnzp STOP1		;we load R0 with 0 and go to RET			
;-----------loading back all the values------------------------------------------------------
STOP			ADD R0,R0,#1			;
STOP1			LD R1,SAVE_1		;
			LD R2,SAVE_2		;
			LD R3,SAVE_3		;
			LD R4,SAVE_4		;
			LD R5,SAVE_5		;
			LD R7,SAVE_7		;
;---------------------------------------------------------------------------------------------
				
		RET
;------------------------------------------------------------------------------------
GAMEBOARD	.FILL x3600
val_one		.FILL x0031
SAVE_1		.BLKW 1
SAVE_2		.BLKW 1
SAVE_3		.BLKW 1
SAVE_4		.BLKW 1
SAVE_5		.BLKW 1
SAVE_7		.BLKW 1
STORE		.BLKW 1
.END
