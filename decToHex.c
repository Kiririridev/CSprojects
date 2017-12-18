#include<stdio.h>
#include<math.h>

int n; //ilosc wprowadzanych liczb, potem nadpisywana
void mainMenu(); //funkcja glownego menu
void about(); //wyswietla opis programu
int input();  //pobiera dane z klawiatury
void decToHex(int x); //konwertuje liczbe

int main()		//sterowanie programem
{
	mainMenu();
	
	if(n==1)	//dla pojedynczych int
	{
		int x;
		x = input();
		
		decToHex(x);
	

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
			decToHex(y[i]);
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


void decToHex(int x)                //funkcja zamieniajaca liczby dziesietne na binarne
{	
	int dec = x;
	int digits = 0;



	while(dec>=pow(16,digits))
	{
		digits++;
	}
	
	char hex[digits];
	
	int i = 0;
	for(i = 0; i<=digits-1; i++)    //zapisywanie wyniku jako szereg zer i jedynek, zaczynajac od konca
	{
		
		switch(dec%16){
			case 0:
			hex[i] = '0';
			break;
	
			case 1:
                        hex[i] = '1';
                        break;
			
			case 2:
                        hex[i] = '2';
                        break;
			
			case 3:
                        hex[i] = '3';
                        break;

			case 4:
                        hex[i] = '4';
                        break;

			case 5:
                        hex[i] = '5';
                        break;

			case 6:
                        hex[i] = '6';
                        break;

			case 7:
                        hex[i] = '7';
                        break;

			case 8:
                        hex[i] = '8';
                        break;

			case 9:
                        hex[i] = '9';
                        break;

			case 10:
                        hex[i] = 'A';
                        break;

			case 11:
                        hex[i] = 'B';
                        break;

			case 12:
                        hex[i] = 'C';
                        break;
	
			case 13:
                        hex[i] = 'D';
                        break;			

			case 14:
                        hex[i] = 'E';
                        break;

			case 15:
                        hex[i] = 'F';
                        break;}

	dec = dec/16;
	}
	

	printf("\n%d  w systemie dziesietnym to ", x);            //wyswietlanie wyniku
	
		
	for(i=digits-1; i>=0; i--)
	{
		printf("%c ", hex[i]);
	}
	printf(" w systemie szestnastkowym.\n");
}
