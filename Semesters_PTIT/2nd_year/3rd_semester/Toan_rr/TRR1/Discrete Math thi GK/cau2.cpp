#include<bits/stdc++.h>
using namespace std;
int check(int i) {
    int a[10]={0};
    while(i) {
        int d=i%10;
        a[d]++;
        i/=10;
    }
    if(a[2] || a[3] || a[4] || a[6] || a[7]) return 0;
    if(a[0]!=1 || a[1]!=1 || a[5]!=1 || a[8]!=1 || a[9]!=1) return 0;
    return 1;
}
int main() {
    int count=0;
    cout << 4*4*3*2 << endl;
    for(int i=10000; i<=99999; i++) {
        if(check(i)) {
            cout << i << " ";
            count++;
        }
    }
    cout << endl;
    cout << count;
}