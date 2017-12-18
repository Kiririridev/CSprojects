#include<stdio.h>
#include<math.h>

void wczytajWektor(int wektor[3])
{
	printf("podaj parametry wektora: \n");
	int i =0;
	for(i= 0; i<3; i++)
	{
		scanf("%d", &wektor[i]);
	}
}

void iloczynWektorowy(int wektor1[3], int wektor2[3], int iloczyn[3])
{
	
	iloczyn[0] = (wektor1[1]*wektor2[2]) - (wektor1[2]*wektor2[1]);
	iloczyn[1] = (wektor1[0]*wektor2[2]) - (wektor1[2]*wektor2[0]);
	iloczyn[2] = (wektor1[0]*wektor2[1]) - (wektor1[1]*wektor2[0]);		
}

void drukarzWektorowy(int wektor[3])
{	
	printf("Wynik iloczynu to: \n");
	int i = 0;
	for(i =0; i<3; i++)
	{
		printf("%d, ", wektor[i]);
	}
}


int main()
{
	int wektorA[3];
	int wektorB[3];

	wczytajWektor(wektorA);
	wczytajWektor(wektorB);
	
	int wektorIloczyn[3];
	iloczynWektorowy(wektorA, wektorB, wektorIloczyn);

	drukarzWektorowy(wektorIloczyn);
}
