; This file should be submitted in mp2.2
; Comments
;PURPOSE OF REGISTERS
;R0 - 
;R1 - 
;R2 - 
;R3 - contains (R6)^2
;R4 - is the counter
;R5 - 
;R6 - 

.ORIG x3500
;SAVE ALL THE REGISTERS
		ST R1,SAVE_1
		ST R2,SAVE_2
		ST R3,SAVE_3
		ST R4,SAVE_4
		ST R5,SAVE_5
		ST R7,SAVE_7

;CLEAR ALL REGISTERS
		AND R1,R1,#0		;clear
		AND R2,R2,#0		;clear
		AND R3,R3,#0		;clear
		AND R4,R4,#0		;clear
		AND R5,R5,#0		;clear
		AND R7,R7,#0		;clear	 
;----------------making a counter-------------------------------------------------------------
		ADD R5,R6,#0		;R5 now has the size
		
LOOP2		ADD R3,R6,#0		;R3 now has the square of R6(size^2)
		ADD R5,R5,#-1		;		
		BRp LOOP2		;R5 is a loop counter		
					;
;---------------------------------------------------------------------------------------------
		AND R5,R5,#0		;clear - now we have R1,R2,R4,R5,R7 FREE
		
		
		LD R1,GAMEBOARD		;the first memory location is stored in R1
		LD R2,val_one		;
		NOT R2,R2		;
		ADD R2,R2,#1		;R2 contains -1
		
		
LOOP1		ADD R3,R1,R2		;we see if the result is -ve or 0
		BRn NEXT		;if it is negative, decrement the counter		
		BRzp STOP		;if it is 1, we go to halt straight
		

NEXT		ADD R1,R1,#1		;checks the next value
		ADD R3,R3,#-1		;acts as the check of the last value	
		BRp LOOP1		;checks the next value		
	;if all are checked, we load R6 with 0 and halt

;--------------------------------------------------------------------------------------------
		AND R6,R6,#0		;load R6 with 0 when all the values are 0	
;-----------loading back all the values------------------------------------------------------
		LD R1,SAVE_1
		LD R2,SAVE_2
		LD R3,SAVE_3
		LD R4,SAVE_4
		LD R5,SAVE_5
		LD R7,SAVE_7
;---------------------------------------------------------------------------------------------
STOP		RET
GAMEBOARD	.FILL x3600
val_one		.FILL x0031
SAVE_1		.BLKW 1
SAVE_2		.BLKW 1
SAVE_3		.BLKW 1
SAVE_4		.BLKW 1
SAVE_5		.BLKW 1
SAVE_7		.BLKW 1
.END
