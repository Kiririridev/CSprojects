#include<stdio.h>

/*
We have comparison of different ways to search element in array.
First function is simple search without guardian on unsorted array.
Seconds one is search with guardian on unsorted array.
Third one is search without guardian on unsorted array.
Fourth one is search with guardian on sorted array.

Adding guardian at the end of array allows us to not check for it on every iteration,
so functions without guardian does "twice as much minus one" operations.

Fact that array is sorted only helps us if the element is not in array, because
when we spot element that is bigger we can stop searching and it only costs us
one additional operation.


*/

int szuk(int x, int n, int *a)
{
	int i = 0;
	while(i<n && x!=a[i]) i++;
	return i;
}

int szuk_wart(int x, int n, int *a)
{
	int i = 0;
	a[n] = x;
	while(x!=a[i]) i++;
	return i;
}

int szuk_sort(int x, int n, int *a)
{
	int i = 0;
	while(i<n && x>a[i]) i++;
	if(a[i]==x) return i;
	return n;
}

int szuk_sort_wart(int x, int n, int *a)
{
	int i = 0;
	a[n] = x;
	while(x>a[i]) i++;
	if(a[i]!=x) return n;
	return i;
}

int main(){}
