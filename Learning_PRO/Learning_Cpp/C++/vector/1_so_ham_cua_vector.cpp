#include<iostream>
#include<vector>
using namespace std;
main(){
 
	vector<int> first(4, 50); // first = { 50, 50, 50, 50}
	vector<int> sec(first);
// 1. them 1 phan tu vao vi tri cuoi cung cua vector
	first.push_back (3);
	first.push_back (2);
	first.push_back (4);
	first.push_back (5);
	// first = { 50, 50, 50, 50, 3, 2, 4}
	for(int i=0; i<first.size();i++)
		cout<<first.at(i)<<" ";
		
// 2. Xoa phan tu cuoi vector
	first.pop_back();
	cout<<endl;
	for(int i=0; i<first.size();i++)
		cout<<first.at(i)<<" ";
// 3a. Dung luong va kich thuoc	
	cout<<"\nlength: "<<first.size()<<"   capacity: "<<first.capacity()<<'\n';
	cout<<"length: "<<sec.size()<<"   capacity:"<<sec.capacity()<<endl;

// 3b. Cap phat dung luong(capacity) ban dau cho std::vector bang ham reverse();
	/*
		first.reverse(11);
		sec.reverse(11);
		cout<<"new capacity: "<<first.capacity()<<" "<<sec.capacity()<<endl;
	*/
	
// 3c.1 Thay doi so phan tu cua vector
	sec.resize(1);
	cout<<"length of sec: "<<sec.size()<<"   capacity "<<sec.capacity();
/*	cout<<sec.at(3);// loi vi truy cap phan tu lon hon size cua vector
terminate called after throwing an instance of 'std::out_of_range'
  what():  vector::_M_range_check: __n (which is 3) >= this->size() (which is 1)
*/
	cout<<'\n'<<sec.back()<<endl;
//	3c.2  Thay doi so kich thuoc cua vector
	vector<double> second(10,2);
	second.resize(5);
	for( int i = 0; i < second.size(); i++)
		cout << second[i] <<" ";
	vector<double> third(7, 3);
	cout<<endl;
	third.resize(10);
	for( int i = 0; i < third.size(); i++)
		cout << third[i] << " ";	
	cout<<endl;	
	
// 3d. Xoa phan tu
		sec.clear();
		cout<<sec.size()<<endl;
		
// 4. Kiem tra trang thai rong cua vector
	if(sec.empty()==true)
		cout<<"No values in sec\n";
		
// 5. lay phan tu dau va cuoi cua vector
	cout <<first.front()<<" "<< first.at(0) << endl; //out 50
	cout <<first.back()<<" "<< first[6]; //out 2.9
	//	first[6] // không kiem tra pham vi mang
	//	first.at(0) // có kiem tra pham vi mang	


}
