#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//coding message start

//take message from keyboad
void inputMessage(char *pMes)
{
	printf("Enter your Message: ");
	fgets(pMes, 256, stdin);
	printf("test InputMessage: %s\n", pMes);
	
}


//take key from keyboard (dynamic allocation)
void inputKey(int *pKey, int *pkeyLength)
{
	
	int taker;	
	int i = *pkeyLength;
	printf("Enter key and finish it with 255): ");
	
	
	while(1)
	{
		
		scanf("%d", &taker); 
		
		if(taker == 255) break;
		else
		{
			*(pKey+i) = taker;
		}
		i++;
	}
	
	*pkeyLength = i;
	
	int n = 0;
	for(n = 0; n<i; n++)
	{
		printf("%d\n", *(pKey+n));
		
	}
}

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

void codeMessage(char message[256], char *pCMes, int *pKey, int keyLength)
{
	int i = 0;
	
	for(i = 0; i <strlen(message)-1; i++)
	{
		*(pCMes + i) = message[i] + *(pKey+(i%keyLength));
	}
}



//main for coding input message
int mainCodeMessage()
{
	printf("Coding\n");
	char message[256];
	char codedMessage[256];
	
	int *pKey;
	int keyLength = 0;
	int *pKeyLength = &keyLength;
	size_t size = 100;  
	pKey = (int *)malloc(32);
	
	char *pMes = &message[0];
	char *pCMes = &codedMessage[0]; 
	int staticKey[keyLength];
	int i = 0;

	
	
	
	inputMessage(pMes);
	inputKey(pKey, pKeyLength);
	codeMessage(message, pCMes, pKey, keyLength);

	
	printf("Coded message in main: %s\n", codedMessage);
	
	
}

void inputCodedMessage(char *pCMes)
{
	fflush(stdin);
	printf("Enter your Message:");
	fgets(pCMes, 256, stdin);
	printf("InputCodedMessage: %s\n", pCMes);
	
}

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

void uncodeMessage(char codedMessage[256], char *pMes, int *pKey, int keyLength)
{
	int i = 0;
	
	for(i = 0; i <strlen(codedMessage)-1; i++)
	{
		*(pMes + i) = codedMessage[i] - *(pKey+(i%keyLength));
	}
}

int mainUncodeMessage()
{
	printf("Uncoding\n");
	char codedMessage[256];
	char message[256];
	
	char *pCMes = &codedMessage[0];
	char *pMes = &message[0];
	
	int key[10];
	int *pKey = &key[0];
	int keyLength;
	int *pKeyLength = &keyLength;
	
	inputCodedMessage(pCMes);
	inputKey(pKey, pKeyLength);
	
	uncodeMessage(codedMessage, pMes, pKey, keyLength);
	
	printf("\n%s", pMes);
}

int main()
{	

	char czarik = getch();
	
	loopLabel:
	
	printf("coding(c)/uncoding(u)?\n");
	czarik = getch();
	
	if(czarik=='c')mainCodeMessage();
	if(czarik=='u')mainUncodeMessage();
	czarik = ' ';
	sleep(1);
	goto loopLabel;

}


