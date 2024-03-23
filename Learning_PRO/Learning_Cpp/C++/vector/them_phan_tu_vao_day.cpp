#include<iostream>
#include<vector>
#include<string>
using namespace std;
void inday(vector<int > v)
{
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
}
int main(){
	vector<int> v;
	for(int i=1;i<10;i++)
		v.push_back(i);
	cout<<"Day ban dau: "<<endl;
	inday(v);
	v.insert(v.begin()+2,10);		// them vao vi tri thu 2
	v.insert(v.begin()+5,3,20);		// them vao 3 so vao vi tri thu 5
	v.insert(v.end(),50);			// them vao cuoi day
	cout<<"\nDay sau khi them: "<<endl;
	inday(v);
	
return 0;				
}
