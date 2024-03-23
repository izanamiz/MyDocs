#include <iostream>
#include <string>
using namespace std;
struct SinhVien
{
	string MaSo;
	float DiemToan, DiemLy, DiemHoa;
};
typedef struct SinhVien SINHVIEN; // �oi "struct SinhVien" th�nh "SINHVIEN"

void NhapDuLieu(SINHVIEN &);
void XuatSinhVien(SINHVIEN);
float TinhDiemTrungBinh(SINHVIEN);

void NhapDuLieu(SINHVIEN &x) // Ch� �: Phai c� &: Tham chieu.
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
