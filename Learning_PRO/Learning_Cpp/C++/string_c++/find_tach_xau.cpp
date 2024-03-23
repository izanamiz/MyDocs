// find(vi_tri_dau, vi_tri_cuoi, ky_tu_tim) dung de tim vi tri dau tien cua ky_tu_tim
// tra ve vi tri cua ky_tu_tim neu tim thay, vi tri cuoi neu k tim thay
//
// string co the khoi tao tu 1 doan ky tu con cua 1 xau ky tu khac voi cu phap
// string(vi_tri_dau, vi_tri_cuoi)
#include <bits/stdc++.h>
using namespace std;

int main() {
	// khoi tao gia tri cua xau
	string S = "Xin chao tat ca cac ban"; 

	string::iterator t, t2; // cac bien lap
	vector<string> split; //mang tach xau(luu kq tach)
	
	for (t=S.begin(); t<S.end();)
	{
	    // Lap tu vi tri bat dau
	    t2=find(t, S.end(), ' ' ); // TÌm ký tu space ' ' dau tiên
	    // ke tu vi tri t
	    if (t!=t2) split.push_back(string(t, t2)); // Lay xau ky tu giua trí
	    t = t2+1; // Chuyen sang vi tri sau
	}
	for (int i=0; i<split.size(); i++)
		cout << split[i] << endl; // In mang cac xau ky tu
	getchar();
	   
 
}

