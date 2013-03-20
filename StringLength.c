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
		if(s[i] == 0){//scanf ignores return key! //zero is different from '0'
			printf("return sum of ");			
			return sum;
		}
		sum++;
	}
	return 0;
}


