#include <stdio.h>

int stringcmp( const char *s1, const char *s2 ); /* prototype */
int stringlen( const char *s );

int main( void ){
	
	char string1[ 80 ]; /* create a string */
	char string2[ 80 ]; /* create another string */
	printf( "Enter two strings: " );
	scanf( "%s%s", string1 , string2 );
	printf( "The result is %d\n", stringcmp( string1, string2 ) );
	return 0;
}

int stringcmp(const char *s1, const char *s2 ){
	int i,j,length1,length2;
	//find length of string1
	//check if strings are equally long	otherwise why compare them
	if(length1 != length2){
		return 0;
	}
	for(i=0;i<length1;i++){
				
	}
	return 0;//if the arrays are different return 0
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


