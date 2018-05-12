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
extern void testGetUserCoords(void funcGetUserCoords(int*), int* pUserCoords);
extern void testGeneratePathway(void funcGeneratePathway(int*, int, float*), int* pUserCoords, float* pPathway);
extern void testCheckPathway(void funcCheckPathway(float* , int , struct Planet* ), float* pPathway, int amountOfPoints, struct Planet* pPlanetTable);
extern void testCheckPlanetOnPath(void funcCheckPlanetOnPath(float, float, float, struct Planet*, float));

/*
*Generator liczb losowych w zakresie [from, to)
*
*/
int randomInteger(int from, int to)
{
	return  from + (rand()%(to - from));
}


/*
*Funkcja wype3nia tablice sylab, która póYniej wykorzystywana jest przez generator nazw planet.
*Wszyskitesylaby s1 dwuliterowe, sk3adaj1 sie z samogoski(lub a) oraz litery a. 
*@param pNameTable - wskaYnik do tablicy sylab. W tablicy powinniomy miea zamallocowane 
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
*Generator imion wykorzystuj1cy stworzon1 wczeoniej tablice z sylabami.
*Tablica potrzebuje wskaYnika do pierwszego elementu 3ancucha znaków oraz wskaYnik do wczesniej
*wype3nionej tablicy sylab(s3ownika).
*
*@param pName - wskaYnik do 3ancucha znaków z imieniem. Potrzebuje zamallocowane przynajmniej (6 * sizeof(char))
*@param pNameTable - wskaYnik do tablicy sylab wype3nionej przez metode void .nameTableInitializator(char* pNameTable)
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
* "Konstruktor" dla struct Planet. Tworzy planete i nadaje jej losowe wartooci koordynatów X,Y,Z oraz to czy jest gazowa.
* Wywoluje metode nameGenerator(char* pName, char* pNameTable), by stworzya losowe imie dla planety.
*Metode potrzebuje wskaxnika do wczesniej stworzonej planet oraz wskaYnika do tablicy sylab(s3ownika)
*
*@param pPlanet - wskaYnik do miejsca w pamieci, gdzie stworzymy planete.
*@param pNameTable - wskaznik do wypelnionej wczesniej przez funkcje nameTableInitializator(char* pNameTable) tablice sylab
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


/*
*Funkcja wywo³uje 10 razy metodê createPlanet i zapisuje j¹ w tablicy planet, do której wskaŸnik przekazany jest jako parametr.
*
*@param pPlanetTable - wksaznik do pustej tablicy tablicy planet w ktorej powinno byc zaalokowane (10 * sizeof(struct Planet) miejsca) 
*@param pNameTable - wskaznik do tablicy sylab wypelnionej przez nameTableInitializator(char* pNameTable)
*/
void createGalaxy(struct Planet* pPlanetTable, char* pNameTable)
{
	int i = 0;
	for(i=0;i<10;i++)
	{
		createPlanet((pPlanetTable + (i * sizeof(struct Planet))), pNameTable);
	}
}


/*
*Funkcja pobiera od uzytkownika koordynaty poczatkowe oraz koncowe
*
*@param userCoords - wskaznik do tablicy int, w ktorej zostana zapisane koordynaty - pierwsze 3 to poczatkowe, drugie 3 to koncowe
*wymagamy wiec tablicy w ktorej mamy miejsce na 6 intow
*/
void getUserCoords(int* userCoords)
{
	printf("\nKosmonauto, wprowadz swoje koordynaty startowe oraz docelowe.\n");
	printf("Kordynaty startowe w postaci XX YY ZZ:\n");
	scanf("%d %d %d", userCoords, (userCoords + 1), (userCoords + 2));
	
	printf("Koordynaty docelowe w postaci XX YY ZZ:\n");
	scanf("%d %d %d", (userCoords + 3), (userCoords + 4), (userCoords + 5));
	
	printf("\nKoordynaty przyjeto.");
}


