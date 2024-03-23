#include <stdio.h>
#include <malloc.h>
void xemmang(int **a, int m, int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
            printf("%d ", a[i][j]);
        printf("\n");    
    }
        
    //return ;    
}

int main()
{
    int m=2,n=3;
    int **b;
    b =(int **) malloc(m*sizeof(int *));
    for(int i=0; i<2; i++)
        b[i] = (int *) malloc(n * sizeof(int)*3);
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            b[i][j]=i*n+j; 

    xemmang(b,m,n);
}


