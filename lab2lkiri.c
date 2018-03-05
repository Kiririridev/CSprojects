#include <math.h>
#include <stdio.h>


#define XX 4
#define YY 4
#define NN 5
//#define NN 0
//#define NN -5

/* Zad ASDPetle
2.  Dla danego ogólnego iteracyjnego algorytmu utwórz równowa¿ny
program,  w których wyeliminujesz skok bezwarunkowy
a) zastepuj¹c go pêtl¹   while (warunek) instrukcja
a) zastepuj¹c go pêtl¹   do instrukcja while (warunek)
Uwaga: instrukcje 1 i 2 mog¹ wzajemnie od siebie zale¿eæ
i nie zmieniaj¹c wartoœci  n  mog¹ od niej zale¿eæ.
*/
void PetlaGoTo() {
	int i = 0, n = NN;     double x = XX, y = YY;
pocz:
	x = x + 1 + y + n + i;
	if (n > 0) {          		 // printf ("s%10.4lf %10.4lf %10d\n",y,t,i);
		i = i + 1;
		y = x + y - 1 - n - 2 * i;
		n = n - 1;
		goto pocz;
	}
	printf("\n\tPetla Go To\t%10d %10d%10.4lf%10.4lf\n", i, n, x, y);
}


void WhileA() {
	int i = 0, n = NN; 	double x, y;    x = XX, y = YY;
	
	
	while(n>0)
	{
		x = x + 1 + y + n + i;
		
		i = i + 1;
		y = x + y - 1 - n - 2 * i;
		n = n - 1;
	}
	
	x = x + 1 + y + n + i;	
	
	printf("\n\tPetla WhileA\t%10d %10d%10.4lf%10.4lf\n", i, n, x, y);
}
void WhileB() {
	int i = 0, n = NN; 	double x, y;    x = XX, y = YY;
	
	while(x = x + 1 + y + n + i, n>0)
	{
		
		
		i = i + 1;
		y = x + y - 1 - n - 2 * i;
		n = n - 1;
	}
	
	
	printf("\n\tPetla WhileB\t%10d %10d%10.4lf%10.4lf\n", i, n, x, y);
}
void WhileC() {
	int i = 0, n = NN; 	double x, y;    x = XX, y = YY;
	//..........
	printf("\n\tPetla WhileC\t%10d %10d%10.4lf%10.4lf\n", i, n, x, y);
}
void PetlaDoA1() {
	int i = 0, n = NN;  double x, y;    x = XX, y = YY;
	
	
	do
	{
		x = x + 1 + y + n + i;
		i = i + 1;
		y = x + y - 1 - n - 2 * i;
		n = n - 1;
	}while(n>0);

	x = x + 1 + y + n + i;
	printf("\n\tPetla Do vA1\t%10d %10d%10.4lf%10.4lf\n", i, n, x, y);
}
void PetlaDoA2() {
	int i = 0, n = NN;  double x, y;    x = XX, y = YY;
	
	x = x + 1 + y + n + i;
	do
	{
		i = i + 1;
		y = x + y - 1 - n - 2 * i;
		n = n - 1;
		x = x + 1 + y + n + i;
	}while(n>0);
	
	

	
	
	printf("\n\tPetla Do vA2\t%10d %10d%10.4lf%10.4lf\n", i, n, x, y);
}
void PetlaDoB() {
	int i = 0, n = NN;  double x, y;     x = XX, y = YY;
	//..........
	printf("\n\tPetla Do vB\t%10d %10d%10.4lf%10.4lf\n", i, n, x, y);
}
void PetlaDoC() {
	int i = 0, n = NN;  double x, y;     x = XX, y = YY;
	//..........
	printf("\n\tPetla Do vB\t%10d %10d%10.4lf%10.4lf\n", i, n, x, y);
}

/*#undef XX
#undef YY
#undef NN
*/

int main()
{
	printf("start\n");
	PetlaGoTo();
	WhileA();
	WhileB();
	//WhileC();
	PetlaDoA1();
	PetlaDoA2();
	//PetlaDoB();
	//PetlaDoC();
	// getchar();
	return 0;
}


/*

start NN=5

Petla Go To              5          0 1042.0000  631.0000

ROZWIAZANE TESTY WYNIKOW
Petla Go To              5          0 1042.0000  631.0000
Petla While vA           5          0 1042.0000  631.0000
Petla While vB           5          0 1042.0000  631.0000
Petla While vC           5          0 1042.0000  631.0000
Petla Do vA1             5          0 1042.0000  631.0000
Petla Do vA2             5          0 1042.0000  631.0000
Petla Do vB              5          0 1042.0000  631.0000
Petla Do vC              5          0 1042.0000  631.0000
Petla Do vA2             5          0 1042.0000  631.0000


start NN=0

Petla Go To              0          0    9.0000    4.0000

ROZWIAZANE TESTY WYNIKOW
Petla Go To              0          0    9.0000    4.0000
Petla While vA           0          0    9.0000    4.0000
Petla While vB           0          0    9.0000    4.0000
Petla While vC           0          0    9.0000    4.0000
Petla Do vA1             0          0    9.0000    4.0000
Petla Do vA2             0          0    9.0000    4.0000
Petla Do vB              0          0    9.0000    4.0000
Petla Do vC              0          0    9.0000    4.0000
Petla Do vA2             0          0    9.0000    4.0000

start   NN=-5

Petla Go To              0         -5    4.0000    4.0000

ROZWIAZANE TESTY WYNIKOW
Petla Go To              0         -5    4.0000    4.0000
Petla While vA           0         -5    4.0000    4.0000
Petla While vB           0         -5    4.0000    4.0000
Petla While vC           0         -5    4.0000    4.0000
Petla Do vA1             0         -5    4.0000    4.0000
Petla Do vA2             0         -5    4.0000    4.0000
Petla Do vB              0         -5    4.0000    4.0000
Petla Do vC              0         -5    4.0000    4.0000
Petla Do vA2             0         -5    4.0000    4.0000

*/
