/*(10 marks) Write three functions sum1, sum2, sum3 to sum up the integers
between from and to (including from and to), using recursion, iteration and
algorithm, respectively.
*/
#include <time.h>
#include <stdio.h>

unsigned int sum1(unsigned int from,unsigned int to); /* recursion */
unsigned int sum2(unsigned int from,unsigned int to); /* iteration */
unsigned int sum3(unsigned int from,unsigned int to); /* algorithm */

int main(){	
	unsigned int s;
	unsigned int from, to;
	double t1, t2;
	
	printf("Enter the fist integer:");
	scanf("%d", &from);
	printf("Enter the second integer:");
	scanf("%d", &to);
	
	t1 = clock();
	s = sum1(from, to);
	t2 = clock();
	printf("sum1=%d, %fseconds.\n", s, (t2-t1)/CLOCKS_PER_SEC);
	
	t1 = clock();
	s = sum2(from, to);
	t2 = clock();
	printf("sum2=%d, %fseconds.\n", s, (t2-t1)/CLOCKS_PER_SEC);
	
	t1 = clock();
	s = sum3(from, to);
	t2 = clock();
	printf("sum3=%d, %fseconds.\n", s, (t2-t1)/CLOCKS_PER_SEC);
	
	return 0;
}
//define sum fuctions here
int sum1(unsigned int from, unsigned int to){
	if(to == from){
		return 1;	
	}	
	return sum1(from,to-1)+1;
}

int sum2(unsigned int from, unsigned int to){
	for(from; from<to;from++){	
		printf("%d",from);	
	}	
	return from;
}
int sum3(unsigned int from, unsigned int to){
	return to*((to+from)/2);
}


