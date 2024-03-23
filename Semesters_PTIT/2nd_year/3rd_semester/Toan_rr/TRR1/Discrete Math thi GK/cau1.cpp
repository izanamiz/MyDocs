#include<bits/stdc++.h>
using namespace std;
int n=4;
string l;
bool check=true;
void thu() {
    int i=n-1;
    while(i>=0 && l[i]!='0'){
        l[i]='0';
        i--;
    }
    if (i>=0){
        l[i]='1';
	}
    else check=false;
}
main() {
    int a[4];
    int x1,x2,x3;
    for(int i=0;i<n;i++) {
        l[i]='0';
    }
    while(check==true){
        for(int i=0;i<n;i++) {
            if(l[i]=='1') a[i]=1;
            else a[i]=0;
        }
        if(a[0]==1 && a[1]==0){
        	x1=0;
		}
        else x1=1;
        if(a[2]==a[3]){
        	x2=1;
		}
        else x2=0;
        if(x1==1 && x2==1){
        	x3=1;
		}
        else x3=0;
        if (x3==0 && a[0]==1){
        	cout << "F"<<endl;
		}
        else cout<<"T"<<endl;
        thu();
    }
}