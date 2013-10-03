; This file should be submitted in both mp2.1 and mp2.2
; Comments
.ORIG x3300


R7VALUE .BLKW 1	; The memory reserved for R7
ASKROW .STRINGZ "\nPlease input a valid row number:\n"	; The words that should be displayed to ask row number
ASKCOLUMN .STRINGZ "\nPlease input a valid column number:\n" ; The words that should be displayed to ask column number
ERRORINPUT .STRINGZ "\nYour input is not valid."	; The words that should be displayed if the input is not valid
.END

