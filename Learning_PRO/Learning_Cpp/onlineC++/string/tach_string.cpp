#include<iostream>
#include<string>
#include<vector>

using namespace std;
vector<string> split(string s, char sub){
	vector<string> RES;
	string res="";
	int j=0;
	while(s[j]==sub) j++;
	for(int i=j; i<s.length(); i++){
		if(s[i]==sub && s[i-1]!=sub){
			RES.push_back(res);
			res="";
		}else if(s[i]!=sub){
			res+=s[i];
		}
	}
	if(res!="") RES.push_back(res);
	return RES;
}

int main()
{
	string s= "ProPTIT nam nay la sinh nhat 10 tuoi";
// 1. ProPTIT Nam Nay La Sinh Nhat 10 Tuoi	
// 2. tuoi 10 nhat sinh la nay nam ProPTIT	
 	vector<string> a,b;
 	a=split(s, ' ');
 	for(int i=0;i<a.size();i++){
 		string c=a[i];
 		for(int i=0; i<c.length();i++){
 			
		}
	 }
 	int len=a.size();
 	for(int i=0;i<len-1; i++) 
 		b.push_back(a[i]+" ");
 	b.push_back(a[len-1]);
	return 0;
	
}
