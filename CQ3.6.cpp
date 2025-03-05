#include <stdio.h>
#include <math.h>
int main()
{
	float width, height, perimeter, area, diagonal;
	printf("Input width: ");
	scanf("%f",&width);
	printf("Input height: ");
	scanf("%f",&height);
	perimeter=2*width+2*height;
	area=width*height;
	diagonal=sqrt(width*width+height*height);
	printf("Perimeter: %f\n",perimeter);
	printf("Area: %f\n",area);
	printf("Diagonal: %f\n",diagonal);
	return 0;
}
