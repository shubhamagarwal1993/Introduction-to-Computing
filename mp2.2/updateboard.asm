; This file should be submitted in mp2.2
; Comments

;PURPOSE OF REGISTERS
;R1 - load it with gameboard+(row-1)*size+(column-1)
;R2 - 
;R3 - 
;R4 - contains the column number
;R5 - contains the row number
;R6 - contains the board size

.ORIG x3400
;-------------SAVE REGISTERS-------------------------------------------------------
		ST R2,SAVE_2		;
		ST R3,SAVE_3		;
		ST R7,SAVE_7		;


;------------CLEARING REGISTERS----------------------------------------------------
		AND R1,R1,#0		;clear
		AND R2,R2,#0		;clear
		AND R3,R3,#0		;clear

;-------------LOADING REGISTERS-----------------------------------------------------
		LD R1,INITIAL		;load R1 with GAMEBOARD
		ADD R3,R5,#-1		;R0W-1

		ADD R2,R6,#0		;loop to get (row-1)*size
DO_ROW		ADD R3,R3,#0		;		
		ADD R2,R2,#-1		;
		BRp DO_ROW		;loop ends
		ADD R1,R3,#0
		
		AND R2,R2,#0		;	
		ADD R2,R4,#-1		;gets column-1
		
		ADD R1,R2,#0		;R1 now has (row-1)*size+(column-1)+GAMEBOARD

		ADD R1,R1,#-15
		ADD R1,R1,#-15
		ADD R1,R1,#-15
		ADD R1,R1,#-3
		
		ST R1,GAME_SAVE

		AND R2,R2,#0		;clear registers
		AND R3,R3,#0		;clear registers
		
;------------FLIP THE MAIN NUMBER----------------------------------------------------
		AND R2,R2,#0
		AND R3,R3,#0
		
		LD R2,val_one		; 
		NOT R2,R2		;
		ADD R2,R2,#1		;
		ADD R3,R1,R2		;	
		BRz CHANGE_0_M		;
		BRn CHANGE_1_M		;

CHANGE_0_M	LD R1,val_one		;
CHANGE_1_M	LD R1,val_zero		;
;------------------------------------------------------------------------------------

;---------changing (col-1) and (col+1)-----------------------------------------------
		AND R1,R1,#0		
		AND R2,R2,#0
		AND R3,R3,#0
		AND R7,R7,#0

		LD R1,GAME_SAVE		;load the formula into R1 again
		ADD R1,R1,#1		;increment column by 1
		LD R2,val_one		;we check for 
		NOT R2,R2		;**
		ADD R2,R2,#1		;**
		ADD R3,R1,R2		;**	
		BRz CHANGE_0_C		;**
		BRn CHANGE_1_C		;col+1 and flip it

CHANGE_0_C	LD R1,val_zero
CHANGE_1_C	LD R1,val_one
		
		ST R1,GAME_SAVE_C+1


		AND R1,R1,#0		;we start decrementing column from here
		AND R2,R2,#0
		AND R3,R3,#0

		LD R1,GAME_SAVE		;load the formula into R1 again
		ADD R1,R1,#-1		;decrement column by 1
		LD R2,val_one		;we check for 
		NOT R2,R2		;**
		ADD R2,R2,#1		;**
		ADD R3,R1,R2		;**	
		BRz CHANGE_0_C_d	;**
		BRn CHANGE_1_C_d	;col+1 and flip it

CHANGE_0_C_d	LD R1,val_zero
CHANGE_1_C_d	LD R1,val_one
		
		ST R1,GAME_SAVE_C-1

		
;------------------------------------------------------------------------------------
;---------changing (row-1)-----------------------------------------------------------
;here we will have to change the formula we initially loaded into R1
		AND R1,R1,#0
		AND R2,R2,#0
		AND R3,R3,#0


		LD R1,INITIAL		;load R1 with GAMEBOARD
		ADD R3,R5,#-2		;R0W-2

		ADD R2,R6,#0		;loop to get (row-2)*size

DO_ROW_K	ADD R3,R3,#0		;		
		ADD R2,R2,#-1		;
		BRp DO_ROW_K		;loop ends
		
		ADD R1,R3,#0
		
		AND R2,R2,#0		;	
		ADD R2,R4,#-1		;gets column-1
		
		ADD R1,R2,#0		;R1 now has (row-2)*size+(column-1)+GAMEBOARD

		ADD R1,R1,#-15
		ADD R1,R1,#-15
		ADD R1,R1,#-15
		ADD R1,R1,#-3		;now R1 has the decimal value in it.
		
		AND R2,R2,#0		;clear registers
		AND R3,R3,#0		;clear registers

		LD R2,val_one		; 
		NOT R2,R2		;
		ADD R2,R2,#1		;
		ADD R3,R1,R2		;	
		BRz CHANGE_0_S		;
		BRn CHANGE_1_S		;

CHANGE_0_S	LD R1,val_one		;
CHANGE_1_S	LD R1,val_zero		;

		ST R1,GAME_SAVE_R+1	;
;-------------------------------------------------------------------------------------------------

;---------changing (row+1)-----------------------------------------------------------
;here we will have to change the formula we initially loaded into R1
		AND R1,R1,#0
		AND R2,R2,#0
		AND R3,R3,#0


		LD R1,INITIAL		;load R1 with GAMEBOARD
		ADD R3,R5,#0		;R0W

		ADD R2,R6,#0		;loop to get (row)*size

DO_ROW_I	ADD R3,R3,#0		;		
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

		LD R2,val_one		; 
		NOT R2,R2		;
		ADD R2,R2,#1		;
		ADD R3,R1,R2		;	
		BRz CHANGE_0_S		;
		BRn CHANGE_1_S		;

CHANGE_0_S	LD R1,val_one		;
CHANGE_1_S	LD R1,val_zero		;

		ST R1,GAME_SAVE_R-1	;

;-------------------------------------------------------------------------------------------------
RET
;-----------------------------------------------------------------------------------

val_zero		.FILL x0030
val_one		.FILL x0031
INITIAL		.FILL x3600
SAVE_2		.BLKW 1
SAVE_3		.BLKW 1
SAVE_7		.BLKW 1
COL_IN		.FILL x
COL_DE		.FILL x
ROW_IN		.FILL x
ROW_DE		.FILL x	
FLIP_MAIN	
GAME_SAVE
GAME_SAVE_C+1
GAME_SAVE_C-1
GAME_SAVE_R+1
GAME_SAVE_R-1
.END

