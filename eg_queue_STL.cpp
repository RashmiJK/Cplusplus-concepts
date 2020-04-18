#include <iostream>
#include <queue>

using namespace std;

template <typename T>
void print_queue(T item)
{
	bool front_marked = false;

	if(front_marked == false)
	{	
		cout << " Front " ;
		front_marked = true;
	}
	while(!item.empty())
	{
		cout << "\t" << item.front();
		item.pop();
	}
	cout << endl;
}

int main()
{
	queue<float> stf;

	stf.push(10.99);
	print_queue(stf);
	
	stf.push(20.99);
	print_queue(stf);
	
	stf.push(30.99);
	stf.push(80.99);
	stf.push(90.99);
	print_queue(stf);
	
	cout << "Item popped" << endl;
	stf.pop();
	print_queue(stf);
	
	cout << "One more item popped" << endl;
	stf.pop();
	print_queue(stf);
}
