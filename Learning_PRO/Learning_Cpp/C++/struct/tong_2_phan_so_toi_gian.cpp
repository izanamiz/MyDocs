
#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
 
struct phanso
{
    int tu;
    int mau;
};
 
phanso a,b, tong;
 
void nhapdl()
{
    cin >>a.tu >> a.mau;
    cin >>b.tu >> b.mau;
}
 
int ucln(int a, int b)
{
    while (a*b!=0)
    {
        if(a>b) a%=b;
    	else b%=a;
    }
    return a+b;
}
 
int main( )
{
    nhapdl();
    if (a.mau==0 || b.mau==0)
    {
        cout << "-1";
        return 0;
    }
 
    tong.tu = a.tu*b.mau + a.mau*b.tu;
    tong.mau = a.mau*b.mau;
 
    int UC = ucln(tong.tu,tong.mau);
    cout << tong.tu/UC << "/"<< tong.mau/UC;
}
