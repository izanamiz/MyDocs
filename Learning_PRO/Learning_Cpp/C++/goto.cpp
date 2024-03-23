#include <bits/stdc++.h>
using namespace std;
int main()
{	
	for(int i=0 ; i<10 ; i++)
	{
		cout<<i<<" ";
		if(i==5)
			goto print;
 }
	print: //nhãn print
		cout<<"Hello world";
	return 0;
}
