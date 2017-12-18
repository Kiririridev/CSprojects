#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 100

double szereg(double x)
{
	double s, w;
	int i;
	s=1;
	w=1;
	
	for(i=1;i<n;i=i+1)
	{
		w=-w*x*x;
		s=s+w;           
	}                  

	return s;    
}       


int main()
{
	int lp;
	double a, b, krok, x;
	printf("podaj konce przedzialow i liczbe podprzedzialow\n");
	scanf("%lf %lf %d",&a,&b,&lp);
	krok=(b-a)/lp;

	printf("krok=%6.2lf\n\n\n",krok);

	printf("     ----------------------------\n\n");
	printf("        x    szereg(x)  1/(1+x^2)\n     ----------------------------\n");

	for (x=a;x<=b;x+=krok) printf("%10.2lf    %7.4lf    %7.4lf\n",x,szereg(x),(1/(1+pow(x,2))));

	printf("     ----------------------------\n\n");

	return 0;
}
