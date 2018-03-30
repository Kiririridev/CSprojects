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
	printf("test InputMessage: %s\n", pMes);
	
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
	
	/*
	int n = 0;
	for(n = 0; n<i; n++)
	{
		printf("%d\n", *(pKey+n));
		
	}
	*/
	
	
}


/*
void codeMessageOld(char message[256], char *pCMes, int *pKey, int keyLength)
{
	int staticKey[keyLength];
	int i = 0;
	
	for(i = 0; i<keyLength; i++)
	{
		staticKey[i] = *(pKey + i);
	}
	
	printf("key: ");
	for(i = 0; i<keyLength; i++)
	{
		printf(" %d ", staticKey[i]);
	}printf("\n");
	

	for(i = 0; i<(strlen(message)-1); i++)
	{		
		*(pCMes + i) = message[(i+staticKey[i%keyLength])%(strlen(message)-1)];
		
	}
}
*/

//kodowanie wiadomosci
//przekazanie ca³ej tablicy jako parametr (zamiast przekazania wskaŸnika) sprawia, ¿e nie musimy przekazaæ oddzielnie wskaŸnika do tablicy oraz jej d³ugoœci
//dla odmiany tablica kluczy jest przekazywana jako wskaŸnik do pierwszego elementu oraz d³ugoœæ tablicy jako wartosc
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
	printf("InputCodedMessage: %s\n", pCodedMessage);
	
}

/*
void uncodeMessageOld(char codedMessage[256], char *pMes, int *pKey, int keyLength)
{
	
	char message[256];
	int i = 0;
	int staticKey[10];
	
	
	for(i = 0; i<keyLength; i++)
	{
		staticKey[i] = *(pKey + i);
	}
	

	
	printf("key: ");
	for(i = 0; i<keyLength; i++)
	{
		printf(" %d ", staticKey[i]);
	}printf("\n");
	

	int celM;
	
	for(i = 0; i<strlen(codedMessage)-1; i++)
	{

		celM = (i+staticKey[i%3])%6;
		message[celM] = codedMessage[i];
			
	}
		
	printf("in uncode: %s\n", codedMessage);
	printf("in uncode: %s\n", message);
}

*/

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
	
	loopLabel:
	
	printf("coding(c)/uncoding(u)?\n");
	czarik = getch();
	
	if(czarik=='c')mainCodeMessage();
	if(czarik=='u')mainUncodeMessage();
	czarik = ' ';
	sleep(1);
	goto loopLabel;

}


