#include<iostream>
typedef long long ll;
using namespace std;
//nhap vao kich thuoc 2 hinh chu nhat
//so sanh dien tich cua 2 hcn
struct hcn
{
	ll CD;
	ll CR;
};

void nhap(hcn &x)
{
	cin>>x.CD;
	cin>>x.CR;
}
ll xuat(hcn h1, hcn h2)
{
	ll s1=h1.CD*h1.CR;
	ll s2=h2.CD*h2.CR;
	if(s1>s2) return s1;
	else return s2;
}
int main()
{
	hcn h1,h2;
	nhap(h1);
	nhap(h2);
	cout<<xuat(h1,h2);
}
