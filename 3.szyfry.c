#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<unistd.h>

//coding message start

//take message from keyboad
void inputMessage(char *pMes)
{	
	fflush(stdin);
	printf("Enter your Message: ");
	fgets(pMes, 256, stdin);
	//printf("test InputMessage: %s\n", pMes);
	
}


//take key from keyboard (dynamic allocation)
void inputKey(int *pKey, int *pkeyLength)
{
	
	int taker;	
	int i = 0;
	printf("Enter key and finish it with 255: ");
	
	
	while(1)
	{
		
		scanf("%d", &taker); 
		
		if(taker == 255 || i == 10) break;
		else
		{
			*(pKey+i) = taker;
		}
		i++;

	}
	
	*pkeyLength = i;

}



//kodowanie wiadomosci
//przekazanie ca≥ej tablicy jako parametr (zamiast przekazania wskaünika) sprawia, øe nie musimy przekazaÊ oddzielnie wskaünika do tablicy oraz jej d≥ugoúci
//dla odmiany tablica kluczy jest przekazywana jako wskaünik do pierwszego elementu oraz d≥ugoúÊ tablicy jako wartosc
void codeMessage(char message[256], char *pCodedMessage, int *pKey, int keyLength)
{
	int i = 0;
	
	for(i = 0; i<(int)strlen(message)-1; i++)
	{
		*(pCodedMessage + i) = message[i] + *(pKey+(i%keyLength));
	}
}




//main for coding input message
void mainCodeMessage()
{
	printf("Coding\n");
	char message[256];
	char codedMessage[256];
	
	int *pKey;
	int keyLength = 0;
	int *pKeyLength = &keyLength;

	pKey = (int *)malloc(40);
	
	char *pMessage = &message[0];
	char *pCodedMessage = &codedMessage[0]; 



	
	
	inputMessage(pMessage);
	inputKey(pKey, pKeyLength);
	codeMessage(message, pCodedMessage, pKey, keyLength);

	
	printf("Coded message in main: %s\n", codedMessage);
	
	
}

void inputCodedMessage(char *pCodedMessage)
{
	fflush(stdin);
	printf("Enter your Message:");
	fgets(pCodedMessage, 256, stdin);
	//printf("InputCodedMessage: %s\n", pCodedMessage);
	
}

void uncodeMessage(char codedMessage[256], char *pMessage, int *pKey, int keyLength)
{
	int i = 0;
	
	for(i = 0; i<(int)strlen(codedMessage)-1; i++)
	{
		*(pMessage + i) = codedMessage[i] - *(pKey+(i%keyLength));
	}
}

void mainUncodeMessage()
{
	printf("Uncoding\n");
	char codedMessage[256];
	char message[256];
	
	char *pCodedMessage = &codedMessage[0];
	char *pMessage = &message[0];
	

	int *pKey;
	pKey = (int *)malloc(40);
	int keyLength;
	int *pKeyLength = &keyLength;
	
	inputCodedMessage(pCodedMessage);
	inputKey(pKey, pKeyLength);
	
	uncodeMessage(codedMessage, pMessage, pKey, keyLength);
	
	printf("%s\n", pMessage);
}



int main()
{	

	char czarik;
	
	//loopLabel:
	
	while(czarik != 'c' || czarik != 'u' )
	{
		printf("coding(c)/uncoding(u)?\n");
		czarik = getch();
		
		if(czarik=='c')mainCodeMessage();
		if(czarik=='u')mainUncodeMessage();
		czarik = ' ';
		sleep(1);
	}
		//goto loopLabel;

}


