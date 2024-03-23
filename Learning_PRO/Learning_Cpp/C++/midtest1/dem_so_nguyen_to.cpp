#include<iostream>
#include<vector>
using namespace std;

int main(){	
	int n,m; cin>>n>>m;
	if(n==1) n++;
	vector<int> a;
	for(int i=n;i<=m;i++){
		int dd=1;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				dd=0;
				break;
			}
		}
		if(dd==1){
			a.push_back(i);
		}				
	}
	cout<<a.size()<<endl;		
	for(int i=0; i<a.size(); i++)
		cout<<a[i]<<" ";
	
							
}		

