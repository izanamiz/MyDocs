#include<iostream>
using namespace std;

struct PHANSO
{
	int TS;
	int MS;
};

void NhapPS(PHANSO &x)
{
	cin>>x.TS;
	cin>>x.MS;
}

void XuatPS(PHANSO x)
{
	cout<<x.TS<<"/"<<x.MS<<endl;
}

float TongPS(PHANSO x1, PHANSO x2)
{
	int Tu, Mau;
	Tu = x1.TS*x2.MS + x1.MS*x2.TS;
	Mau = x1.MS*x2.MS;
	return (float)Tu/Mau;
}

float HieuPS(PHANSO x1, PHANSO x2)
{
	int Tu, Mau;
	Tu = x1.TS*x2.MS - x1.MS*x2.TS;
	Mau = x1.MS*x2.MS;
	return (float)Tu/Mau;
}

float TichPS(PHANSO x1, PHANSO x2)
{
	int Tu, Mau;
	Tu = x1.TS * x2.TS;
	Mau = x1.MS * x2.MS;
	return (float)Tu/Mau;
}

float ThuongPS(PHANSO x1, PHANSO x2)
{
	int Tu, Mau;
	Tu = x1.TS * x2.MS;
	Mau = x1.MS * x2.TS;
	return (float)Tu/Mau;
}

int main() 
{ 
	PHANSO ps1, ps2;
	NhapPS(ps1);
	NhapPS(ps2);
	XuatPS(ps1);
	XuatPS(ps2);
	
	cout<<TongPS(ps1, ps2)<<endl;
	cout<< HieuPS(ps1, ps2)<<endl;
	cout<<TichPS(ps1, ps2)<<endl;
	cout<<ThuongPS(ps1, ps2)<<endl;

} 
