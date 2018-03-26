#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void inputMessage(char *pMes)
{
	printf("Enter your Message: ");
	fgets(pMes, 256, stdin);
	printf("test InputMessage: %s\n", pMes);
	
}

void inputKey(int *pKey, int *pkeyLength)
{
	
	int taker;	
	int i = *pkeyLength;
	printf("Enter key and finish it with 255): ");
	
	
	while(1)
	{
		//pogrzebany pies
		
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


int main()
{
	char message[256];
	int *pKey;
	int keyLength = 0;
	int *pkeyLength = &keyLength;
	size_t size = 100;  
	pKey = (int *)malloc(32);
	char *pMes = &message[0]; 
	
	
	inputMessage(pMes);
	printf("test main: %s", message);
	
	inputKey(pKey, pkeyLength);	
	}

