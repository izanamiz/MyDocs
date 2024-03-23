	//vector<kieu du lieu> ten;
#include<iostream>
#include<vector>
using namespace std;
int main(){
//	int n;cin>>n;
//	vector<int> a;
	//nhap n, sau do co n phan tu
	vector<int> a;//(n,6);//mang gom n phan tu co gia tri bang 6
	cout<<a.max_size()<<endl;
	a.resize(6,6);
//	a.resize(7,7);// kiem tra phan tu thu 7 chua duoc khai bao => 7
	//6 6 6 6 6 6 7
	a.clear();
	cout<<a.size()<<endl;
	a.resize(7,7); // 7 7 7 7 7 7 7
//	for(int i=0;i<n;i++)
//	{
//		int x;cin>>x;
//		a.push_back(x);
//	}
	cout<<a[-3]<<endl;
	for(int i=0;i<a.size();i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
