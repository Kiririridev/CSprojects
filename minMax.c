
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
    
    int max, min, imax, imin;
    max = a[0];
    min = a[0];
    imax = 0;
    imin = 0;
    i = 1;
    
    for(i = 1; i<n;i++)
    {
        if(a[i]>max)
        {
            max = a[i];
            imax = i;
        } else
        {
            if(a[i]<min)
            {
                min = a[i];
                imin = i;
            }
        }
    }
    
    a[imax] = min;
    a[imin] = max;
    
    i = 0;
    for(i = 0; i<n; i++)
    {
        printf("%d \n", a[i]);
    
    }
}



