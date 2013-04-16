struct stackNode {
char data;
struct stackNode *nextPtr;
};
typedef struct stackNode StackNode;
typedef StackNode *StackNodePtr;

void convertToPostfix( char infix[], char postfix[] );
/*Convert the infix expression to postfix notation.*/
int isOperator( char c );
/*Determine if c is an operator.*/
int precedence( char operator1, char operator2 );
/*Determine if the precedence of operator1 is less than, equal to, or greater than
the precedence of operator2. The function returns -1, 0 and 1, respectively.*/
void push( StackNodePtr *topPtr, char value );
/*Push a value on the stack.*/
char pop( StackNodePtr *topPtr );
/*Pop a value off the stack.*/
char stackTop( StackNodePtr topPtr );
/*Return the top value of the stack without popping the stack.*/
int isEmpty( StackNodePtr topPtr );
/*Determine if the stack is empty.*/
void printStack( StackNodePtr topPtr );
/*Print the stack.*/
int main(void){

	return 0;
}