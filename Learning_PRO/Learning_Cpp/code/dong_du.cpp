#include <iostream>

using namespace std; 

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string n;
		cin>>n;
		cout<<( n%4==0 ? 4 : 0 ) << endl;

	}
}
