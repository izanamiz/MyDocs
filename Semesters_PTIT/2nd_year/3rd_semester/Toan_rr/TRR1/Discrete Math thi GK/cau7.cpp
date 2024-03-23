#include<bits/stdc++.h>
using namespace std;
int a[30],b[30],n,dem=0,check;
void sinh() {
    int i=n-1;
    while(i>0 && a[i] > a[i+1]) i--;
    if(i == 0) check = 0;
    else {
        int j = n;
        while(a[i] > a[j])
        j--;
        swap(a[i],a[j]);
        reverse(a+i+1,a+n+1);
    }
}
int main() {
    cin >> n;
    for(int i = 1; i <= n; i++)
    cin >> a[i];
    check = 1;
    while(check) {
        sinh();
        dem++;
        for(int i = 1; i <= n; i++)
        cout << a[i] << " ";
        cout << endl;
        if(dem == 5) break;
    }
}
