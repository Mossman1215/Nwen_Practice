
#include<stdio.h>
#include<limits.h>

int main (){	
	int number = 5; /* number of integers to be entered */
	int value; /* value input by user */
	int smallest = INT_MAX; /* smallest number */
	int i=0; /* counter */

	//ASK for numbers 
	//if number is smaller than intmax then assign to smallest
	//check if next series of numbers are smaller than smallest
	//i++
	while(i<number){
		printf("Enter one number");
		scanf("%d",&value);
		if(value < smallest){
			smallest = value;		
		}
		i++;
	}
	printf("%d",smallest);
//printf result
	return 0;
}
