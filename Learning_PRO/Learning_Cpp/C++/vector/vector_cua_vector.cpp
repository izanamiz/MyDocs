#include<iostream>
#include<vector>
using namespace std;
int main(){
	int i,j,cot,hang;
	cout<<"Nhap so hang, so cot cua ma tran: ";
	cin>>hang>>cot;
	vector<vector<int>> a(hang,vector<int>(cot));	//Khai bao ma tranj
	for(i=0;i<hang;i++)
		for(j=0;j<cot;j++){
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[i][j];
		}

	cout<<"\nMa tran vua nhap la: "<<endl;
	for(i=0;i<hang;i++){
		for(j=0;j<cot;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;	
	}
	
return 0;				
}
