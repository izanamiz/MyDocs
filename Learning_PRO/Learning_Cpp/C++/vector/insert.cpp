#include<iostream>
#include<vector>
using namespace std;
main(){

// .insert(pos, n, giatri) chen n phan tu vao vi tri pos cua day	
	vector<int> myvector1(4, 10);
	myvector1.insert(myvector1.begin(), 5, 1); // 1 1 1 1 1 10 10 10 10
	for(int i=0;i<myvector1.size();i++)
		cout<<myvector1[i]<<" ";
	cout<<endl;	
	
// .begin() -> .end()	
	vector<int> myvector2 (4, 100);
	for(int i=0;i<myvector2.size();i++)
		cout<<myvector2[i]<<" ";
	cout<<endl;
		
	vector<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	for(int i=0;i<l.size();i++)
		cout<<l[i]<<" ";
	cout<<endl;
		
	myvector2.insert(myvector2.begin(), l.begin(), l.end());	// 1 2 3 100 100 100 100
	for(int i=0;i<myvector2.size();i++)
		cout<<myvector2[i]<<" ";
	cout<<endl;
		
// .insert(pos, giatri) chen 1 phan tu vao vi tri pos cua day		
	vector<int> vector(4, 10);
	vector.push_back(5);
	vector.insert(vector.begin(), 9);		// 9 10 10 10 10 5	
	for(int i=0;i<vector.size();i++)
		cout<<vector[i]<<" ";
	cout<<endl;		
}
