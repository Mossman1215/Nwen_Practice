/*(6 marks) Using the switch statement, write a program that counts and prints the
number of each different letter grade user entered. Assume we have only five
different grades – “A” / “a”, “B” / “b”, “C” / “c”, “D” / “d”, “E” / “e”. You need
to provide a special character to end the input (user needs to enter this character to
end the input). You can only use the following variables.*/
#include <stdio.h>
#include <ctype.h>

int main (void){
char grade = 0;
/* current grade. You can also use char grade.
You may use either getchar or scanf to handle the input.
*/
int aCount = 0; /* total a grades */
int bCount = 0; /* total b grades */
int cCount = 0; /* total c grades */
int dCount = 0; /* total d grades */
int eCount = 0; /* total e grades */

//while grade is not 'the exit key'
//ask for a number
// switch statement
//loop
	printf("Enter grades until done. press x to end \n");	
		do {
			scanf("%c",&grade);
			if(isupper(grade)){
				switch(grade) {
				case 65:
					aCount++;
					break;
				case 66:
					bCount++;
					break;
				case 67:
					cCount++;
					break;
				case 68:
					dCount++;
					break;
				case 69:
					eCount++;
					break;
				default:
					break;
				}
			} else {
				switch(grade) {
				case 97:
					aCount++;
					break;
				case 98:
					bCount++;
					break;
				case 99:
					cCount++;
					break;
				case 100:
					dCount++;
					break;
				case 101:
					eCount++;
					break;
				default:
					break;
				}
			}
			printf("%d\n",grade);
		} while(grade != 120);
	printf("the answers %d %d %d %d %d \n",aCount, bCount, cCount, dCount, eCount);
	return 0;	
} 
	
//capital letters from 65to70
//lower case from 97 to 102
/*
switch from msdn
for reference
*/
/*
switch( i ) 
{
    case -1:
        n++;
        break;
    case 0 :
        z++;
        break;
    case 1 :
        p++;
        break;
}

*/

