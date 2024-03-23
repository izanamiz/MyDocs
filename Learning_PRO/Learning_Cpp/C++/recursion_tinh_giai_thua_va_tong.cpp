//1 ham duoc goi la de quy neu ben trong than ham 
//co 1 loi goi den chinh no
#include<iostream>
using namespace std;
//tinh n!
long long factor(int n){//
	if( n==0 || n==1)// dieu kien dung(dieu kien co so): diem neo,khi dat toi diem neo(1 gia tri cuc tieu), 
	//ham se khong goi chinh no nua-> ham cham dut
		return 1;
	else return n*factor(n-1);
}//giai thich voi n=5
/*GiaiThua(5) 
   GiaiThua(4) 
      GiaiThua(3) 
         GiaiThua(2) 
            GiaiThua(1) 
               return 1 
            return 2*1 = 2 
         return 3*2 = 6 
      return 4*6 = 24 
   return 5*24 = 120*/

long sumFrom1toN(int n){
	if(n==1)//if(n == 0)
		return 1;// return 0;
	else return n+sumFrom1toN(n-1);	
}
int fibonacci(int number){
	if(number==0) return 0;
	if(number==1) return 1;
	return fibonacci(number-1)+fibonacci(number-2);
}
int main(){
	cout<<" Sum of numbers from 1 to 10: "<<sumFrom1toN(10)<<endl;
	cout<<"49!= "<<factor(49);
	cout<<endl<<"15 so fibonacci dau tien la: ";
	for(int count =0;count<15;count++)
		cout<<fibonacci(count)<<" ";
}
