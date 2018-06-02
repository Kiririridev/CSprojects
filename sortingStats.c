#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

#define filePath "daneRand.txt"
#define filePathOrder "dane.txt"
#define amountOfNumbers 10000000
#define testAmount 10

void generateRandomNumbToText(int amount, int max);
void swap(int* a, int *b);

void printTab(int tab[], int amount);
void printTabFromPointer(int* tab, int amount);
void readTabFromFile(int *tab, int amount);
void readTabFromFileOrder(int *tab, int amount);
void readTabFromFileReverseOrder(int *tab, int amount);


void navigation();
void groupOne(int amount, char dataType);
void groupTwo(int amount, char dataType);



void bubbleSort(int tab[], int amount);
void insertionSort(int tab[], int amount);
void selectionSort(int tab[], int amount);

void quicksort(int* tab, int start, int end);
int partitionQS(int* tab, int start, int end);

void shellSort(int tab[], int amount);

void heapify(int tab[], int amount, int i);
void heapSort(int tab[], int amount);


int main()
{
	srand(time(NULL));
	
	
	//generateRandomNumbToText(amountOfNumbers, 200);
	
	
	navigation();
	
	
	//int testTab[testAmount] = {2, 5 , 5, 7, 4, 7, 1, 9, 2, 8};
	//int* pTestTab = &testTab[0];
	
	//int tab[amountOfNumbers];
	//int *pTab = &tab[0];
	//readTabFromFile(pTab, amountOfNumbers);
	
	//int timeBegin = time(NULL);
	
	//printTab(tab, amountOfNumbers);
	
	//bubbleSort(tab, amountOfNumbers);
	//insertionSort(tab, amountOfNumbers);
	//selectionSort(tab, amountOfNumbers);
	
	//quicksort(pTab, 0, amountOfNumbers);
	
	//shellSort(tab, amountOfNumbers);
	
	//heapSort(tab, amountOfNumbers);
	
	//int timeEnd = time(NULL);
	
	//printf("%d\n", timeEnd - timeBegin);
	
	//printTab(tab, amountOfNumbers);
	//printTabFromPointer(pTestTab, testAmount);
	
	
}

void navigation()
{
	int numbs, algorithms;
	char dataType;
	printf("Witam w programie liczacym czasu sortowañ.\n");
	printf("Wybierz iloœæ liczb do sortowania(max 100000)\n");
	//scanf("%d", &numbs);
	
	printf("Wybierz grupê algorytmów: 1 - insertion, bubble, selection; 2 - quick, shell, heap\n");
	//scanf("%d", &algorithms);
	
	printf("Wybierz typ danych: a- losowe, b - odwrotnie posortowane, c - posortowane\n");
	scanf("%d %d %c", &numbs, &algorithms, &dataType);
	
	
	printf("\n %d  %d   %c", numbs, algorithms, dataType);
	if(algorithms == 2)
	{
		printf("wtf?1\n");
		groupTwo(numbs, dataType);
		printf("wtf?2\n");
	}
	
	if(algorithms == 1)
	{
		groupOne(numbs, dataType);
	}

}

