#include <iostream>
#include <vector>
using namespace std;

void printStack(const vector<int> &stack)
{
	for (const auto &element : stack)
		cout << element << ' '; 
	cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}

int main()
{
	vector<int> stack;

	stack.push_back(5); // push_back() thêm 1 phan tu vao cuoi vector
	printStack(stack);

	stack.push_back(3);
	printStack(stack);

	stack.push_back(2);
	printStack(stack);

// back() tra ve giá tri cua phan tu cuoi
	cout << "Phan tu cuoi: " << stack.back() << '\n'; 

	stack.pop_back(); // pop_back() xóa m?t ph?n t? cu?i vector
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	system("pause");
	return 0;
}

