#include <iostream>
#include <string>
using namespace std;
void insert(string str){
	string istr = "them";
    cout<<str<<endl;
    str.insert(8, istr);
    cout << str << endl;	
}
void erase(string str)
{
	//  str.erase(int pos, int n);
	// xoa n ky tu cua chuoi ke tu vi tri pos
	// neu k quy dinh n thi tat ca ky tu cua str tu pos tro di se bi xoa  
	cout<<'\n'<<str<<endl;
	
	str.erase(0, 3); // " cung la xau thu"
    cout << str << endl;
    str.erase(6, 2);
    cout << str << endl; // " cung xau thu"
    getchar();
}
int main ()
{
    insert("day la .. xau thu");
    erase("day cung la xau thu");
    
    return 0;
}
