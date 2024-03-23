#include<iostream>
typedef long long ll;
using namespace std;
//nhap vao kich thuoc 2 hinh chu nhat
//so sanh dien tich cua 2 hcn
struct hcn
{
	ll CD;
	ll CR;
	ll S;
};
hcn area(hcn &x)
{
	x.S = x.CD * x.CR;
}
int main()
{
//	hcn HCN[2];
//	cin>> HCN[0].CD >> HCN[0].CR;
//	cin>> HCN[1].CD >> HCN[1].CR;	
//	HCN[0].S = HCN[0].CD * HCN[0].CR;
//	HCN[1].S = HCN[1].CD * HCN[1].CR;
//	if(HCN[0].S > HCN[1].S) cout << HCN[0].S;
//	else cout << HCN[1].S;
	hcn h1,h2;
	cin>> h1.CD >> h1.CR;
	cin>> h2.CD >> h2.CR;
	area(h1);
	area(h2);
}
