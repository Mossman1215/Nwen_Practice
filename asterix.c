/*
print this
*
**
***
****
*/
#include <stdio.h>

int main(void){
int row; /* row counter */
int col; /* column counter */

	for(row = 0; row<4;row++){
			for(col = 0; col<row;col++){
					printf("*");					
		}		
		printf("*\n");	
	}
		
	return 0;
}

