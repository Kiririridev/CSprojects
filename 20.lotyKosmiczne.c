#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include"TestLotyKosmiczne.h"

//extern void testNameTableInitializator(char*);
extern void testNameTableInitializator2(void (*funcNameTableInitializator)(char*));
extern void testRandomInteger(int (*funcRandInt)(int, int));
extern void testNameGenerator(void (*funcNameGenerator)(char* pName, char* pNameTable), void (*funcNameTableInitializator)(char*));


int randomInteger(int from, int to)
{
	return  from + (rand()%(to - from));
}

void nameTableInitializator(char* pNameTable)
{	
	
	*(pNameTable) = 'P';
	*(pNameTable + 2) = 'S';
	*(pNameTable + 4) = 'R';
	*(pNameTable + 6) = 'Z';
	*(pNameTable + 8) = 'K';
	*(pNameTable + 10) = 'A';
	*(pNameTable + 12) = 'L';
	*(pNameTable + 14) = 'M';
	*(pNameTable + 16) = 'Z';
	*(pNameTable + 18) = 'J';
	
	
	int i = 0;
	for(i = 0; i<10; i++)
	{
		*(pNameTable + (2 * i) + 1) = 'a';
	}
	

}


void nameGenerator(char* pName, char* pNameTable)
{
	int i = 0, randomNumber;
	
	for(i = 0; i < 3; i++)
	{
		randomNumber = randomInteger(0, 9);
		*(pName + (2 * i)) = *(pNameTable + (randomNumber * 2));
		*(pName + (2 * i )+ 1) = *(pNameTable + (randomNumber * 2) + 1);
	}
}

void createPlanet(struct Planet* pPlanet, char* pNameTable)
{
	char* pPlanetName = ((*(pPlanet)).name);
	nameGenerator(pPlanetName, pNameTable);
	
	(*pPlanet).cordX = randomInteger(0, 100);
	(*pPlanet).cordY = randomInteger(0, 100);
	(*pPlanet).cordZ = randomInteger(0, 100);
	
	(*pPlanet).isGas = randomInteger(0, 2);
	
}



//=========================START=============================
void start()
{
	char nameTable[10][2];
	char *pNameTable = &nameTable[0][0];
	nameTableInitializator(pNameTable);
}

//=========================TESTY===========================
void testy()
{
	int (*funcRandInt)(int, int) = &randomInteger;
	void (*funcNameTableInitializator)(char*) = &nameTableInitializator;
	void (*funcNameGenerator)(char*, char*) = &nameGenerator;
	void (*funcCreatePlanet)(struct Planet*, char* pNameTable) = &createPlanet;
	
	
	char *pNameTable = malloc (10 * 2 * sizeof(char));
	nameTableInitializator(pNameTable);
	
	
	testRandomInteger(funcRandInt);
	testNameTableInitializator2(funcNameTableInitializator);
	testNameGenerator(funcNameGenerator, funcNameTableInitializator);
	testCreatePlanet(funcCreatePlanet, pNameTable);

	
	free(pNameTable);
}

//=========================MAIN================================

int main()
{
	
	srand(time(NULL));
	testy();

}
