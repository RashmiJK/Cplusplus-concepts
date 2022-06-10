#include <iostream>
#include <list>

using namespace std;

template<typename T>
void printl(list<T> &l)
{
	if(l.empty()) return;
	for( auto i = l.begin() ; i != l.end(); i++ )
		cout << *i << " ";
	cout << endl;	
}

int main()
{
	list<int> m = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	cout<< "List m contains : ";
	printl(m);
	cout << endl;

	/* element accesses */
	cout << "Accessing the first element : " << m.front() << endl;
	printl(m);
	cout << endl;

	cout << "Accessing the first element : " << m.back() << endl;
	printl(m);
	cout << endl;

	/* modifiers */
	cout << "Adding 111 to the end : " << endl;
	m.push_back(111);
	printl(m);
	cout << endl;

	cout << "Inserting 112 to the beginning : " << endl;
	m.push_front(112);
	printl(m);
	cout << endl;
	
	/* insert 113 before item 10*/
	cout << "Inserting 113 at a specific location, say before 10 : " << endl;
	for(auto i = m.begin(); i != m.end() ; i++)
	{
		auto prev = i;  /* i is of iterator type, list<int>::iterator i*/
		if(*i == 10)
			m.insert(prev, 113);
	}
	printl(m);
	cout << endl;

	cout << "Remove an element which is 8 : " << endl;
	m.remove(8);
	printl(m);
	cout << endl;

	cout << "Sort rest of the items in the list: " << endl;
	m.sort();
	printl(m);
	cout << endl;
	
	return 0;
}
