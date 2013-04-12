#include <stdio.h>
/* Note: Program assumes years are in the same century. */
struct date {
	int month, day, year;
};
int compare_dates(struct date d1, struct date d2);
void put_date(struct date d);
int main(void)
{
struct date d1, d2;
printf("Enter first date in this style with no brackets (mm/dd/yy): ");

int input1[] = {06,10,01};
d1.month = input1[0];
d1.day = input1[1];
d1.year = input1[2];
printf("Enter second date (mm/dd/yy): ");

int input2[] = {10,10,10};
d2.month = input2[0];
d2.day = input2[1];
d2.year = input2[2];

if (compare_dates(d1, d2) < 0) {
put_date(d1);
printf(" is earlier than ");
put_date(d2);
printf("\n");
} else {
put_date(d2);
printf(" is earlier than ");
put_date(d1);
printf("\n");
}
return 0;
}
/*
*if date 1 is earlier than date 2 this function should
*return an int that should be treated as a bool with 1 being true and 0 being false  
*algorithm:
*	if date1 year is less than date2's year and
*		date1's month is less than date2's month and
*			date1's day is less than date2's day
*				then return true
*	otherwise return false
* 
*/
int compare_dates(struct date d1, struct date d2){
	if(d1.year<d2.year&&d1.month<d2.month&&d1.day<d2.day){
		return 0;
	}else{
		return 1;
	}
}
void put_date(struct date d)
{
printf("%d/%d/%.2d", d.month, d.day, d.year);
}

