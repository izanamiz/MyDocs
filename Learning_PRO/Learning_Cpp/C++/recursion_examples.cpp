#include<iostream>
using namespace std;
void countDown(int count){
	cout<<"push "<<count<<endl;
	if( count >1) countDown(count-1);
	cout<<"pop "<<count<<endl;
}//giai thich
/*
nguyen li hoat dong cua stack la LIFO(last in -first out)
khi 1 bien duoc khai bao trong ham, no se duoc day vao(push) stack
khi ham ket thuc thi no se duoc day ra(pop)
*/
int fibonacci(int number){
	if(number==0) return 0;//dieu kien dung(dieu kien co so)
	if(number==1) return 1;
	return fibonacci(number-1)+fibonacci(number-2);
}

int main(){
	countDown(3);
	cout<<endl<<"15 so fibonacci dau tien la: ";	
	for(int count =0;count<15;count++)
		cout<<fibonacci(count)<<" ";	
	return 0;
}
