#include<iostream>
#include<vector>
using namespace std;
int main(){
	int n,m,i,j;cin>>n>>m;
	vector<int> a;
	vector<int> b;
	for(i=0; i<n; i++)
		cin>>a[i];
	for(i=0; i<m; i++)
		cin>>b[i];

	for(int i=0;i<a.size();i++)	
	{
		int k=0;
		if(a[i]==b[0]){
/*			int pos1=i,pos2=0;
			while(a[pos1]==b[pos2]){
				pos1++;pos2++
			}
			if(pos2==m) a.erase(a.begin()+i,a.begin()i+m);
*/			
			k++;
			int dd=1;
			for(int j=i+1;j<i+b.size();)
			{
				if(a[j]==b[k]){
					j++;k++;
				}else{
					dd==0;
					break;
				}
			}
			if(dd) a.insert(a.begin()+i,m,0);
		}
	}
	for(int i=0;i<a.size();i++){
		if(a[i]==0) a.erase(a.begin()+i);
	}
	for(int i=0;i<a.size();i++)
		cout<<a[i]<<" ";
}
