#include <stdio.h>
#define STUDENTS 3
#define EXAMS 4
void minimum( int grades[][ EXAMS ],int pupils, int tests );
void maximum( int grades[][ EXAMS ],int pupils, int tests );
void average( int grades[][ EXAMS ],int pupils, int tests );
void printArray( int grades[][ EXAMS ], int pupils, int tests );
void printMenu( void );
/*a significant number of these comments don't add anyinformation*/
int main(void){
	
	/* pointer to a function that takes as parameters a
	two-dimensional array and two integer values */
	void ( *processGrades[ 4 ] )( int [][ EXAMS ], int, int ) = { printArray, minimum, maximum, average};
	int choice = 0; /* menu choice */
	/* array of student grades */
	int studentGrades[ STUDENTS ][ EXAMS ] = { { 77, 68, 86, 73 },{ 96, 87, 89, 78 },{ 70, 90, 86, 81 } };
	/* loop while user does not choose option 4 */
	while ( choice != 4 ) {
		/* display menu and read user's choice */
		do {
			printMenu();
			scanf( "%d", &choice );
		} while ( choice < 0 || choice > 4 ); /* end do...while */
		if(choice!=4){
	/* pass choice into the array */
			(*processGrades[choice])(studentGrades,STUDENTS,EXAMS);
	/* for you to complete */
		}else{
			printf("program end\n");
		}
	} /* end main */
	return 0; /* indicate successful termination */
}
/* search for the minimum value */
void minimum( int grades[][ EXAMS ], int pupils, int tests ){
	int i; /* loop counter */
	int j; /* loop counter */
	int lowGrade = 100; /* set lowGrade to highest possible score */
	/*do a basic double for loop to find minimum value*/
	for(i=0;i<pupils;i++){
		for(j=0;j<tests;j++){
			int current = grades[i][j];
			if(current < lowGrade){
				lowGrade = current;
			}
		}
	}

	printf( "\n\tThe lowest grade is %d\n", lowGrade );
} /* end function minimum */

/* search for maximum value */
void maximum( int grades[][ EXAMS ], int pupils, int tests ){
	
	int i; /* loop counter */
	int j; /* loop counter */
	int highGrade = 0; /* set highGrade to lowest possible score */
	/*do another double for loop to find maximum value*/
	for(i=0;i<pupils;i++){
		for(j=0;j<tests;j++){
			int current = grades[i][j];
			if(current > highGrade){
				highGrade = current;
			}
		}
	}
	printf( "\n\tThe highest grade is %d\n", highGrade );
} /* end function maximum */

/* calculate average grade*/
void average( int grades[][ EXAMS ], int pupils, int tests ){

	int i; /* loop counter */
	int j; /* loop counter */
	int total; /* sum of all grades */
	printf( "\n" );
	/*double for loop that sums with total variable over every value in grades*/
	for(i=0;i<pupils;i++){
		for(j=0;j<tests;j++){
			int current = grades[i][j];
			total = total + current;
		}
		double avg = ((double)total)/tests;
		printf("%.1f\n", avg);
		printf("for student %d\n", i);	
	}
	

} /* end function average */

/* print the contents of the array */
void printArray( int grades[][ EXAMS ], int pupils, int tests ){

	int i; /* loop counter */
	int j; /* loop counter */
	
	printf( "\n\t [ 0 ][ 1 ][ 2 ][ 3 ]" );
	for(i=0;i<pupils;i++){
		for(j=0;j<tests;j++){
			printf("%d ",grades[i][j]);
		}
	}
	/* for you to complete */
	printf( "\n" );
} /* end function printArray */

	/* display the menu */
void printMenu( void ){

	printf( "\n\tEnter a choice:\n"
			"\t 0 Print the array of grades\n"
			"\t 1 Find the minimum grade\n"
			"\t 2 Find the maximum grade\n"
			"\t 3 Print the average on all"
			" tests for each student\n"
			"\t 4 End program\n"
			"\t? " );
} /* end function printMenu */





