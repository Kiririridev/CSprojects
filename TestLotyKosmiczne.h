#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>


struct Planet
{
	char name[7]; 
	
	//Coordinates
	int cordX;
	int cordY;
	int cordZ;
	
	short isGas;
};




//PASSED
void testNameTableInitializator2(void (*funcNameTableInitializator)(char*))
{
	char* pNameTable = (char*) malloc(10 * 2 * sizeof(char));
	funcNameTableInitializator(pNameTable);
	
	printf("testNameTableInitializator2:\n");
	int i = 0;
	for(i = 0; i<10;i++)
	{	
		printf("%c %c\n", *(pNameTable + (2 * i)), *(pNameTable + (2 * i) + 1));
	}
	
	free(pNameTable);
	
}



//PASSED
void testRandomInteger(int (*funcRandInt)(int, int))
{
	printf("testRandomInteger:\n");
	int i = 0;
	for(i = 0; i<10; i++)
	{
		printf("%d\n", funcRandInt(0,10));
	}

}


//PASSED
void testNameGenerator(void (*funcNameGenerator)(char* pName, char* pNameTable), void (*funcNameTableInitializator)(char*))
{
	
	printf("\ntestNameGenerator:\n");
	int i = 0;
	char* pNameTable = (char*) malloc(10 * 2 * sizeof(char));
	funcNameTableInitializator(pNameTable);
	
	
	char* pName = (char*) malloc(6 * sizeof(char));
	
	for(i = 0; i<10;i++)
	{
		
		funcNameGenerator(pName, pNameTable);
		printf("%s\n", pName);

	}
	
	free(pNameTable);
	
}


//PASSED
void testCreatePlanet(void funcCreatePlanet(struct Planet*, char* pNameTable), char* pNameTable)
{	
	int i = 0;
	printf("\ntestCreatePlanet: \n");
	struct Planet planet;
	struct Planet *pPlanet = &planet;
	
	for(i = 0; i<10; i++)
	{
		funcCreatePlanet(&planet, pNameTable);
		printf("Planet name: %s, cordX: %d, cordY: %d, cordZ: %d, isGas: %d\n", planet.name, planet.cordX, planet.cordY, planet.cordZ, planet.isGas);
	}
}

//PASSED
void testCreateGalaxy(void funcCreateGalaxy(struct Planet*, char*), char* pNameTable, struct Planet* pPlanetList)
{
	
	printf("\ntestCreateGalaxy:\n");
	funcCreateGalaxy(pPlanetList, pNameTable);
	struct Planet planet; 
	
	int i = 0;
	for(i = 0; i<10; i++)
	{
		planet = *(pPlanetList + (i * sizeof(struct Planet)));
		printf("PlanetName: %.6s, cordX: %d, cordY: %d, cordZ: %d, isGas: %u\n", planet.name, planet.cordX, planet.cordY, planet.cordZ, planet.isGas);
	}
}


//PASSED
void testGetUserCoords(void funcGetUserCoords(int*), int* pUserCoords)
{
	printf("\ntestGetUserCoords:\n");
	


	funcGetUserCoords(pUserCoords);
	
	printf("\nStart: %dX, %dY, %dZ, End: %dX, %dY, %dZ", *pUserCoords, *(pUserCoords+1), *(pUserCoords+2), *(pUserCoords+3), *(pUserCoords+4), *(pUserCoords+5));
}

void testGeneratePathway(void funcGeneratePathway(int*, int, float*), int* pUserCoords, float* pPathway)
{
	printf("\ntestGeneratePathway:\n");
		
	funcGeneratePathway(pUserCoords, 10, pPathway);
	
	int i = 0;
	for(i = 0; i<10; i++)
	{
		printf("Point %d: %.2fX, %.2fY, %.2fZ\n", i, *(pPathway + (i * 3)), *(pPathway + (i * 3) + 1), *(pPathway + (i * 3) + 2));
	}
}

void testCheckPathway(void funcCheckPathway(float[][3] , int , struct Planet* ), float pathway[][3], int amountOfPoints, struct Planet* pPlanetTable)
{
	printf("\ntestCheckPathway\n");
	
	funcCheckPathway(pathway, amountOfPoints, pPlanetTable);
}

void testCheckPlanetOnPath(int funcCheckPlanetOnPath(float, float, float, struct Planet*, float))
{
	printf("\ncheckPlanetOnPath\n");
	
	struct Planet planet;
	planet.cordX = 15;
	planet.cordY = 15;
	planet.cordZ = 15;
	planet.isGas = 0;
	struct Planet* pPlanet = &planet;
	float flo = 6.0;
	
	funcCheckPlanetOnPath(12.0, 12.0, 12.0, pPlanet, 6.0);
	
}
