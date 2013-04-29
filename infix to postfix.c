#include <stdio.h>
#include "MinUnit.h"
#include <malloc.h>
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
int recursiveSolve(StackNodePtr *,char*,char*)

int main(void){
	
	char input[256];
	char output[256];
	scanf("%s",input);
	printf("input :%s\n", input);
	// may consider spilling the data up
	convertToPostfix(input,output);
	printf("output: %s\n", input);
	return 0;
}


/* function that converts to postfix and calls printstack*/
void convertToPostfix(char infix[],char postfix[]){
	int index = 0;
	int* indexPtr = &index;
	StackNodePtr head = malloc(sizeof(StackNode));
	StackNodePtr *headPtr = &head;
	skipWhiteSpace(indexPtr,infix);
	StackNode n = {infix[index],NULL};
	head = &n;
	while(infix[index]!= '\0'){
		skipWhiteSpace(indexPtr,infix);	
		push(headPtr,infix[index]);
		index++;
	}
}
/**
*	functioun to solve the convert to postfix thing
*/
int recursiveSolve(StackNodePtr *,char*,char*){

}
/*
*	get node from head pointer store in temp variable and 
*	make new node with malloc with head as storage? then assign the new head .next
*	pointer with the temp variable and assign the char to new head value
*	
*/
void push( StackNodePtr *topPtr, char value ){
	StackNodePtr temp = *topPtr;
	StackNodePtr newPtr = malloc(sizeof(StackNode));
	StackNode newNode = {value,temp};
	newPtr = &newNode;
	*topPtr = newPtr;
}

/*
*	take the head value
*	get it's .next node and store it in a temp variable
*	store its character in a temporary char variable
*	then free headNode
*	then assign headNode to temp variable
*	return the temporary char variable
*/
char pop( StackNodePtr *topPtr ){
	return 'c';
}
/*
* printing the stack
*	if the next node is null return 0?
*	otherwise
*	get the headNode print it's character value then printStack the next one
*/
void printStack( StackNodePtr topPtr ){

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
	if(isEmpty == 1){
		printf("stack is empty\n");
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
*/
int precedence( char operator1, char operator2 ){
	return 0;
}

void skipWhiteSpace(int* index,char* input){
	int i = *index;
	while(input[i] == ' '){
		i++;
		printf("white space skip: %d\n",i);
	}
}