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
		printf("x[%d]=%d, &x[%d]=%n\n", i, x[i], i, &x[i]);
	}
	return 0;
}

void v_exchange(int a[]){
	int i;
	int end;
	//for every element in a[] 
		for(i= 0; i<SIZE/2; i++){		
		//store the end element
			end = a[(SIZE-1-i)];
		// put the current i element in size-1
			a[(SIZE-1-i)] = a[i];
		// put stored element in a[i]
			a[i] = end;
		}

}

