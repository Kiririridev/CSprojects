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
    
    int max, min;
    max = a[0];
    min = a[0];
    i = 1;
    
    for(i = 1; i<n;i++)
    {
        if(a[i]>max)
        {
            max = a[i];
        } else
        {
            if(a[i]<min)
            {
                min = a[i];
            }
        }
    }
    
    printf("Min: %d, max: %d.", min, max);
}



