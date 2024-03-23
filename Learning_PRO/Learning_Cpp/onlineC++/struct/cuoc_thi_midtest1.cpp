#include<iostream>
#include<string>
#include<vector>
using namespace std;
struct student
{
	string name;
	int toan;
	int li;
	int tin;	
};

int main(){
	vector<student> v;
	int n;cin>>n;
	cin.ignore();
	student hs[100];
	for(int i=0; i<n; i++){
		getline(cin,hs[i].name);		
	}
	for(int i=0; i<n; i++){
		cin>>hs[i].toan;		
	}
	for(int i=0; i<n; i++){
		cin>>hs[i].li;		
	}
	for(int i=0; i<n; i++){
		cin>>hs[i].tin;		
	}		
	
	
	vector<int> diem;
	int max=0;
	for(int i=0; i<n; i++){
		int x=hs[i].toan+hs[i].li+hs[i].tin;
		diem.push_back(x);
		if(diem[i]>=max) max=diem[i];
	}
	for(int i=0; i<n; i++){
		if(diem[i]==max) 
			cout<<hs[i].name<<" "<<hs[i].toan<<" "<<hs[i].li<<" "<<hs[i].tin<<endl;
	}
	
}
