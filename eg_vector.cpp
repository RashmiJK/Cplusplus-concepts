#include <iostream>
#include <vector>
using namespace std;

void print_vec(vector<int> vec);

int main(int argc, char * argv[])
{
	cout << "Sample vector pgm - " << endl;
	
	/* vector - push_back(), assign(), pop_back(), insert(), erase(), swap(), clear()
 	 * 	    begin(), end()
 	 * 	    size(), max_size(), capacity(), resize(), empty()
	*/
	vector<int> vec;

	/* fill the array with 12 seven times */
	vec.assign(7, 12);

	vec.push_back(24);
	print_vec(vec);

	/* removes last element */
	vec.pop_back();
	print_vec(vec);

	vec.insert(vec.begin(),10);
	print_vec(vec);

	vec.insert(vec.begin(), 10);
	print_vec(vec);

	vec.erase(vec.begin());
	print_vec(vec);

	vec.emplace(vec.begin(), 5);
	print_vec(vec);

	cout << "Capacity of this vector: " << vec.capacity() << endl;
	cout << "Max size of the vector: " << vec.max_size() << endl;

	vec.resize(4);
	cout << "Size of the vector: " << vec.size() << endl;

}

void print_vec(vector<int> vec)
{
	cout << "The vector elements are: ";
	for(auto i = vec.begin(); i != vec.end(); i++)
		cout << *i << " ";
	cout << endl;
}
