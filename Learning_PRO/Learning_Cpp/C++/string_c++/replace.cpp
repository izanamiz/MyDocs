#include <iostream>
using namespace std;
 
int main() {
 
   string str = "This is text";
 
   // Thay the cac chuoi con 4 ky tu bat dau tu vi tri 8
   // boi chuoi "string", và tra ve tham chieu
   string s2 = str.replace(8, 4, "string");
 
   cout << "- str=" << str << endl; // This is string
   cout << "- s2=" << s2 << endl;   // This is string
   cout << " -------------- " << endl;
 
   // xet lai str
   str = "This is text";
 
   // thay the chuoi con 4 ky tu bat dau tu chi so 8, boi 1 chuoi con cua
   // 1 chuoi con khac, 6 ky tu bat dau tu chi so 0.
   // ==> It is string
   string s3 = str.replace(8, 4, "string is important", 0, 6);
 
   cout << "- str=" << str << endl; // This is string
   cout << "- s3=" + s3 << endl;    // This is string
   cout << " -------------- " << endl;
 
}
