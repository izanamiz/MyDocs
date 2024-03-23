#include<bits/stdc++.h>
using namespace std;
int a[30], n;
bool ok=false;
void in() {
    for(int i=1; i<=n; i++) cout << a[i] << " ";
    cout << endl;
}
void sinh() {
    int i=n-1;
    while(a[i]>a[i+1]) i--;
    if(i==0) ok=true;
    else {
        int j=n;
        while(a[j]<a[i]) j--;
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
        int d=i+1;
        int c=n;
        while(d<c) {
            t=a[d];
            a[d]=a[c];
            a[c]=t;
            d++;
            c--;
        }
    }
}
int main() {
    cin >>  n;
    for(int i=1; i<=n; i++) a[i]=i;
    while(!ok) {
        in();
        sinh();
    }
}