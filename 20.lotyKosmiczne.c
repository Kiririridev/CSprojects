#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include"TestLotyKosmiczne.h"

extern void testNameTableInitializator(char*);
extern void testNameTableInitializator2(void (*funcNameTableInitializator)(char*));
extern void testRandomInteger(int (*funcRandInt)(int, int));
extern void testNameGenerator(void (*funcNameGenerator)(char* pName, char* pNameTable), void (*funcNameTableInitializator)(char*));
extern void testCreatePlanet(void (*funcCreatePlanet)(struct Planet*, char* pNameTable), char* pNameTable);
extern void testCreateGalaxy(void funcCreateGalaxy(struct Planet*, char*), char* pNameTable, struct Planet* pPlanetList);

/*
*Generator liczb losowych w zakresie [from, to)
*
*/
int randomInteger(int from, int to)
{
	return  from + (rand()%(to - from));
}


/*
*Funkcja wype�nia tablice sylab, kt�ra p�niej wykorzystywana jest przez generator nazw planet.
*Wszyskitesylaby s� dwuliterowe, sk�adaj� si� z samogoski(lub a) oraz litery a. 
*@param pNameTable - wska�nik do tablicy sylab. W tablicy powinni�my mie� zamallocowane 
*przynajniej (10 * 2 * sizeof(char))
*/
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



/*
*Generator imion wykorzystuj�cy stworzon� wcze�niej tablic� z sylabami.
*Tablica potrzebuje wska�nika do pierwszego elementu �a�cucha znak�w oraz wska�nik do wczesniej
*wype�nionej tablicy sylab(s�ownika).
*
*@param pName - wska�nik do �a�cucha znak�w z imieniem. Potrzebuje zamallocowane przynajmniej (6 * sizeof(char))
*@param pNameTable - wska�nik do tablicy sylab wype�nionej przez metod� void .nameTableInitializator(char* pNameTable)
*
*/
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


/*
* "Konstruktor" dla struct Planet. Tworzy planet� i nadaje jej losowe warto�ci koordynat�w X,Y,Z oraz to czy jest gazowa.
* Wywoluje metod� nameGenerator(char* pName, char* pNameTable), by stworzy� losowe imie dla planety.
*Metode potrzebuje wskaxnika do wczesniej stworzonej planet oraz wska�nika do tablicy sylab(s�ownika)
*
*@param pPlanet - wska�nik do miejsca w pami�ci, gdzie stworzymy planet�.
*@param pNameTable - wska�nik do wype�nionej wczesniej przez funkcje .nameTableInitializator(char* pNameTable) tablic� sylab
*/
void createPlanet(struct Planet* pPlanet, char* pNameTable)
{
	char* pPlanetName = ((*(pPlanet)).name);
	nameGenerator(pPlanetName, pNameTable);
	
	(*pPlanet).cordX = randomInteger(0, 100);
	(*pPlanet).cordY = randomInteger(0, 100);
	(*pPlanet).cordZ = randomInteger(0, 100);
	
	(*pPlanet).isGas = randomInteger(0, 2);
	
}


void createGalaxy(struct Planet* pPlanetTable, char* pNameTable)
{
	int i = 0;
	for(i=0;i<10;i++)
	{
		createPlanet((pPlanetTable + (i * sizeof(struct Planet))), pNameTable);
	}
	

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
	void (*funcCreateGalaxy)(struct Planet*, char* pNameTable) = &createGalaxy;
	
	
	char *pNameTable = malloc (10 * 2 * sizeof(char));
	nameTableInitializator(pNameTable);
	//struct Planet planetList[10];
	struct Planet* pPlanetList = malloc(10* sizeof(struct Planet));

	
	
	testRandomInteger(funcRandInt);
	testNameTableInitializator2(funcNameTableInitializator);
	testNameGenerator(funcNameGenerator, funcNameTableInitializator);
	testCreatePlanet(funcCreatePlanet, pNameTable);
	testCreateGalaxy(funcCreateGalaxy, pNameTable, pPlanetList);

	
	free(pNameTable);
	free(pPlanetList);
}

//=========================MAIN================================

int main()
{
	
	srand(time(NULL));
	testy();
	
}
