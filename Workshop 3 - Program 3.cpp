#include <stdio.h>
#include <math.h>
int getRelPos ( double x, double y, double r) 
{
    double distance = sqrt(x*x + y*y);
    if (distance<r) 
        return 1;
    else if (distance==r) 
        return 0;
    else 
	    return -1;
}
int main()
{
	double x,y,r,result;
	printf("Input x, y: ");
	scanf("%lf%lf",&x,&y);
	do
	{
		printf("Input circle's radius: ");
	    scanf("%lf",&r);
	}
	while(r<0);
	result = getRelPos(x,y,r);
	if(result == 1)
	    printf("The point is in the circle!");
	else if(result == 0)
	    printf("The point is on the circle!");
	else printf("The point is out of the circle!");
	return 0;
}

