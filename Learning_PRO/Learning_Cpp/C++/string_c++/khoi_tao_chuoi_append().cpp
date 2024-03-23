#include<iostream>
#include<string>
using namespace std;
void append(string s1, string s2, string s3){
	  cout <<"\n ------------ " ;
	  cout << '\n'<<"s1 = " + s1 << endl;
      cout << "s2 = " + s2 << endl;
      cout << "s3 = " + s3 << endl;
      cout << " ------------ " << endl;
 
      // Noi thêm s2 vào s1.
      // Làm thay doi s1 ova tra ve tham chieu cua s1.
      string s = s1.append(s2);
 
 
      cout << "s1 = " + s1 << endl; // ==> OneTwo
      cout << "s = " + s << endl;   // ==> OneTwo
 
      cout << " ------------ " << endl;
 
      // Noi s2 và s3 vào s1.
      // Làm thay doi s1 và tra ve tham chieu cua s1.
      s = s1.append(s2).append(s3); // ==> OneTwoTwoThree
 
      cout << "s1.append(s2).append(s3) = " + s << endl;
 
}
int main(){
//khai bao 1 chuoi ky tu
	string s0("");//khoi tao chuoi s0 rong
	string s1("tran ");
	string s2{"van "};
	string s3="anh";

	cout<<s0<<endl<<s1;
	cout<<endl<<s2<<endl<<s3;
	
	string s4=s1+s2+s3;
	cout<<endl<<s4;
	cout<<'\n'<<s1.append(s2).append(s3);
	
	append("one","two","three");
}
