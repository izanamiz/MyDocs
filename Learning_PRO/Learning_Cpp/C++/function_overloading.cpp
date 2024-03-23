#include<iostream>
using namespace std;
//Instead of defining two functions that should do the same thing, it is better to overload one.
//In the example below, we overload the plusFunc function to work for both int and double:
int plusFunc(int x, int y) {
  return x + y;
}
/*instead of
int plusFuncInt(int x, int y) {
  return x + y;
}*/

double plusFunc(double x, double y) {
  return x + y;
}
/*instead of
double plusFuncDouble(double x, double y) {
  return x + y;
}*/

int main() {
  int myNum1 = plusFunc(8, 5);
  double myNum2 = plusFunc(4.3, 6.26);//double myNum2 = plusFunc(8, 5);
  cout << "Int: " << myNum1 << "\n";
  cout << "Double: " << myNum2;
  return 0;
}//Multiple functions can have the same name as long as the number and/or type of parameters are different.
