#include <stdio.h>
int main()
{
	long long centuries,years,days,hours,minutes,seconds,milliseconds;
	printf("Input the number of centuries: ");
	scanf("%lld",&centuries);
	years=centuries*100;
	days=years*365.242199;
	hours=days*24;
	minutes=hours*60;
	seconds=minutes*60;
	milliseconds=seconds*1000;
	printf("%lld centuries = %lld years = %lld days = %lld hours = %lld minutes = %lld seconds = %lld milliseconds",centuries,years,days,hours,minutes,seconds,milliseconds);
	return 0;
}
