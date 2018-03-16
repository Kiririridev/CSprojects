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
Autor: Bar³omiej Kirejczyk grupa 12, Informatyka rok I

*Program liczy ca³ki metod¹ monte carlo. Metoda monte carlo polega na wyznaczeniu prostok¹ta zawieraj¹cego wycinek funkcji,
który nas interesuje, którego podstawa jest zakresem granic ca³kowania od fOd do fDo, a wysokoœc ró¿nic¹ max - min.
W programie wartoœæ min zawsze wynosi zero, a wartoœæ max jest najwiêksz¹ wartoœci¹ absolutn¹ funkcji w naszym przedziale.
Granice ca³kowania zosta³y nazwane fOd i fDo, zamiast prostego "od" i "do", poniewa¿ s³owo "do" jest juz zarezerwane dla pêtli do while.

Program zosta³ rozbity na nastêpuj¹ce funkcje:
0)f1(double x)
a)randomDouble(double min, double max)
b)defineMAX()
c)checkPoint(double x, double y)
d)pointCounter(double min, double max, int n)
e)resultCalculator(double min, double max, int pointsInside, int n)

0)jest to miejsce na wprowadzenie obliczanej funkcji 

a)generuje losow¹ liczbê zmiennoprzecinkow¹ z zakresu (min; max)

b)iteruje przez zakres funkcji, by odnaleŸæ wartoœæ najwiêkszego modu³u funkcji

c)sprawdza, czy wprowadzony w argumentach punkt (x,y) znajduje siê powy¿ej czy poni¿ej modu³u z f(x).
Je¿eli f(x) jest ujemne, funkcja zaznacza to na pocz¹tku. Procedura zostaje policzona w zwyczajny sposób,
ale gdy punkt mieœci siê w fabs(f(x)), punkt zostaje odjêty, zamiast dodany do licznika.
Dziêki zastosowaniu tego mechanizmu oraz wartoœci absolutnej mo¿emy przyj¹æ na min jako zero
i nie definiowaæ go razem z maxem. Zmniejsza to iloœæ operacji przy definiowaniu wysokoœci min-max,
przy sprawdzaniu punktów prawdopodobnie wychodzimy na zero. Algorytm jest za to prostszy, gdy porównujemy punkt
do abs(f(x)) i  nie robimy dwóch zachowañ dla f(x)>0 i f(x)<0.

d)funkcja korzysta z funkcji randomDouble i checkPoint. Zawiera w sobie pêtle for, która generuje losowe liczby double
w zakresach x=(fOd;fDo) i y=(min;max), a potem zlicza -1, 0, 1 otrzymane z funkcji sprawdzaj¹cej punkty.
Zwraca wartoœæ trafionych punktów. 

e)funkcja wykonuje proste obliczenie, które wrzucono do oddzielnej funkcji dla utrzymania porz¹dku.

Zarówno funkcja pointCounter jak i resultCalculator korzystaj¹ z liczby wszystkich prób zadeklarowanej w funkcji main
jako n, a nie z wartoœci numberOfTests zdefiniowanej w preprocesorze. Zdecydowano siê na to, by zachowaæ dogmat
funkcji jako "czarnej skrzynki". Zdaniem autora u¿ywanie wartoœci predefiniowanej/zmiennej globalnej, zamiast wartoœci
wprowadzonej jako argument jawny by³oby naruszeniem tej filozofii. 

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
	
//Funkcja srand wrzuca pocz¹tkow¹ liczbê do generowania liczb pseudolosowych. Tutaj uzale¿niamy liczby pseudolosowe od czasu
//Dziêki temu przy uruchomieniu programu o innej godzinie mamy inne liczby pseudolosowe.
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