void groupOne(int amount, char dataType)
{
		int tab[amount];
		int* pTab = &tab[0];
		int beginTime, endTime;
	
	if(dataType == 'a')
	{
		
		
		readTabFromFile(pTab, amount);
		
		beginTime = time(NULL);
		insertionSort(tab, amount);
		endTime = time(NULL);
		
		printf("InsertionSort: %d seconds.\n", endTime - beginTime);
		
		
		
		readTabFromFile(pTab, amount);
		
		beginTime = time(NULL);
		bubbleSort(tab, amount);
		endTime = time(NULL);
		
		printf("BubbleSort: %d seconds.\n", endTime - beginTime);
		
		
		
		readTabFromFile(pTab, amount);
		
		beginTime = time(NULL);
		selectionSort(tab, amount);
		endTime = time(NULL);
		
		printf("SelectionSort: %d seconds.\n", endTime - beginTime);
		
		
		
	}else if(dataType == 'b')
	{

		
		readTabFromFileReverseOrder(pTab, amount);
		
		beginTime = time(NULL);
		insertionSort(tab, amount);
		endTime = time(NULL);
		
		printf("InsertionSort: %d seconds.\n", endTime - beginTime);
		
		
		
		readTabFromFileReverseOrder(pTab, amount);
		
		beginTime = time(NULL);
		bubbleSort(tab, amount);
		endTime = time(NULL);
		
		printf("BubbleSort: %d seconds.\n", endTime - beginTime);
		
		
		
		readTabFromFileReverseOrder(pTab, amount);
		
		beginTime = time(NULL);
		selectionSort(tab, amount);
		endTime = time(NULL);
		
		printf("SelectionSort: %d seconds.\n", endTime - beginTime);
		
		
		
		
	}else if(dataType == 'c')
	{

		readTabFromFileOrder(pTab, amount);
		
		beginTime = time(NULL);
		insertionSort(tab, amount);
		endTime = time(NULL);
		
		printf("InsertionSort: %d seconds.\n", endTime - beginTime);
		
		
		
		readTabFromFileOrder(pTab, amount);
		
		beginTime = time(NULL);
		bubbleSort(tab, amount);
		endTime = time(NULL);
		
		printf("BubbleSort: %d seconds.\n", endTime - beginTime);
		
		
		
		readTabFromFileOrder(pTab, amount);
		
		beginTime = time(NULL);
		selectionSort(tab, amount);
		endTime = time(NULL);
		
		printf("SelectionSort: %d seconds.\n", endTime - beginTime);
	}
}

void groupTwo(int amount, char dataType)
{
	int tab[amount];
	int* pTab = &tab[0];
	int beginTime, endTime;
	printf("group2\n");
	
	if(dataType == 'a')
	{
		
		
		readTabFromFile(pTab, amount);
		
		beginTime = time(NULL);
		quicksort(pTab, 0, amount);
		endTime = time(NULL);
		
		printf("quicksort: %d seconds.\n", endTime - beginTime);
		
		
		
		readTabFromFile(pTab, amount);
		
		beginTime = time(NULL);
		shellSort(tab, amount);
		endTime = time(NULL);
		
		printf("shellsort: %d seconds.\n", endTime - beginTime);
		
		
		
		readTabFromFile(pTab, amount);
		
		beginTime = time(NULL);
		heapSort(tab, amount);
		endTime = time(NULL);
		
		printf("heapsort: %d seconds.\n", endTime - beginTime);
		
		
		
	}else if(dataType == 'b')
	{
		
		readTabFromFileReverseOrder(pTab, amount);
		
		beginTime = time(NULL);
		quicksort(pTab, 0, amount-1);
		endTime = time(NULL);
		
		printf("quicksort: %d seconds.\n", endTime - beginTime);
		
		
		
		readTabFromFileReverseOrder(pTab, amount);
		
		beginTime = time(NULL);
		shellSort(tab, amount);
		endTime = time(NULL);
		
		printf("shellsort: %d seconds.\n", endTime - beginTime);
		
		
		
		readTabFromFileReverseOrder(pTab, amount);
		
		beginTime = time(NULL);
		heapSort(tab, amount);
		endTime = time(NULL);
		
		printf("heapsort: %d seconds.\n", endTime - beginTime);
		
		
		
		
	}else if(dataType == 'c')
	{

		
		readTabFromFileOrder(pTab, amount);
		
		beginTime = time(NULL);
		quicksort(pTab, 0, amount);
		endTime = time(NULL);
		
		printf("quicksort: %d seconds.\n", endTime - beginTime);
		
		
		
		readTabFromFileOrder(pTab, amount);
		
		beginTime = time(NULL);
		shellSort(tab, amount);
		endTime = time(NULL);
		
		printf("shellsort: %d seconds.\n", endTime - beginTime);
		
		
		
		readTabFromFileOrder(pTab, amount);
		
		beginTime = time(NULL);
		heapSort(tab, amount);
		endTime = time(NULL);
		
		printf("heapsort: %d seconds.\n", endTime - beginTime);
	}
}



void generateRandomNumbToText(int amount, int max)
{
	FILE* file = fopen(filePath, "w");
	
	for(int i = 0; i<amount; i++)
	{
		fprintf(file, "%d ", (rand()%max)-100);
	}
	
	fclose(file);
}

