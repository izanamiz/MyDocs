#include<bits/stdc++.h>
using namespace std;
int main() {
    int count=0;
    for(int x1=5; x1<=6; x1++) {
        for(int x2=6; x2<=8; x2++) {
            for(int x3=0; x3<=15-(x1+x2); x3++) {
                for(int x4=0; x4<=15-(x1+x2+x3); x4++) {
                    for(int x5=0; x5<=15-(x1+x2-x3-x4); x5++) {
                        int x6=15-(x1+x2+x3+x4+x5);
                        if(x6>=0) count++;
                    }
                }
            }
        }
    }
    cout << count << endl;
    for(int x1=5; x1<=6; x1++) {
        for(int x2=6; x2<=8; x2++) {
            for(int x3=0; x3<=15-(x1+x2); x3++) {
                for(int x4=0; x4<=15-(x1+x2+x3); x4++) {
                    for(int x5=0; x5<=15-(x1+x2-x3-x4); x5++) {
                        int x6=15-(x1+x2+x3+x4+x5);
                        if(x6>=0) cout << x1 << " " << x2 << " " << x3 << " " <<x4 << " " <<x5 << " " <<x6 << endl;
                    }
                }
            }
        }
    }
    cout << count << endl;
}