void generatePathway(int *userCoords, int amountOfPoints, float* pPathWay)
{
	float dX = (*(userCoords+3) - *userCoords )/amountOfPoints;
	float dY = (*(userCoords+4) - *(userCoords+1) )/amountOfPoints;
	float dZ = (*(userCoords+5) - *(userCoords+2) )/amountOfPoints;
	
	int i = 0;
	for(i = 0; i<amountOfPoints ;i++)
	{
		*(pPathWay + (i*3)) = *userCoords + (i * dX);
		*(pPathWay + (i*3) + 1) = *(userCoords + 1) + (i * dY);
		*(pPathWay + (i*3) + 2) = *(userCoords + 2) + (i * dZ);
	}
}

void checkPathway(float* pPathway, int amountOfPoints, struct Planet* pPlanetTable)
{
	
	int i = 0;
	int j =0;
	for(i=0; i<amountOfPoints; i++)
	{	
		printf("Pokonany dystans: %.2f %%\n",  100 *  ((float)i / (float)amountOfPoints));
		for(j = 0; j<10; j++)
		{
			checkPlanetOnPath(*(pPathway + (j * 3 * sizeof(float))), *(pPathway + (j * 3  + 1) * sizeof(float)), *(pPathway + (j * 3 + 2) * sizeof(float)), *(pPlanetTable + sizeof(struct Planet) * j), 5.0f);
		}
	}
	
}

void checkPlanetOnPath(float pathwayX, float pathwayY, float pathwayZ, struct Planet* planet, float safeDistance)
{
	float distance = sqrtf(powf(((pathwayX - (float) (*(planet)).cordX)), 2) + powf(((pathwayY-(float) (*(planet)).cordY)),2) + powf(((pathwayZ-(float) (*(planet)).cordZ)),2));
	float distanceX = powf(((pathwayX - (float) (*(planet)).cordX)), 2);
	float distanceY = powf(((pathwayY-(float) (*(planet)).cordY)),2);
	float distanceZ = powf(((pathwayZ-(float) (*(planet)).cordZ)),2);
	
	distance = distanceX + distanceY + distanceZ;
	distance = sqrt(distance);
	
	printf("pX: %f, pY: %f, pZ: %f\n", pathwayX, pathwayY, pathwayZ);
	printf("distance: %.2f, distX: %.2f, distY: %.2f, distZ: %.2f\n", distance, distanceX, distanceY, distanceZ);
	
	if(distance<=safeDistance)
	{
		printf("Uwaga, jesteœmy niebezpiecznie blisko planety %6s ", (*(planet)).name);
		if((*(planet)).isGas == 1) printf("ale jest gazowa");
		printf(".\n");
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
	void (*funcGetUserCoords)(int*) = &getUserCoords;
	void (*funcGeneratePathway)(int*, int, float*) = &generatePathway;
	void (*funcCheckPathway)(float* , int , struct Planet* ) = &checkPathway;
	void (*funcCheckPlanetOnPath)(float, float, float, struct Planet*, float) = &checkPlanetOnPath;
	
	
	char *pNameTable = malloc (10 * 2 * sizeof(char));
	nameTableInitializator(pNameTable);
	//struct Planet planetList[10];
	struct Planet* pPlanetList = malloc(10* sizeof(struct Planet));
	int userCoords[6];
	int* pUserCoords = &userCoords[0];
	int amountOfPoints = 10;
	float pathway[3][amountOfPoints];
	float *pPathway = &pathway[0][0];

	
	
	testRandomInteger(funcRandInt);
	testNameTableInitializator2(funcNameTableInitializator);
	testNameGenerator(funcNameGenerator, funcNameTableInitializator);
	testCreatePlanet(funcCreatePlanet, pNameTable);
	testCreateGalaxy(funcCreateGalaxy, pNameTable, pPlanetList);
	testGetUserCoords(funcGetUserCoords, pUserCoords);
	testGeneratePathway(funcGeneratePathway, pUserCoords, pPathway);
	testCheckPathway(funcCheckPathway, pPathway, amountOfPoints, pPlanetList);
	testCheckPlanetOnPath(funcCheckPlanetOnPath);
	
	free(pNameTable);
	free(pPlanetList);
}

//=========================MAIN================================

int main()
{
	
	srand(time(NULL));
	testy();
	
}
