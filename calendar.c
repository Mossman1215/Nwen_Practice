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
printf("Enter first date (mm/dd/yy): ");
/* for you to complete */
printf("Enter second date (mm/dd/yy): ");
/* for you to complete */
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
int compare_dates(struct date d1, struct date d2)
{
/* for you to complete */
return 0;
}
void put_date(struct date d)
{
printf("%d/%d/%.2d", d.month, d.day, d.year);
}

