#include <stdio.h>
#include "MinUnit.h"
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

int main(void){
	//need to read data in via scanf or args
	// may consider spilling the data up
	//send to convert to post fix
	return 0;
}

//define the functions here
/*
*	get node from head pointer store in temp variable and 
*	make new node with malloc with head as storage? then assign the new head .next
*	pointer with the temp variable and assign the char to new head value
*	
*/
void push( StackNodePtr *topPtr, char value ){

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

}
/*
* printing the stack
*	if the next node is null return 0?
*	otherwise
*	get the headNode print it's character value then printStack the next one
*/
void printStack( StackNodePtr topPtr ){

}
/*
*	return the headNodes .data value or if its not assigned return null?
*/
char stackTop( StackNodePtr topPtr ){

}
/*
* 	check if a value is an operator which are
*	/*+-^%
* Return 1 (true) if is operator
*	otherwise return 0 (false)
*/
int isOperator( char c ){

}
/*
*	check if operator one is before operator 2 in (bedmas?)
*	return 1 true
*	return 0 false
*/
int precedence( char operator1, char operator2 ){

}