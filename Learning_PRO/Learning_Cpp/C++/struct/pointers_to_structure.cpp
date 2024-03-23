#include <iostream>
using namespace std;

struct Distance
{
    int feet;
    float inch;
};

int main()
{
    Distance *ptr, d;

    ptr = &d;
//The address of variable d is stored to pointer variable
//ptr is pointing to variable d
//the member function of variable d is accessed using pointer
    cout << "Enter feet: ";
    cin >> ptr->feet;//(*ptr).inch and d.inch is exact same cell.
    cout << "Enter inch: ";
    cin >> (*ptr).inch;//(*ptr).feet and d.feet is exact same cell
 	
	//ptr->feet is same as (*ptr).feet
	//ptr->inch is same as (*ptr).inch
    cout << "Displaying information." << endl;
    cout << "Distance = " << (*ptr).feet << " feet " << (*ptr).inch << " inches";

    return 0;
}
