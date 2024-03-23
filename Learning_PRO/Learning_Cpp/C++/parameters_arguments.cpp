#include<iostream>
using namespace std;

void myFunction(string fname,int age)
//A parameter with a default value, is often known as an "optional parameter"
//When a parameter is passed to the function, it is called an argument. So, from the example above: 
//fname is a parameter, 
//while Liam, Jenny and Anja are arguments.
{
	cout<<fname<<" Refsnes"<<age<<" years old.\n";
}
//You can also use a default parameter value, by using the equals sign (=).
//If we call the function without an argument, it uses the default value ("Norway"):
void myfunction(string country="Norway")
{
	cout<<country<<endl;
}
int function(int x,int y){
	return x+y;
}
int main()
{
	myFunction("Liam",3);
	myFunction("Jenny",14);
	myFunction("Anja",30);
	
	myfunction("Sweden");
	myfunction("Vietnam");
	myfunction();
	
	int z=function(5,3);
	cout<<function(5,3)<<" "<<z;
	return 0;
}
