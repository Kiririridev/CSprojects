#include<stdio.h>

void inputMessage(char *pMes)
{
	printf("Enter your Message: ");
	fgets(pMes, 256, stdin);
	printf("test InputMessage: %s\n", pMes);
}

void inputKey(int *pKey)
{
	int i = 0, taker;
	printf("Enter key: ");
	for(i = 0; i<8; i++)
	{
		//pogrzebany pies
		/*
		scanf("%d", &taker);
		//if(taker == '\0') break;
		//if(taker == NULL) break;
		//else{*(pKey+i) = taker;}
		*/
	}
	
}


int main()
{
	char message[256];
	int key[8];
	char *pMes = &message[0]; 
	int *pKey = &key[0];
	
	inputMessage(pMes);
	printf("test main: %s", message);
	
	inputKey(pKey);
	
	
	
}
