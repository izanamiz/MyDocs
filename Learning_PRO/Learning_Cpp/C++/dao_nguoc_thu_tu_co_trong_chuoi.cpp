#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string> Reverse(string s)
{
	string a="";
	vector<string> v;
	int len=s.size();
	int i=len-1,j;
 	for(;i>=0; i--)
	{
		if(s[i]!=' ')
		{
			for(j=i; j>=0; j--)
			{
	 			if(s[j]==' ')
	 			{
	 				for(int k=j+1; k<=i; k++)
	 					a+=s[k];
	 				v.push_back(a+" ");	
	 				a="";
				}	
				if(j==0){
				 	for(int k=j; k<=i;k++)
	 					a+=s[k];
	 				v.push_back(a);	
				}			
		 	}
		}
		i=j;
 		
	} 
	return v;
}
int main()
{
	string s;	
	getline(cin,s);
	
	vector<string> b;	
 	b=Reverse(s);
 	for(int i=0; i<b.size(); i++)
 		cout<<b[i];

	return 0;
	
}
