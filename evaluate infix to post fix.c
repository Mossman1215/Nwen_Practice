#include <stdio.h>

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
int evaluatePostfixExpression(char*);
int evaluateBracketed(int*,char*);
int readNumber(char);
char match(char);
void skipWhiteSpace(int*, char*);

int main(void){

	return 0;
}
