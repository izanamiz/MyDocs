#include<bits/stdc++.h>
using namespace std;
int n, dem=0;
int check(string s) {
    for(int i=0; i<s.size()-1; i++) {
        if(s[i]=='1' && s[i+1]=='1') return 0;
    }
    return 1;
}
void Try(string s) {
    if(s.size()==n) {
        if(check(s)) {
            dem++;
            for(int i=0; i<s.size(); i++) {
                cout << s[i] << " ";
            }
            cout << endl;
        }
    }
    else {
        Try(s+"0");
        Try(s+"1");
    }
}
int main() {
    cin >> n;
    int xn, x1=2, x2=3;
    for(int i=3; i<=n; i++) {
        xn=x1+x2;
        x1=x2;
        x2=xn;
    }
    cout << xn << endl;
    Try("");
    cout << dem;
}