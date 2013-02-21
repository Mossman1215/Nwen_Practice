#include <stdio.h>
#define SIZE 10
void v_exchange(int a[]);

int main(void){
	 int i, x[SIZE];
	/* x[] has 10 int elements */
	for (i=0; i<SIZE; i++){
		x[i] = i;
	}
	/* assign i to x[i] */
	v_exchange(x);
	/* call for value exchange */
	for (i=0; i<SIZE; i++){
		printf("x[%d]=%d, &x[%d]=%x\n", i, x[i], i, &x[i]);
	}
	return 0;
}

void v_exchange(int a[]){
	int i;
	//for every element in a[] 
		//store the end element
		// put the current i element in size-1
		// put stored element in a[i]
}

