#include<iostream>
#include<vector>
using namespace std;
main(){
		
	// default constructor
	vector<double> second;
	
	// fill constructor
	vector<double> first(4, 50); // first = { 50, 50, 50, 50}
	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);
	// first = { 50, 50, 50, 50, 3.1, 2.2, 2.9}	
	
	// position truy cap den vi tri dau tien chua gia tri  50
	vector<double>::iterator position = first.begin();
	position += 2; // position truy cap den vi tri thu ba chua gia tri 50
	
	vector<double>::iterator position1 = first.end();
	position1 -= 2; // position truy cap den vi tri thu nam chua gia tri 3.1
		
	// range constructor
	vector<double> third(position, position1); // third = { 50, 50, 3.1}
	
	*position = 5.5;
	cout<< first[2]<<endl;// 5.5
	for(int i=0;i<first.size();i++)
		cout<<first.at(i)<<" ";
}
