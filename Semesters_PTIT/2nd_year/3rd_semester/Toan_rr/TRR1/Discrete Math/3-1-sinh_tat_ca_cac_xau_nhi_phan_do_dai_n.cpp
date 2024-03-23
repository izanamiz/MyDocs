#include<bits/stdc++.h>
using namespace std;
int n;
int b[30]={0};
bool OK=false;
void in() {
    for(int i=1; i<=n; i++) cout << b[i] << " ";
    cout << endl;
}
void sinh() {
    int i=n;
    while(b[i]==1) {
        b[i]=0;
        i--;
    }
    if(i==0) OK=true;
    else b[i]=1;
}
int main() {
    cin >> n;
    while(!OK) {
        in();
        sinh();
    }
}