#include <stdio.h>
#include<math.h>


int main()
{
    int a[] = {1, 1, 5, 4, 3, 3 ,2 ,2};
    
    int c[] = {0, 0, 0, 0, 0};
    
    int i= 1;
    for(i = 1; i < 6 ; i++)
    {
        int j = 0;
        for(j =0; j<8; j++)
        {
            if(i == a[j])
            {
                c[i-1]++;
            }
        }
    }
    
    for(i = 0; i<5; i++)
    {
        printf("amount of %d: %d\n", i+1, c[i]);
        
    }
}



