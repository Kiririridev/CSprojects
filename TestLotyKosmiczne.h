#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>


struct Planet
{
	char name[6]; 
	
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

void testCreateGalaxy(void funcCreateGalaxy(struct Planet*, char*), char* pNameTable, struct Planet* pPlanetList)
{
	int i = 0;
	printf("\ntestCreateGalaxy:\n");
	funcCreateGalaxy(pPlanetList, pNameTable);
	struct Planet planet; 
	
	for(i = 0; i<10; i++)
	{
		planet = (*(pPlanetList + (i * sizeof(struct Planet))));
		printf("PlanetName: %s, cordX: %d, cordY: %d, cordZ: %d, isGas: %u\n", planet.name, planet.cordX, planet.cordY, planet.cordZ, planet.isGas);
	}
}
	




