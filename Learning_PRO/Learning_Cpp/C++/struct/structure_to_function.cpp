	
#include <iostream>
using namespace std;

struct Person {
    string name;
    int age;
    float salary;
};

Person getData(Person); // Function declaration
void displayData(Person); // Function declaration

int main() {

    //(struct )+
	Person p;
	// Function call with structure variable as an argument
	// The value of all members of a structure variable 
	// can be assigned to another structure
	// using assignment operator = 
	// if both structure variables are of same type.
	// You don't need to manually assign each members.
    p=getData(p);   
    displayData(p);

    return 0;
}

Person getData(Person p) {

    cout << "Enter Full name: ";
    getline(cin,p.name);
    

    cout << "Enter age: ";
    cin >> p.age;

    cout << "Enter salary: ";
    cin >> p.salary;

    return p;
}

void displayData(Person p) {
    cout << "\nDisplaying Information." << endl;
    cout << "Name: " << p.name << endl;
    cout <<"Age: " << p.age << endl;
    cout << "Salary: " << p.salary;
}
