
#include <stdio.h>
#include<math.h>


int main()
{
    int n;
    scanf("%d", &n);
    
    int a[n];
    int i = 0;
    for(i = 0; i<n; i++)
    {
        scanf("%d", &a[i]);
        printf("\n");
    }
    
    int sum;
    float average;
    sum = 0;
    
    i = 0;
    for(int i = 0; i<n;i++)
    {
        sum+=a[i];
    }
    
    average = sum/n;
    
    printf("Sum: %d,  Average: %f", sum, average);
}



