
#include<stdio.h>
#include<limits.h>

int main (){	
	int number = 5; /* number of integers to be entered */
	int value; /* value input by user */
	int smallest = int_MAX; /* smallest number */
	int i; /* counter */

	//ASK for numbers 
	//if number is smaller than intmax then assign to smallest
	//check if next series of numbers are smaller than smallest
	//i++
	while(i<number){
		scanf("Enter one number",value);
		if(value < smallest){
			smallest = value;		
		}
	}
	printf("%d",smallest);
//printf result
}
