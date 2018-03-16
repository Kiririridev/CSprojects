#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<sys/time.h>

#define fOd 1.0
#define fDo 10.0
#define dx 0.01
#define numberOfTests 100000



double f1(double x)
{
	return sin(x);
}

/*
Autor: Bar�omiej Kirejczyk grupa 12, Informatyka rok I

*Program liczy ca�ki metod� monte carlo. Metoda monte carlo polega na wyznaczeniu prostok�ta zawieraj�cego wycinek funkcji,
kt�ry nas interesuje, kt�rego podstawa jest zakresem granic ca�kowania od fOd do fDo, a wysoko�c r�nic� max - min.
W programie warto�� min zawsze wynosi zero, a warto�� max jest najwi�ksz� warto�ci� absolutn� funkcji w naszym przedziale.
Granice ca�kowania zosta�y nazwane fOd i fDo, zamiast prostego "od" i "do", poniewa� s�owo "do" jest juz zarezerwane dla p�tli do while.

Program zosta� rozbity na nast�puj�ce funkcje:
0)f1(double x)
a)randomDouble(double min, double max)
b)defineMAX()
c)checkPoint(double x, double y)
d)pointCounter(double min, double max, int n)
e)resultCalculator(double min, double max, int pointsInside, int n)

0)jest to miejsce na wprowadzenie obliczanej funkcji 

a)generuje losow� liczb� zmiennoprzecinkow� z zakresu (min; max)

b)iteruje przez zakres funkcji, by odnale�� warto�� najwi�kszego modu�u funkcji

c)sprawdza, czy wprowadzony w argumentach punkt (x,y) znajduje si� powy�ej czy poni�ej modu�u z f(x).
Je�eli f(x) jest ujemne, funkcja zaznacza to na pocz�tku. Procedura zostaje policzona w zwyczajny spos�b,
ale gdy punkt mie�ci si� w fabs(f(x)), punkt zostaje odj�ty, zamiast dodany do licznika.
Dzi�ki zastosowaniu tego mechanizmu oraz warto�ci absolutnej mo�emy przyj�� na min jako zero
i nie definiowa� go razem z maxem. Zmniejsza to ilo�� operacji przy definiowaniu wysoko�ci min-max,
przy sprawdzaniu punkt�w prawdopodobnie wychodzimy na zero. Algorytm jest za to prostszy, gdy por�wnujemy punkt
do abs(f(x)) i  nie robimy dw�ch zachowa� dla f(x)>0 i f(x)<0.

d)funkcja korzysta z funkcji randomDouble i checkPoint. Zawiera w sobie p�tle for, kt�ra generuje losowe liczby double
w zakresach x=(fOd;fDo) i y=(min;max), a potem zlicza -1, 0, 1 otrzymane z funkcji sprawdzaj�cej punkty.
Zwraca warto�� trafionych punkt�w. 

e)funkcja wykonuje proste obliczenie, kt�re wrzucono do oddzielnej funkcji dla utrzymania porz�dku.

Zar�wno funkcja pointCounter jak i resultCalculator korzystaj� z liczby wszystkich pr�b zadeklarowanej w funkcji main
jako n, a nie z warto�ci numberOfTests zdefiniowanej w preprocesorze. Zdecydowano si� na to, by zachowa� dogmat
funkcji jako "czarnej skrzynki". Zdaniem autora u�ywanie warto�ci predefiniowanej/zmiennej globalnej, zamiast warto�ci
wprowadzonej jako argument jawny by�oby naruszeniem tej filozofii. 

*/
double randomDouble(double min, double max)
{
	double range = (max- min);
	double div = RAND_MAX / range;
	return min + rand() / div;
}

double defineMAX()
{
	double ff, x;
	double max = 0;


	for(x = fOd; x<=fDo; x+=dx)
	{
		ff = fabs(f1(x));
		if(ff>max)
		{
			max = ff;
		}
	}

//	printf("max: %3.3f\n", max);
	
	return max;
}

int checkPoint(double x, double y)
{
	int isNegative = 0;
	double ff = f1(x);
//	printf("ff before abs: %f   ", ff);
	if(ff<0) isNegative = 1;
	ff = fabs(ff);
//	printf("x: %f, y: %f, ff: %f\n", x, y, ff);
	
	if(ff>=y)
	{
		if(isNegative==1)
		{
			return -1;
		}else return 1;
	}else return 0;
}

int pointCounter(double min, double max, int n)
{	
	int pointsInside = 0;
	int it = 0;
	for(it = 0; it<n; it++)
	{
		pointsInside+=checkPoint(randomDouble(fOd, fDo), randomDouble(min, max));
	}
	
	return pointsInside;
}

double resultCalculator(double min, double max, int pointsInside, int n)
{
	return ((max-min) * (fDo - fOd) * ((double)pointsInside/(double)n));
}


int main()
{	
	int n, pointsInside;
	double min, max, result;
	n = numberOfTests;
	pointsInside = 0;
	
//Funkcja srand wrzuca pocz�tkow� liczb� do generowania liczb pseudolosowych. Tutaj uzale�niamy liczby pseudolosowe od czasu
//Dzi�ki temu przy uruchomieniu programu o innej godzinie mamy inne liczby pseudolosowe.
	srand(time(NULL));
	

	max= defineMAX();
	min = 0;
	
	
	pointsInside = pointCounter(min, max, n);

	printf("pointsInside/n: %d/%d\n", pointsInside, n);
	printf("fDo - fOd: %f\n", (fDo-fOd));
	printf("max: %f, min: %f\n", max, min);
	
	printf("%f", resultCalculator(min, max, pointsInside, n));
	
	return 0;
}
