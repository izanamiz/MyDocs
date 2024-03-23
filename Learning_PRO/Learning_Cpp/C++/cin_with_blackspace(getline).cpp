#include <iostream>
#include<string>

using namespace std;

int main()
{
	string Name,Address;
	//cin considers a space (whitespace, tabs, etc) as a terminating character,
	// which means that it can only display a single word (even if you type many words)
	getline(cin,Name);
	getline(cin,Address);
	cout<< "Name: "<<Name;
	cout<< endl<< "Address: "<< Address;
	
	return 0;
}
