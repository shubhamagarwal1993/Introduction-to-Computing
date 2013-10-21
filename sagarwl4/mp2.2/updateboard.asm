; This file should be submitted in mp2.2
; Comments

;PURPOSE OF REGISTERS
;R1 - load it with gameboard+(row-1)*size+(column-1)
;R2 - act as a counter
;R3 - act as a counter
;R4 - contains the column number
;R5 - contains the row number
;R6 - contains the board size

.ORIG x3400
;-------------SAVE REGISTERS-----------------------------------------------
				ST R1,SAVE_1		;
				ST R2,SAVE_2		;
				ST R3,SAVE_3		;
				ST R7,SAVE_7		;

;------------CLEARING REGISTERS--------------------------------------------
				AND R1,R1,#0		;clear
				AND R2,R2,#0		;clear
				AND R3,R3,#0		;clear
				AND R7,R7,#0
;-------------LOADING REGISTERS---------------------------------------------
				LD R1,INITIAL		;load R1 with GAMEBOARD
				ADD R3,R5,#-1		;R0W-1
				ADD R7,R7,R3		;
	
				ADD R2,R6,#-1		;loop to get (row-1)*size
DO_ROW			ADD R3,R3,R7		;		
				ADD R2,R2,#-1		;
				BRp DO_ROW			;loop ends
				ADD R1,R1,R3
			
				AND R2,R2,#0		;	
				ADD R2,R4,#-1		;gets column-1
		
				ADD R1,R1,R2		;R1 now has (row-1)*size+(column-1)+GAMEBOARD
;--------------------------------------------------------------------------
		
				ST R1,GAME_SAVE		;GAMESAVE HAS THE MEMORY LOCATION OF THE ORIGINAL VALUE
				LDI R1, GAME_SAVE	;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;we add -48 to R1 to get 0 or 1		
						
				AND R2,R2,#0		;clear registers
				AND R3,R3,#0		;clear registers
		
;------------FLIP THE MAIN NUMBER------------------------------------------
			
				ADD R3,R1,#-1		;	
				BRzp CHANGE_0_M		;
				BRn CHANGE_1_M		;

CHANGE_0_M		LD R1,val_zero		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;
				STI R1,GAME_SAVE	;		
				BRnzp DONE 			;

CHANGE_1_M		LD R1,val_one		;
				ADD R1,R1,#-1		;
				STI R1,GAME_SAVE	;			
				BRnzp DONE			;
;		
;---------changing (col+1)-----------------------------------------------
;

DONE			AND R1,R1,#0		;		
				AND R2,R2,#0		;
				AND R3,R3,#0		;
			
				LD R1,GAME_SAVE		;load the formula into R1 again
				ADD R1,R1,#1		;increment column by 1
				ST R1,GAME_SAVE_1	;GAMESAVE HAS THE MEMORY LOCATION OF THE ORIGINAL VALUE
				LDI R1, GAME_SAVE_1	;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;we add -48 to R1 to get 0 or 1					
				ADD R2,R2,#-1		;we load R2 with -1 to check for 0 or 1 
				ADD R3,R1,R2		;check if R1 is 0 or 1	
			
				BRzp CHANGE_0_M_Q	;
				BRn CHANGE_1_M_Q	;

CHANGE_0_M_Q	LD R1,val_zero		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;
				STI R1,GAME_SAVE_1	;		
				BRnzp DONE_Q		;

CHANGE_1_M_Q	LD R1,val_one		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;
				STI R1,GAME_SAVE_1	;				
				BRnzp DONE_Q		;
		
;---------changing (col-1)-----------------------------------------------
DONE_Q			AND R1,R1,#0		;we start decrementing column from here
				AND R2,R2,#0
				AND R3,R3,#0

				LD R1,GAME_SAVE		;load the formula into R1 again
				ADD R1,R1,#-1		;decrement column by 1
				ST R1,GAME_SAVE_2	;GAMESAVE HAS THE MEMORY LOCATION OF THE ORIGINAL VALUE
				LDI R1, GAME_SAVE_2
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;we add -48 to R1 to get 0 or 1		
				ADD R2,R2,#-1		;we check for 
				ADD R3,R1,R2		;check if R1 is 0 or 1	
		
				BRzp CHANGE_0_M_R	;
				BRn CHANGE_1_M_R	;

CHANGE_0_M_R	LD R1,val_zero		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;	
				STI R1,GAME_SAVE_2	;	
				BRnzp DONE_R		;
	
