#include<iostream>
#include<string>

using namespace std;

int main(){
	string s;
	getline(cin,s);
	
	for(int i=2; i<s.length(); i++)
	{
		if(i==2 || i==3) s[i]='*';
		int dd=1;
		for(int j=2; j*j<=i; j++)
		{
			for(int j=2;j*j<=i;j++)
			{
				if(i%j==0){
					dd=0;
					break;
				}
			}
			if(dd==1)
				s[i]='*';
		}				
	}
	cout<<s;
}
	
