
#include<iostream>
#include<vector>

using namespace std;

int main(){
	int a[20][30];	// Khai bao ma tran
	int i,j,cot,hang;
	cout<<"Nhap so hang, so cot cua ma tran: ";
	cin>>hang>>cot;
	for(i=0;i<hang;i++){
		for(j=0;j<cot;j++){
			cout<<"a["<<i<<"]["<<j<<"]=";
			cin>>a[i][j];
		}
	}
	cout<<"\nMa tran vua nhap la: "<<endl;
	for(i=0;i<hang;i++){
		for(j=0;j<cot;j++)
			cout<<a[i][j]<<" ";
		cout<<endl;	
	}
	
return 0;				
}