void generateOrderNumbToText(int amount)
{
	FILE* file = fopen(filePathOrder, "w");
	int step = 200/amount;
	
	for(int i = 0; i<amount; i++)
	{
		fprintf(file, "%d ", (step * i)-100);
	}
	
}


void readTabFromFile(int *tab, int amount)
{
	FILE* file = fopen(filePath, "r");
	
	if(file==NULL) printf("nullik");
	
	for(int i= 0; i<amount; i++)
	{
		fscanf(file, "%d", (tab+i));
	}
	
	
	fclose(file);
}

void readTabFromFileOrder(int *tab, int amount)
{
	FILE* file = fopen(filePathOrder, "r");
	
	for(int i= 0; i<amount; i++)
	{
		fscanf(file, "%d", (tab+i));
	}
	
	
	fclose(file);
}

void readTabFromFileReverseOrder(int *tab, int amount)
{
	FILE* file = fopen(filePathOrder, "r");
	
	for(int i= 0; i<amount; i++)
	{
		fscanf(file, "%d", (tab + amount - i -1));
	}
	
	
	fclose(file);
}

void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printTab(int tab[], int amount)
{
	for(int i = 0; i < amount; i++)
	{
		printf("%d ", tab[i]);
	}
}

void printTabFromPointer(int* tab, int amount)
{
	for(int i = 0; i < amount; i++)
	{
		printf("%d ", *(tab+i));
	}
}

void bubbleSort(int tab[], int amount)
{
	int sortedBorder = amount -1;
	while(sortedBorder>1)
	{
		for(int i= 0; i < sortedBorder; i++)
		{
			if(tab[i]>tab[i+1])
			{
				swap(&tab[i], &tab[i+1]);
			}
		}
		sortedBorder--;
	}
	
}

void insertionSort(int tab[], int amount)
{
	int i, j, value;
	for(i = 1; i<amount; i++)
	{
		j = i;
		value = tab[i];
		
		while ((j>0) && (tab[j-1]>value))
		{
			tab[j]= tab[j-1];
			j--;
		}
		
		tab[j] = value;
	}
	
}

void selectionSort(int tab[], int amount)
{
	int min;
	
	for(int i = 0; i<amount-1; i++)
	{
		
		min = i;
		
		for(int j = i+1; j < amount; j++)
		{
		
			if(tab[j] <= tab[min])
			{
				min = j;
			}
			
			
		}
		
		swap(&tab[min], &tab[i]);
	}
	
}

void quicksort(int *tab, int start, int end)
{

	
	if(start<end)
	{
		int pi = partitionQS(tab, start, end);
		
		quicksort(tab, start, pi);
		quicksort(tab, pi + 1, end);
	}
	
	//printTabFromPointer(tab, (end-start));
}

int partitionQS(int *tab, int start, int end)
{
	int pivot = *(tab + end - 1);
	int i = start;
	
	for(int j = start; j < end; j++)
	{
		
		if(*(tab + j) < pivot)
		{
		
			swap((tab + i), (tab + j));
			i++;
		}
		
	}
	
	swap((tab+i), (tab + end - 1));
	
	return i;
}

void shellSort(int tab[], int amount)
{
	for(int gap = amount/2; gap>0; gap/=2)
	{
		for(int i = gap; i<amount;i++)
		{
			int temp = tab[i];
			int j; 
			for(j = i; j>=gap && tab[j-gap]>temp; j-=gap)
			{
				tab[j] = tab[j-gap];
			}
			
			tab[j] = temp;
		}
	}
}

void heapify(int tab[], int amount, int i)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;
	
	

	if((l<amount) && (tab[l] > tab[largest]))
	{
		largest = l;
	}
	

	if(r < amount && tab[r] > tab[largest])
	{
		largest = r;
	}
	
	

	if(largest != i)
	{
		swap(&tab[i], &tab[largest]);
		
		heapify(tab, amount, largest);
	}
	
}

void heapSort(int tab[], int amount)
{
	

	for(int i = (amount/2) -1; i>=0; i--)
	{
		heapify(tab, amount, i);
	}
	
	

	for(int i=amount-1; i>=0; i--)
	{
		swap(&tab[0], &tab[i]);

		heapify(tab, i, 0);
	}
}

