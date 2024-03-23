#include<bits/stdc++.h>

using namespace std;
int main(){
	int n;cin>>n;
	cin.ignore();
	vector<string> ten;
	string name;
	for(int i=0; i<n; i++){
		getline(cin,name);
		ten.push_back(name);
	}
		
	vector<int> toan;
	for(int i=0; i<n; i++){
		int math;cin>>math;
		toan.push_back(math);
	}
		
	vector<int> li;
	for(int i=0; i<n; i++){
		int phy;cin>>phy;
		li.push_back(phy);
	}
	
	vector<int> tin;
	for(int i=0; i<n; i++){
		int c;cin>>c;
		tin.push_back(c);
	}	
			
	vector<int> diem;	
	int max=INT_MIN;
	for(int i=0; i<n; i++){
		int x=toan[i]+li[i]+tin[i];
		diem.push_back(x);
		if(diem[i]>=max) max=diem[i];
	
	}
		
	for(int i=0; i<n; i++){
		if(diem[i]==max){
			cout<<ten[i]<<" "<<toan[i]<<" "<<li[i]<<" "<<tin[i];
			cout<<endl;
		}
	}	

}

