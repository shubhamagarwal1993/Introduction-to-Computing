;The LC3 code for 'C' multiplication

;z = x * y


;R5   - memory address where 'x' is located
;R5-1 - memory address where 'y' is located
;R5-2 - memory address where 'z' is located

;--------LC3 CODE BEGINS HERE---------------

		AND R0,R0.#0		;
		
		LDR R1,R5,#0		;load the value of 'x'
		LDR R2,R5,#-1		;load the value of 'y'
		BRz DONE			;if y is zero, then we are done
		BRp LOOP			;continue adding till we get the answer
		
							;if 'y' is negative, then 
							;we change '-y' to 'y' and 'x' to '-x'			 

		NOT R2,R2
		ADD R2,R2,#1
		
		NOT R1,R1
		ADD R1,R1,#1
				
LOOP	ADD R0,R0,R1		;we add 'x' to itself 'y' times
		ADD R2,R2,#-1
		BRp LOOP		
		
		
DONE	STR R0,R5,#-2		;store the product in 'z'		
