#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct stackNode {
	char data;
	struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void convertToPostfix( char infix[], char postfix[] );
int isOperator( char c );
/* precedence function returns -1, 0 and 1, respectively.*/
int precedence( char operator1, char operator2 );
void push( StackNodePtr *topPtr, char value );
char pop( StackNodePtr *topPtr );
char stackTop( StackNodePtr topPtr );
int isEmpty( StackNodePtr topPtr );
void printStack( StackNodePtr topPtr );
/* custom functions*/
void skipWhiteSpace(int*, char*);
void recursiveSolve(StackNodePtr *,char*,char*,int*);
/**
* has max value 256 chars cause i can't work out another way
*/
int main(void){
	
	char input[256];
	char output[256];
	scanf("%s",input);
	printf("input :%s\n", input);
	// may consider spilling the data up
	convertToPostfix(input,output);
	printf("input Postfix :%s\n", input);
	printf("output: %s\n", output);
	
	return 0;
}
/*
 function that converts to postfix and calls printstack
 */
void convertToPostfix(char infix[],char postfix[]){
	int index = 0;
	int* indexPtr = &index;
	StackNodePtr tmp = malloc(sizeof(StackNode));
	StackNodePtr head = NULL;
	if(tmp == NULL){
		printf("memory allocation failure\n");
		exit(0);
	}else{
		head = tmp;	
	}
	StackNodePtr *headPtr = &head;
//	Push a left parenthesis '(' onto the stack.
	head->data = '(';
	head->nextPtr = NULL;
// 	Append a right parenthesis ')' to the end of infix
	strcat(infix,")");
	//recursiveSolve(headPtr,infix,postfix,indexPtr);
}
/**
*	functioun to solve the convert to postfix thing
***********************************
*	if stack is empty
*		return;
*	char data = infix[0]
*	do algorithm
*	create new list excluding data
*	recursiveSolve()
***********************************
*	algorithm
*	if infix is digit copy to postfix
*	if infix is (
		push on stack
	if isoperator
		while there is operator on stack
			if the top stack operator is higher than current operators
				popstack and put in postfix
				push current onto stack
		OTHERWISE
			push currentoperator onto stack
	if infix is )
		while '(' is not top of stack
		pop operators from stack and place in postfix
		then
		discard '('
		//print?
*/
void recursiveSolve(StackNodePtr *topPtr,char*infix,char*postfix,int *indexPtr){
	if(*topPtr==NULL){
		return;
	}
	char data = infix[0];
	char stackTopChar = stackTop(*topPtr);
	if(isdigit(data)){
		postfix[*indexPtr] = data;
		(*indexPtr)++;
	}
	if(isOperator(data)){
		if(isOperator(stackTopChar)){
			if(precedence(data,stackTopChar)){
				//pop stacktop
				stackTopChar = pop(topPtr);
				//push data
				push(topPtr,data);
				//push stacktop
				push(topPtr,stackTopChar);
			}
		}else{
				push(topPtr,data);
		}
	}
	if(infix[0]== ')'){
		while(stackTopChar != '('){
			postfix[*indexPtr] = pop(topPtr);
			(*indexPtr)++;
		}
		pop(topPtr);
	}
	recursiveSolve(topPtr,infix+1,postfix,indexPtr);
}
/*
*	get node from head pointer store in temp variable and 
*	make new node with malloc with head as storage? then assign the new head .next
*	pointer with the temp variable and assign the char to new head value
*	
*/
void push( StackNodePtr *topPtr, char value ){
	StackNodePtr temp = *topPtr;
	//check for malloc falure
	StackNodePtr newPtr = malloc(sizeof(StackNode));
	if(newPtr == NULL){
		printf("Memory allocation falure\n");
		exit(0);
	}else{
		StackNode newNode = {value,temp};
		newPtr = &newNode;
		*topPtr = newPtr;
	}
}
/*
*	return null if stack is empty
*	take the head value
*	store its character in a temporary char variable
*	then assign headNode to temp variable
*	get head .next node and store it in head
*	then free tmp
*	return the temporary char variable
*/
char pop( StackNodePtr *topPtr ){
	if(isEmpty(*topPtr) == 1){
		printf("stack is empty\n");
	}else{
		StackNodePtr temp = *topPtr;
		char c = temp->data;
		*topPtr = (*topPtr)->nextPtr;
		free(temp);
		return c;
	}
	return ' ';
}
/*
* printing the stack
*	if the next node is null return 0?
*	otherwise
*	get the headNode print it's character value then printStack the next one
*/
void printStack( StackNodePtr topPtr ){
	printf("Not implemented\n");
}
/**
*	check if node is empty
*/
int isEmpty(StackNodePtr topPtr){
	if(topPtr==NULL){
		return 1;
	}else{
		return 0;
	}
}
/*
*	return the headNodes .data value or if its not assigned return null?
*/
char stackTop( StackNodePtr topPtr ){
	if(isEmpty(topPtr) == 1){
		printf("stack is empty\n");
		return ' ';
	}else{
		return topPtr->data;
	}
}
/*
* 	check if a value is an operator which are
*	/ * + - ^ % 
* Return 1 (true) if is operator
*	otherwise return 0 (false)
*/
int isOperator(char c){
// do a case statement returning an int based on if its a operator otherwise it returns zero (default)
	switch (c){
        case '+':
        return 1; 
        case '-':
        return 1;
        case '*':
        return 1;
        case '/':
        return 1;
        case'^':
        return 1;
        case '%':
        return 1;
        default:
        return 0;    
    }
}

/*
*	check if operator one is before operator 2 in (bedmas?)
*	return 1 true
*	return 0 false
* ^ > (/or*) > (+or-)
*/
int precedence( char operator1, char operator2 ){
	char operatorList[] = {'+','-','*','/','%','^'};
	int opVal1=0,opVal2=0;
	if(operator1 == operator2){
		return 0;
	}
	int i;
	for(i=0;i<7;i++){
		if(operator1 == operatorList[i]){
			opVal1 = i;
		}
		if(operator2 == operatorList[i]){
			opVal2 = i;
		}
	}
	//compare opvals
	//if op1 is <= op2-1 (op2 is greater) (i.e. return 1)
	if(opVal1<= (opVal2-1)){
		return 1;
	}
	return 0;
}

void skipWhiteSpace(int* index,char* input){
	int i = *index;
	while(input[i] == ' '){
		i++;
		printf("white space skip: %d\n",i);
	}
}