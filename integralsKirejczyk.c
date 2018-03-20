#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<math.h>

#define fOd 1.00
#define fDo 10.0
#define dx 0.01
#define numberOfTestsMC 10000

/*
Projekt 1: ca�kowanie numeryczne
Autor: Bart�omiej Kirejczyk, grupa 12, Informatyka
AiSD

Pe�en opis i dokumantacja zosta�a z�o�ona oddzielnie
*/


//ca�kowane funkcje
double f1(double x)
{
	return sin(x);
}

double f2(double x)
{
	return 2*cos(x);
}

double f3(double x)
{
	return 4*pow(x, 3);
}

double f4(double x)
{
	return -5 * pow(x, -2);
}

//*** metoda MC ***

//generator losowych liczb typu double w zakresie min max
double randomDouble(double min, double max)
{
	double range = (max- min);
	double div = RAND_MAX / range;
	return min + rand() / div;
}


//funkcja definiuj�ca maksimum w funkcji w badanym przedziale
double defineMAX(double (*f)(double x))
{
	double ff, x;
	double max = 0;


	for(x = fOd; x<=fDo; x+=dx)
	{
		ff = fabs(f(x));
		if(ff>max)
		{
			max = ff;
		}
	}
	
	return max;
}


//funkcja sprawdzaj�ca, czy punkt nale�y do funkcji
int checkPoint(double x, double y, double (*f)(double x))
{
	int isNegative = 0;
	double ff = f(x);

	if(ff<0) isNegative = 1;
	ff = fabs(ff);

	
	if(ff>=y)
	{
		if(isNegative==1)
		{
			return -1;
		}else return 1;
	}else return 0;
}


//zlicza ile losowych punkt�w znalaz�o si� w zakresie funkcji
int pointCounter(double min, double max, int n, double (*f)(double x))
{	
	int pointsInside = 0;
	int it = 0;
	for(it = 0; it<n; it++)
	{
		pointsInside+=checkPoint(randomDouble(fOd, fDo), randomDouble(min, max), f);
	}
	
	return pointsInside;
}


//dzia�anie licz�ce warto�c ca�ki
double resultCalculator(double min, double max, int pointsInside, int n)
{
	return ((max-min) * (fDo - fOd) * ((double)pointsInside/(double)n));
}


//main methody MC
double methodMC(double (*function)(double x))
{

	int n, pointsInside;
	double min, max, result;
	
	n = numberOfTestsMC;
	pointsInside = 0;
	
	srand(time(NULL));
	
	max= defineMAX(function);
	min = 0;
	
	pointsInside = pointCounter(min, max, n, function);
	
	printf("pointsInside/n: %d/%d\n", pointsInside, n);
	printf("fDo - fOd: %f\n", (fDo-fOd));
	printf("max: %f, min: %f\n", max, min);
	
	result = resultCalculator(min, max, pointsInside, n);
	printf("%f\n", result);
	
	return result;
}



//*** koniec metody MC***


//*** metoda prostok�t�w ***
//main metody prostok�t�w
double methodRectangle(double (*function)(double x))
{
	double sum = 0;
	
	double it = fOd;
	for(it = fOd; it<fDo; it+=dx)
	{
		sum+=function(it)*dx;
	}
	
	printf("sum: %lf\n", sum);

	return sum; 
}
//*** koniec metody prostok�t�w ***


//*** metoda trapez�w ***

//main metody trapez�w
double methodTrapezoid(double (*function)(double x))
{
	double sum = 0;
	
	double it = fOd+dx;
	for(it ; it<=fDo; it+=dx)
	{
		sum+=function(it);
	}
	sum+=(function(fOd)+function(fDo))/2;
	sum*=dx;
	
	printf("sum: %lf\n", sum);
	
	return sum;
}

//*** koniec metody trapez�w ***


//testy
int main()
{	
	double ( * function1)(double);
	double ( * function2)(double);
	double ( * function3)(double);
	double ( * function4)(double);
	function1 = f1;
	function2 = f2;
	function3 = f3;
	function4 = f4;
	
	printf("methodMC: \n");
	methodMC(function1);
	methodMC(function2);
	methodMC(function3);
	methodMC(function4);
	
	
	
	printf("methodRectangle: \n");
	methodRectangle(function1);
	methodRectangle(function2);
	methodRectangle(function3);
	methodRectangle(function4);
	
	
	printf("methodTrapez \n");
	methodTrapezoid(function1);
	methodTrapezoid(function2);
	methodTrapezoid(function3);
	methodTrapezoid(function4);
	
	
	return 0; 
}
