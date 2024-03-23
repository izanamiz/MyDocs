#include <iostream>
#include <vector>
using namespace std;
 
int main(){
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i<n; i++) cin >> a[i];
    for(int i = 0; i<m; i++) cin >> b[i];
    vector<int> c;
    for(int i = 0; i<n; i++){
        c.push_back(a[i]);
        if((c.size()<b.size() && c[0] != b[0]) || i == a.size()-1){
            cout << a[i] << " ";
            c.clear();
        }
        if(c.size() == b.size()){
            if(b == c) c.clear();
            else {
                for(int j = 0; j<c.size(); j++){
                    cout << c[j] << " ";
                }
                c.clear();
            }
        }
    }
    return 0;
}
