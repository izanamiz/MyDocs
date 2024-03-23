#include <iostream>
#include <string>
using namespace std;
struct SinhVien
{
	string MaSo;
	float DiemToan, DiemLy, DiemHoa;
};
typedef struct SinhVien SINHVIEN; // Ðoi "struct SinhVien" thành "SINHVIEN"

void NhapDuLieu(SINHVIEN &);
void XuatSinhVien(SINHVIEN);
float TinhDiemTrungBinh(SINHVIEN);

void NhapDuLieu(SINHVIEN &x) // Chú ý: Phai có &: Tham chieu.
{
	cin.ignore();
	getline(cin,MaSo);
	cin>>x.DiemToan);
	cin>>x.DiemLy);
	cin>>x.DiemHoa);
}

void XuatSinhVien(SINHVIEN x)
{
	cout<<'\n'<<x.MaSo;
	cout<<"\n"<<x.DiemToan);
	cout<<endl<<x.DiemLy);
	pcout<<endl<<x.DiemHoa);
	cout<<endl<<TinhDiemTrungBinh(x));
}

float TinhDiemTrungBinh(SINHVIEN x)
{
	return (x.DiemToan + x.DiemLy + x.DiemHoa) / 3;
}

int main()
{
	SINHVIEN x;
	NhapDuLieu(x);
	XuatSinhVien(x);
	return 0;
}