CHANGE_1_M_R	LD R1,val_one		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;
				STI R1,GAME_SAVE_2	;		
				BRnzp DONE_R		;
		
;---------changing (row-1)-----------------------------------------------------------

;here we will have to change the formula we initially loaded into R1

DONE_R			AND R1,R1,#0
				AND R2,R2,#0
				AND R3,R3,#0

				LD R1,INITIAL		;load R1 with GAMEBOARD
				ADD R3,R5,#-2		;R0W-2
				ST R1,GAME_SAVE_3	;GAMESAVE HAS THE MEMORY LOCATION OF THE ORIGINAL VALUE
				LDI R1, GAME_SAVE_3
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;we add -48 to R1 to get 0 or 1		
				ADD R2,R6,#0		;loop to get (row-2)*size

DO_ROW_K		ADD R3,R3,#0		;		
				ADD R2,R2,#-1		;
				BRp DO_ROW_K		;loop ends
				ADD R1,R3,#0
		
				AND R2,R2,#0		;	
				ADD R2,R4,#-1		;gets column-1
		
				ADD R1,R2,#0		;R1 now has (row-2)*size+(column-1)+GAMEBOARD

				AND R2,R2,#0		;clear registers
				AND R3,R3,#0		;clear registers

				ADD R2,R2,#-1		; 
				ADD R3,R1,R2		;	
		
				BRzp CHANGE_0_M_J	;
				BRn CHANGE_1_M_K	;

CHANGE_0_M_J	LD R1,val_zero		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;		
				STI R1,GAME_SAVE_3	;
				BRnzp DONE_J		;

CHANGE_1_M_K	LD R1,val_one		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;		
				STI R1,GAME_SAVE_3	;
				BRnzp DONE_J		;
		
;---------changing (row+1)-----------------------------------------------------------
;here we will have to change the formula we initially loaded into R1

DONE_J			AND R1,R1,#0
				AND R2,R2,#0
				AND R3,R3,#0

				LD R1,INITIAL		;load R1 with GAMEBOARD
				ADD R3,R5,#0		;R0W
				ST R1,GAME_SAVE_4	;GAMESAVE HAS THE MEMORY LOCATION OF THE ORIGINAL VALUE
				LDI R1, GAME_SAVE_4
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;we add -48 to R1 to get 0 or 1		
				ADD R2,R6,#0		;loop to get (row)*size

DO_ROW_I		ADD R3,R3,#0		;		
				ADD R2,R2,#-1		;
				BRp DO_ROW_I		;loop ends
			
				ADD R1,R3,#0
			
				AND R2,R2,#0		;	
				ADD R2,R4,#-1		;gets column-1
		
				ADD R1,R2,#0		;R1 now has (row)*size+(column-1)+GAMEBOARD

				ADD R1,R1,#-15
				ADD R1,R1,#-15
				ADD R1,R1,#-15
				ADD R1,R1,#-3		;now R1 has the decimal value in it.
		
				AND R2,R2,#0		;clear registers
				AND R3,R3,#0		;clear registers

				ADD R2,R2,#-1		; 
				ADD R3,R1,R2		;	
				BRzp CHANGE_0_M_Z	;
				BRn CHANGE_1_M_Z	;

CHANGE_0_M_Z	LD R1,val_zero		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;		
				STI R1,GAME_SAVE_4	;
				BRnzp DONE_Z		;

CHANGE_1_M_Z	LD R1,val_one	;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-15		;
				ADD R1,R1,#-3		;		
				STI R1,GAME_SAVE_4	;
				BRnzp DONE_Z		;
		
DONE_Z			RET
;-------------------------------------------------------------------------------------------------

val_zero	.FILL x0030
val_one		.FILL x0031
INITIAL		.FILL x3600
SAVE_1		.BLKW 1
SAVE_2		.BLKW 1
SAVE_3		.BLKW 1
SAVE_7		.BLKW 1
GAME_SAVE	.BLKW 1
GAME_SAVE_1	.BLKW 1
GAME_SAVE_2	.BLKW 1
GAME_SAVE_3	.BLKW 1
GAME_SAVE_4	.BLKW 1
ZIP_1		.BLKW 1
ZIP_2		.BLKW 1
ZIP_3		.BLKW 1
ZIP_4		.BLKW 1
ZIP_5		.BLKW 1
ZIP_6		.BLKW 1
ZIP_7		.BLKW 1
ZIP_8		.BLKW 1
ZIP_9		.BLKW 1
ZIP_10		.BLKW 1
FINAL		.BLKW 1
.END

