#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

int main(){
	string s;
	getline(cin,s);
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	sort(s.begin(), s.end());
	int k=0;
	while(s[k]==' ') k++;
	int i=k;
	while(i<s.length())
	{
		int count=1;
		int j;
		for(j=i+1; j<s.length(); j++ ){
			if(s[i]==s[j])
				count++;
		}
		cout<<s[i]<<" "<<count<<endl;	
		i=i+count;			
	}
}
