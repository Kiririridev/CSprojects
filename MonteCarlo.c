#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<sys/time.h>

#define fOd 1.0
#define fDo 10.0`
#define dx 0.01
#define numberOfTests 10000

double f1(double x)
{
	return sin(x);
}

/*
double losuj(double min, double max)
{
	double tmp = max - min;
	double l;
 
	l = rand();
	printf("random number generator: tmp: %f, l: %f, fmod: %f\n", tmp, l, fmod(l, tmp));
	return (fmod(l, tmp) + min);
}
*/


double losujDouble(double min, double max)
{
	double range = (max- min);
	double div = RAND_MAX / range;
	return min + rand() / div;
}

/*
double defineMINMAX(double *pmin, double *pmax)
{
	double ff, x;
	double max = 0;
	double min = 0;

	for(x = fOd; x<=fDo; x+=dx)
	{
		ff = f1(x);
		if(ff>max)
		{
			max = ff;
		}//else if(ff<min)
		//{
		//	min = ff;
		//}
		
	}
	*pmin = min;
	*pmax = max;
	printf("min: %3.3f, max: %3.3f\n", min, max);
}
*/

double defineMAX()
{
	double ff, x;
	double max = 0;


	for(x = fOd; x<=fDo; x+=dx)
	{
		ff = f1(x);
		if(ff>max)
		{
			max = ff;
		}
		
	}

	printf("max: %3.3f\n", max);
	
	return max;
}

int checkPoint(double x, double y)
{
	int flag = 0;
	double ff = f1(x);
	printf("ff before abs: %f   ", ff);
	if(ff<0) flag = 1;
	ff = fabs(ff);
	printf("x: %f, y: %f, ff: %f\n", x, y, ff);
	
	if(ff>=y)
	{
		if(flag==1)
		{
			return -1;
		}else return 1;
	}else return 0;
}



int main()
{	
	int it, n, pointsInside;
	double min, max, result;
	n = numberOfTests;
	pointsInside = 0;
	srand(time(NULL));
	
	//defineMINMAX(&min, &max);
	max= defineMAX();
	
	it = 0;
	for(it = 0; it<n; it++)
	{
		//if(checkPoint(losuj(fOd, fDo), losuj(min, max))==1)
		//{
		//	pointsInside++;
		//}
		pointsInside+=checkPoint(losujDouble(fOd, fDo), losujDouble(min, max));
	}
	
	printf("pointsInside/n: %d/%d\n", pointsInside, n);
	printf("fDo - fOd: %f\n", (fDo-fOd));
	printf("max: %f, min: %f\n", max, min);
	
	result = (max-min) * (fDo - fOd) * ((double)pointsInside/(double)n);
	
	printf("%f", result);
	
	return 0;
}
