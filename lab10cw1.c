#include<stdio.h>

int main()
{
	FILE* file1;
	FILE* file2;
	file1 = fopen("macierz1.txt", "r" );
	file2 = fopen("macierz2.txt", "r");
	
	int macierz1[3][3];
	int macierz2[3][3];
	
	int i = 0;
	int j = 0;
	
	int k;
	while( fscanf(file1,"%d", &k) !=EOF)
	{	
		macierz1[i][j] = k;
		j++;
		
		if(j==3)
		{
			i++;
			j=0;
		}
		 	
	}
	fclose(file1);

	i = 0;
        j = 0;
        
       	k=0;
        while( fscanf(file2,"%d", &k) !=EOF)
        {       
                macierz2[i][j] = k;
                j++;
                
                if(j==3)
                {
                        i++;
                        j=0;
                }       
                        
        }
	fclose(file2);

	int macierz3[3][3];

	macierz3[0][0] = macierz1[0][0]*macierz2[0][0] + macierz1[0][1]*macierz2[1][0] + macierz1[0][2] * macierz2[2][0];		
	macierz3[0][1] = macierz1[0][0]*macierz2[1][1] + macierz1[0][1]*macierz2[1][1] + macierz1[0][2] * macierz2[2][1];
	macierz3[0][2] = macierz1[0][0]*macierz2[0][2] + macierz1[0][1]*macierz2[1][2] + macierz1[0][2] * macierz2[2][2];
	
	macierz3[1][0] = macierz1[1][0]*macierz2[0][0] + macierz1[1][1]*macierz2[1][0] + macierz1[1][2] * macierz2[2][0];
	macierz3[1][1] = macierz1[1][0]*macierz2[0][1] + macierz1[1][1]*macierz2[1][1] + macierz1[1][2] * macierz2[2][1];
	macierz3[1][2] = macierz1[1][0]*macierz2[0][2] + macierz1[1][1]*macierz2[1][2] + macierz1[1][2] * macierz2[2][2];
	
	macierz3[2][0] = macierz1[2][0]*macierz2[0][0] + macierz1[2][1]*macierz2[1][0] + macierz1[2][2] * macierz2[2][0];
	macierz3[2][1] = macierz1[2][0]*macierz2[0][1] + macierz1[2][1]*macierz2[1][1] + macierz1[2][2] * macierz2[2][1];
	macierz3[2][2] = macierz1[2][0]*macierz2[0][2] + macierz1[2][1]*macierz2[1][2] + macierz1[2][2] * macierz2[2][2];

	FILE* file3;
	file3 = fopen("macierz3.txt", "w");
	fprintf(file3, "%d, %d, %d \n", macierz3[0][0], macierz3[0][1], macierz3[0][1]);
	fprintf(file3, "%d, %d, %d \n", macierz3[1][0], macierz3[1][1], macierz3[1][1]);
	fprintf(file3, "%d, %d, %d \n", macierz3[2][0], macierz3[2][1], macierz3[2][1]);
	fclose(file3);
}






