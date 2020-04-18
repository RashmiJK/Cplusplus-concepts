#include <iostream>
#include <stack>

using namespace std;

template <typename T>
void print_stack(T item)
{
	bool top_indicated = false;
	
	if(top_indicated == false)
	{
		cout << "top:";
		top_indicated = true;
	}
	while(!item.empty())
	{
		cout << "\t" << item.top();
		item.pop();
	}
	cout << endl;
}

int main()
{
	stack<float> stf;

	stf.push(10.99);
	print_stack(stf);
	
	stf.push(20.99);
	print_stack(stf);
	
	stf.push(30.99);
	stf.push(80.99);
	stf.push(90.99);
	print_stack(stf);
	
	cout << "Item popped" << endl;
	stf.pop();
	print_stack(stf);

}
