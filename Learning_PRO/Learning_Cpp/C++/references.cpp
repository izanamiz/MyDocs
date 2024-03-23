#include <iostream>
#include <string>
using namespace std;

int main() {
  string food = "Pizza";
  string &meal = food;

  cout << food << "\n";
  cout << meal << "\n";
  cout<<&food<<endl;//Get the memory address of the food variable
  string* ptr=&food; cout<<ptr;//Create a pointer variable with the name ptr, that should point to a string variable named food
  return 0;
}

