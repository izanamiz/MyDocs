#include<iostream>
using namespace std;
void swapNums2(int &x, int &y)//kieu tham chieu
{
	int z=x;x=y;y=z;
}
void swapNums1(int x, int y)//kieu tham chieu
{
	int z=x;x=y;y=z;
}

int main(){
	int firstNum=10;
	int secNum=20;
	cout<<"Before swap: "<<endl;
	cout<<firstNum<<" "<<secNum<<endl;
// Call the function, which will change the values of firstNum and secondNum
  swapNums1(firstNum, secNum);
  cout << "After swap1: " << "\n";
  cout << firstNum << " "<<secNum << "\n";
  
  swapNums2(firstNum,secNum);
  cout << "After swap2: " << "\n";
  cout << firstNum << " "<<secNum << "\n";  
  

}
