#include <stdio.h>
#define ll long long
#include <malloc.h>
// void nhap(int a[], int *pn)
// {
//     scanf("%d",pn);
//     for(int i=0; i<*pn; i++) scanf("%d",&a[i]);
// }
// void xuat(int a[],int n)
// {
//     for(int i=0; i<n; i++) printf("%d ",a[i]);
// }
void nhap(int *a, int *pn)
{
    scanf("%d",pn);
    for(int i=0; i<*pn; i++,++a) 
        scanf("%d",a);

}
void xuat(int *a,int n)
{
    for(int i=0; i<n; i++,++a) 
        printf("%d ",*a);
}
int main()
{
    //int b[30],n;
    int *b, n,m;
    scanf("%d",&m);
    b = (int *)malloc(m*sizeof(int)); // int b[m];
    nhap(b,&n);
    xuat(b,n);

}