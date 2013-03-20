#include <stdio.h>

int stringlen( const char *s ); /* prototype */

int main( void ){ 
	char string[ 80 ]; /* create char array */
	printf( "Enter a string: ");
	scanf( "%[^\n]", string );
	printf( "%d\n", stringlen( string ) );
	return 0;
}

int stringlen( const char *s ){
	int i;
	int sum = 0;
	for(i=0;i<80;i++){
		sum++;
		if(s[i] =='\n'){
			printf("return sum");			
			return sum;
		}
	}
	return 0;
}


