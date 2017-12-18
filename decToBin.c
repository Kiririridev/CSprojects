
#include<stdio.h>
#include<math.h>

int n; //ilosc wprowadzanych liczb, potem nadpisywana
void mainMenu(); //funkcja glownego menu
void about(); //wyswietla opis programu
int input();  //pobiera dane z klawiatury
void decToBin(int x); //konwertuje liczbe

int main()		//sterowanie programem
{
	mainMenu();
	
	if(n==1)	//dla pojedynczych int
	{
		int x;
		x = input();
		
		decToBin(x);
	

	}else		//dla tablic int
	{
		int y[n];
		int i = 0;
		for(i = 0; i<n; i++)
		{
			y[i] = input();
		}
		
		for(i = 0; i<n; i++)
		{
			decToBin(y[i]);
		}

	}	
}

void mainMenu() //pyta czy ile chcemy liczb i czy chcemy zobaczyc info
{	
	do{	//petla powtarza pytanie, jesli wybierzemy wyswietlenie info
	
		printf("\nWprowadź ilość liczb na których chcesz pracować. By wyświetlić informacje o programie wprowadź 0.");
		printf("\nIlość liczb:  ");
		scanf("%d", &n);

		if(n==0)
		{
			about();
		}
	} while(n==0);
}


void about()		// wyswietla info
{
	printf("\nautor: Bartlomiej Kirejczyk");
	printf("\nkierunek: Informatyka");
	printf("\ngrupa lab: 13");
	printf("\n");
}

int input()		//funcja zwracajaca wprowadzane z klawiatury liczby
{	
	int x;
	printf("\nWprowadz liczbe: ");
	scanf("%d", &x);

	return x;
}

void decToBin(int x)                //funkcja zamieniajaca liczby dziesietne na binarne
{	
	int dec = x;
	int digits = 0;



	while(dec>=pow(2,digits))
	{
		digits++;
	}
	
	char bin[digits];
	
	int i = 0;
	for(i = 0; i<=digits-1; i++)    //zapisywanie wyniku jako szereg zer i jedynek, zaczynajac od konca
	{
		if(dec%2==1)
		{
			bin[digits-i-1]='1';
			
		}else
		{
			bin[digits-i-1]='0';
			
		}

	dec = dec/2;;
	}
	

	printf("\n%d  w systemie dziesietnym to ", x);            //wyswietlanie wyniku
	for(i=0; i<digits; i++)
	{
		printf("%c ", bin[i]);
	}
	printf(" w systemie binarnym.\n");
}
