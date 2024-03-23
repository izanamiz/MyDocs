
#include <iostream>
#include<string>
using namespace std;
void substr(string str)
{
	 // Tra ve chuoi con tu chi so thu 3 toi cuoi chuoi.
   string substr = str.substr(3);
 
   cout << "- str.substr(3)=" << substr << endl;
 
  
   // Tra ve chuoi con tu chi so thu 2 do dai 7
   substr = str.substr(2, 7);
   cout << "- str.substr(2, 7) =" << substr << endl;
   cout << string(str.begin()+2, str.begin()+2+7); 
   
}
void find(string str)
{
	// Tìm vi tri xuat hien ky tu 'i' tiên.
   // ==> 2
   size_t idx = str.find('i');	
   //  string::size_type idx = str.find('i');
 
   cout << "- find('i') = " << idx << endl;
 
  
   // Tìm vi tri xuat hien 'i' dau tiên
   // tính tu chi so thu 4 tro ve cua chuoi.
   // ==> 5
   idx = str.find('i', 4);
   cout << "- find('i',4) = " << idx << endl;
 
  
   // Tìm vi tri xuat hien chuoi con "te" tiên.
   // ==> 8
   idx = str.find("te");
   cout << "- find('te') = " << idx << endl;
}
 
int main() {
 
    string str = "This is text";
    cout<<str<<'\n';
    cout<<"012345678901"<<'\n';
	find(str);
	substr(str);
	   
 
}

