#include<stdio.h>
int main(void){
	int a[3] = {11, 22, 33};
	int *pa = a;
	//print these
	printf("%d\n",*a);
	printf("%d\n",*(a+2));	
	printf("%d\n",*pa);
	printf("%d\n",pa[1]);	
	//NEXT QUESTION
	int m[4][4] = {{1,3,5,7}, {11,33,55,77}, {2,4,6,8},{22,44,66,88}};
	int (*parr)[4] = m;
	/* **m =
	*(*m+2) =
	*(*(m+1)+1) =
	*(m[1]+2) =
	(*(m+2))[3] =
	(*(parr+3))[2] =
	*/
	printf("%d\n",**m);
	printf("%d\n",*(*m+2));
	printf("%d\n",*(*(m+1)+1));
	printf("%d\n",*(m[1]+2));
	printf("%d\n",(*(m+2))[3]);
	printf("%d\n",(*parr+3))[2]);
return 0;
}
