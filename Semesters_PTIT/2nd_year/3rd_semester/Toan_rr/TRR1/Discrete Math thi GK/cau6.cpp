#include<iostream>
using namespace std;
int n, k, a[100], OK = 1;
void khoitao() {
    for(int i = 1; i <= k ; i++) cin >> a[i];
}

void sinh() {
    int i = k;
    while(i >= 1 && a[i] == n - k + i) i--;
    if(i==0) OK = 0;
    else {
        a[i]++;
        for(int j = i + 1; j <= k; j++) a[j] = a[j-1] + 1;
    }
}
int main() {
    cin >> k >> n;
    khoitao();
    int dem = 0;
    while(OK) {
        sinh();
        dem++;
        for(int j = 1; j <= k; j++) cout << a[j] << " ";
        cout << endl;
        if(dem == 5) return 0;
    }
}
