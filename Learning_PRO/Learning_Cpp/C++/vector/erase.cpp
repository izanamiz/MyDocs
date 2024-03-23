
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void inday(vector<int > A, string tbao)
{
	cout<< tbao <<endl;
	for(int i=0;i<A.size();i++)
		cout<<A[i]<<" ";
}
int main(){
	vector<int> v;
	for(int i=1;i<10;i++)
		v.push_back(i);
	inday(v,"Day ban dau: ");
	v.erase(v.begin());		// Xoa phan tu dau tien
	inday(v,"\nDay da xoa phan tu dau tien: ");
	v.erase(v.end()-3, v.end()); 		// Xoa 3 phan tu cuoi
	inday(v, "\nXoa 3 phan tu cuoi: ");
	
return 0;				
}
