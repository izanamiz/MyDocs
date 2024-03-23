#include<iostream>
#include<vector>
using namespace std;
main(){
	vector<int> foo (3,100);   // three ints with a value of 100
	vector<int> bar (5,200);   // five ints with a value of 200

	cout<<"Before swap: \n";
	for(int i=0;i<foo.size();i++)
		cout<<foo.at(i)<<" ";
	cout<<endl;
	for(int i=0;i<bar.size();i++)
		cout<<bar.at(i) << " ";
	//swap				
	bar.swap(foo);
	
	cout<<"\nAfter swap: \n";
	for(int i=0;i<foo.size();i++)
		cout<<foo.at(i)<< " ";
	cout<<endl;
	for(int i=0;i<bar.size();i++)
		cout<<bar.at(i) << " ";		
	// foo: 200 200 200 200 200
	// bar: 100 100 100
}
