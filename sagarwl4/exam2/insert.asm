.ORIG x3000

INSERT
INSERT_REC	; DO NOT EDIT THIS LINE. IT WILL BE EDITED DURING GRADING
; callee setup


;reserving space for return value
	ADD R6,R6,#-1		;

;reserving space for return address
	ADD R6,R6,#-1		;
	STR R7,R6,#0		;	

;reserving space for frame pointer
	ADD R6,R6,#-1		;
	STR R5,R6,#0		;	

; Check for base case

; Base case implementation. If you set up R5 correctly and implement
; RET_R0 correctly, this code works. However, you have NO OBLIGATION
; to use this code.
LDR R0, R5, #4	; R0 <- current_node
LDR R1, R5, #5	; R1 <- reserved_node
STR R1, R0, #1	; current_node->next = reserved_node
LDR R0, R5, #6	; R0 <- number
STR R0, R1, #0	; reserved_node->value = number
LDR R0, R5, #0	; R0 <- next_node
STR R0, R1, #1	; reserved_node->next = next_node
ADD R0, R0, #0	; R0 <- 0
ADD R0, R0, #1	; R0 <- 1
BRnzp RET_R0	; return R0: YOU MUST IMPLEMENT

; caller setup

LDR R2,R5,#0	;
LDR  R0, R2	; R0 <- next_node

LDR R3,R5,#0	;
LDR  R1, R3,#0	; R1 <- reserved_node
STR R1, R0, #1	; current_node->next = reserved_node
LDR R0, R5, #6	; R0 <- number
STR R0, R1, #0	; reserved_node->value = number
LDR R0, R5, #0	; R0 <- next_node
STR R0, R1, #1	; reserved_node->next = next_node
ADD R0, R0, #0	; R0 <- 0
ADD R0, R0, #1	; R0 <- 1
ADD R0, R0, #1	;
BRnzp RET_R0	; return R0: YOU MUST IMPLEMENT


JSR INSERT_REC	; make recursive call

; caller teardown

RET_RO
;return

STR R5,R6,#0		;
ADD R6,R6,#1		;
STR R7,R6,#0		;	
ADD R6,R6,#1		;

; callee teardown

RET

.END
