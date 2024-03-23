//Structure is a collection of variables of different data types
//under a single name. 
//It is similar to a class in that,
// both holds a collecion of data of different data types.
/*
	You want to store some information about a person: 
	you would want to store information about multiple persons
	A better approach will be to have 
		a collection of all related information
	under a single name Person, 
	and use it for every person.
*/
//This collection of all related information 
//under a single name Person is a structure.
/*
	When a structure is created, no memory is allocated.

	The structure definition is only the blueprint for the creating of variables. 
	You can imagine it as a datatype. When you define an integer as below:
	
	int foo;
	The int specifies that, variable foo can hold integer element only.
	Similarly, structure definition only specifies that, 
	what property a structure variable holds when it is defined.
*/
/*
struct [ten cau truc]
{
   phan dinh nghia thanh vien;
   phan dinh nghia thanh vien;
   ...
   phan dinh nghia thanh vien;
   ( dinh ngh)
} [mot hoac nhieu bien cau truc];  
*/
#include <iostream>
#include <cstring>
 
using namespace std;
void inthongtin( struct Books book );

struct Books
{
   char  tieude[50];
   char  tacgia[50];
   char  chude[100];
   int   book_id;
};
 
int main( )
{
	//struct Books QuyenSach1;
   Books QuyenSach1;        // Khai bao QuyenSach1 la cua kieu Books
    Books QuyenSach2;        // Khai bao QuyenSach2 la cua kieu Books
 
   // chi tiet ve quyen sach thu nhat
   strcpy( QuyenSach1.tieude, "Ngon ngu Lap trinh C++");
   strcpy( QuyenSach1.tacgia, "Pham Van At"); 
   strcpy( QuyenSach1.chude, "Lap trinh");
   QuyenSach1.book_id = 1225;

   // chi tiet ve quyen sach thu hai
   strcpy( QuyenSach2.tieude, "Toi thay hoa vang tren co xanh");
   strcpy( QuyenSach2.tacgia, "Nguyen Nhat Anh");
   strcpy( QuyenSach2.chude, "Van hoc");
   QuyenSach2.book_id = 3214;
 
   // in thong tin ve QuyenSach1
   inthongtin( QuyenSach1 );

   // in thong tin ve QuyenSach2
   inthongtin( QuyenSach2 );

   return 0;
}
void inthongtin( struct Books book )
{
   cout << "Tieu de sach: " << book.tieude <<endl;
   cout << "Tac gia: " << book.tacgia <<endl;
   cout << "Chu de: " << book.chude <<endl;
   cout << "ID cua sach la: " << book.book_id <<endl;
   cout << "\n\n========================================\n\n" <<endl;
}
	
