#include<bits/stdc++.h>
using namespace std;
int n;
int a[30];
int xuoi[60];
int nguoc[60];
int cot[30];
void in() {
    for(int i=1; i<=n; i++) cout << a[i] << " ";
    cout << endl;
}
void Try(int i) {
    for(int j=1; j<=n; j++) {
        if(!cot[j] && !xuoi[i-j+n] && !nguoc[i+j-1]) {
            a[i]=j;
            cot[j]=1;
            xuoi[i-j+n]=1;
            nguoc[i+j-1]=1;
            if(i==n) in();
            else Try(i+1);
            cot[j]=0;
            xuoi[i-j+n]=0;
            nguoc[i+j-1]=0;
        }
    }
}
int main() {
    cin >> n;
    for(int i=0; i<=n; i++) {
        a[i]=0;
        cot[i]=0;
    }
    for(int i=0; i<2*n-1; i++) {
        xuoi[i]=0;
        nguoc[i]=0;
    }
    Try(1);
}