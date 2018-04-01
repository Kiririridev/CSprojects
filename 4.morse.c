#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DICTIONARY_SIZE 25


struct morseLetterPair
{
	char letter;
	char morse[5];
};

void loadDictionary(struct morseLetterPair *alphabet)
{
	
	(*alphabet).letter = 'a';
	strncpy((*alphabet).morse, ".-", 3);
	
	(*(alphabet+1)).letter = 'b';
	strncpy((*(alphabet+1)).morse, "-...", 5);
	
	(*(alphabet+2)).letter = 'c';
	strncpy((*(alphabet+2)).morse, "-.-.", 5);
	
	(*(alphabet+3)).letter = 'd';
	strncpy((*(alphabet+3)).morse, "-..", 4);
	
	(*(alphabet+4)).letter = 'e';
	strncpy((*(alphabet+4)).morse, ".", 2);
	
	(*(alphabet+5)).letter = 'f';
	strncpy((*(alphabet+5)).morse, "..-.", 5);
	
	(*(alphabet+6)).letter = 'g';
	strncpy((*(alphabet+6)).morse, "--.", 4);
	
	(*(alphabet+7)).letter = 'h';
	strncpy((*(alphabet+7)).morse, "....", 5);
	
	(*(alphabet+8)).letter = 'i';
	strncpy((*(alphabet+8)).morse, "..", 3);
	
	(*(alphabet+9)).letter = 'j';
	strncpy((*(alphabet+9)).morse, ".---", 5);
	
	(*(alphabet+10)).letter = 'k';
	strncpy((*(alphabet+10)).morse, "-.-", 4);
	
	(*(alphabet+11)).letter = 'l';
	strncpy((*(alphabet+11)).morse, ".-..", 5);
	
	(*(alphabet+12)).letter = 'm';
	strncpy((*(alphabet+12)).morse, "--", 3);
	
	(*(alphabet+13)).letter = 'n';
	strncpy((*(alphabet+13)).morse, "-.", 3);
	
	(*(alphabet+14)).letter = 'o';
	strncpy((*(alphabet+14)).morse, "---", 4);
	
	(*(alphabet+15)).letter = 'p';
	strncpy((*(alphabet+15)).morse, ".--.", 5);
	
	(*(alphabet+16)).letter = 'q';
	strncpy((*(alphabet+16)).morse, "--.-", 5);
	
	(*(alphabet+17)).letter = 'r';
	strncpy((*(alphabet+17)).morse, ".-.", 4);
	
	(*(alphabet+18)).letter = 't';
	strncpy((*(alphabet+18)).morse, "-", 2);
	
	(*(alphabet+19)).letter = 'u';
	strncpy((*(alphabet+19)).morse, "..-", 4);
	
	(*(alphabet+20)).letter = 'v';
	strncpy((*(alphabet+20)).morse, "...-", 5);
	
	(*(alphabet+21)).letter = 'w';
	strncpy((*(alphabet+21)).morse, ".--", 4);
	
	(*(alphabet+22)).letter = 'x';
	strncpy((*(alphabet+22)).morse, "-..-", 5);
	
	(*(alphabet+23)).letter = 'y';
	strncpy((*(alphabet+23)).morse, "-.--", 5);
	
	(*(alphabet+24)).letter = 'z';
	strncpy((*(alphabet+24)).morse, "--..", 5);
}

void translate(char *message, struct morseLetterPair *pDictionary, int messageLength)
{
	int i = 0, j = 0;
	char singleSign;
	printf("translation: \n");
	for( j = 0; j<messageLength; j++){
		
		singleSign = *(message + j);  
		for(i = 0;i<DICTIONARY_SIZE; i++)
		{	
			if(singleSign==(*(pDictionary+i)).letter) printf("%s ", (*(pDictionary + i)).morse);
	
		}
	}
}

void mainMnemoToMorse(void)
{
	printf("Wprowadz wiadomosc\n");
	
	char message[256];
	char *pMessage = &message[0];

	
	scanf("%s", message);
	printf("%s\n", message);

	struct morseLetterPair dictionary[30];
	struct morseLetterPair *pDictionary = &dictionary[0];
	
	loadDictionary(pDictionary);
	
	translate(pMessage, pDictionary, strlen(message));	

}

char translateWord(char *superWord, int wordLength, struct morseLetterPair *pDictionary)
{
	printf("translateWord argument: %s, %d\n", superWord, wordLength);
	char word[wordLength];
	
	int i =0;
	for(i=0;i<wordLength; i++)
	{
		word[i] = *(superWord + i);
	}
	
	for(i = 0;i<DICTIONARY_SIZE; i++)
	{
		printf("s1: %s, s2: %s, compRes: %d\n", word, (*(pDictionary + i)).morse, strcmp(word,(*(pDictionary + i)).morse));
		if(strcmp(word,(*(pDictionary + i)).morse)==0)
		{
			printf("fineletter: %c\n", (*(pDictionary + i)).letter);
			return (*(pDictionary + i)).letter;
		}
	}
}

void translateToMnemo(char morseMessage[256])
{
	char word[20];
	char decodedMessage[20];
	char *pDecodedMessage = &decodedMessage[0];
	
	char taker;
	struct morseLetterPair dictionary[DICTIONARY_SIZE];
	struct morseLetterPair *pDictionary = &dictionary[0];
	
	loadDictionary(pDictionary);
	
	
	int i = 0, w = 0, dM = 0;
	for(i = 0; i<(int)strlen(morseMessage); i++)
	{
		taker = morseMessage[i];
		if(taker=='-' || taker=='.')
		{
			word[w] = taker;
			w++;
		}else
		{
			printf("word: %s\n", word);
			decodedMessage[dM] = translateWord(word, w, pDictionary);
			dM++;
			w=0;
			strncpy(word, "", 20);

		}
	}
	
	printf("decodedMessage: %s", decodedMessage);
}

void mainMorseToMnemo(void)
{
	printf("Wprowadz wiadomosc w alfabecie Morse'a. Zakoncz ja zerem.\n");
	char morseMessage[256];
	char czarik;
	//char *pMorseMessage[0];
	
	int i = 0;
	while(1)
	{
		czarik = getchar();
		if(czarik == '0') break;
		else
		{
			morseMessage[i] = czarik;
			i++;
		}
	}
	
	printf("%s\n", morseMessage);
	
	translateToMnemo(morseMessage);
}

int main()
{
	char czarik;
	printf("Program kodujacy i dekodujacy alfabet Morse'a\n");
	
	askAgain:
	printf("Wybierz tryb kodowanie(k)/dekodowanie(d)\n");
	
	czarik = getch();
	
	if(czarik == 'k') mainMnemoToMorse();
	else
	{
		if(czarik == 'd') mainMorseToMnemo();
		else{
		goto askAgain;
		}
	}	
	
	return 0;	
}
