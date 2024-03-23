#include <stdio.h>
// nguyên mẫu hàm
void xemmang(int *a,int m, int n);
// void xemmang(int *, int);

int main()
{
    int b[5][10]={4,1,2,3,8,7},m=2,n=3;
    xemmang(b,m,n);
}

void xemmang(int *a[][10],int m, int n)
{
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            printf("%d ", a[i][j]);
    //return ;    
}
