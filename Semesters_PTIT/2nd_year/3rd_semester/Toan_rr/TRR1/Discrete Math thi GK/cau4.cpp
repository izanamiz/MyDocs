#include<bits/stdc++.h>
using namespace std;
int main() {
    int count1=0, count2=0, count4=0;
    for(int i=4000; i<=5000; i++) {
        if(i%2==0) count1++;
        if(i%5==0) count2++;
        if(i%10==0) count4++;
    }
    int x=count1+count2-count4;
    cout << 1001-x << endl;
    int count=0;
    int dem=0;
    for(int i=4000; i<=5000; i++) {
        if(i%2!=0 && i%5!=0 && i%15!=0) {
            cout << i << " ";
            count++;
            dem++;
            if(dem==10) {
                cout << endl;
                dem=0;
            }
        }
    }
    cout << count;
}