#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define filePath "randomNumbers.txt"
#define amountOfNumbers 100000
#define testAmount 10

void generateRandomNumbToText(int amount, int max);
void swap(int* a, int *b);
void bubbleSort(int tab[], int amount);
void printTab(int tab[], int amount);
void printTabFromPointer(int* tab, int amount);
void readTabFromFile(int *tab, int amount);

void insertionort(int tab[], int amount);
void selectionort(int tab[], int amount);
void quicksort(int* tab, int start, int end);
int partitionQS(int* tab, int start, int end);
void shellSort(int tab[], int amount);

void heapify(int tab[], int amount, int i);
void heapSort(int tab[], int amount);


int main()
{
	srand(time(NULL));
	
	//generateRandomNumbToText(amountOfNumbers, 1000);
	
	int testTab[testAmount] = {2, 5 , 5, 7, 4, 7, 1, 9, 2, 8};
	int* pTestTab = &testTab[0];
	
	int tab[amountOfNumbers];
	int *pTab = &tab[0];
	readTabFromFile(pTab, amountOfNumbers);
	
	//printTab(tab, amountOfNumbers);
	
	//bubbleSort(tab, amountOfNumbers);
	//insertionSort(tab, amountOfNumbers);
	//selectionSort(tab, amountOfNumbers);
	
	//quicksort(pTestTab, 0, testAmount);
	
	//shellSort(testTab, testAmount);
	
	heapSort(testTab, testAmount);
	printTabFromPointer(pTestTab, testAmount);
	
	
}

void generateRandomNumbToText(int amount, int max)
{
	FILE* file = fopen(filePath, "w");
	
	for(int i = 0; i<amount; i++)
	{
		fprintf(file, "%d ", (rand()%max));
	}
	
	fclose(file);
}

void readTabFromFile(int *tab, int amount)
{
	FILE* file = fopen(filePath, "r");
	
	for(int i= 0; i<amount; i++)
	{
		fscanf(file, "%d", (tab+i));
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
	
	printTab(tab, amount);
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
	
	printTab(tab, amount);
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
	
	printTab(tab, amount);
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
