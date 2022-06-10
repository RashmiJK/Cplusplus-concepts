/* STL Vector example
 */

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

	/* emplace does in-place insertion and avoids copying of object
	 * meaning, constructs the object and inserts 
	 * For primitive data type, it does not matter much, but for object type it is efficient
	 * vector<Foo> v;
	 * v.emplace(iterator, 42, 3.1216)
	 * v.insert(iterator, Foo(42, 3.1216));
	 */
	vec.emplace(vec.begin(), 5);
	print_vec(vec);

	/* returns the number of elements that can be held in currently allocated storage */
	cout << "Capacity of this vector: " << vec.capacity() << endl;
	
	/* returns the maximum possible number of elements */
	cout << "Max size of the vector: " << vec.max_size() << endl;

	vec.resize(4);
	cout << "Size of the vector: " << vec.size() << endl;
	print_vec(vec);

	vec.push_back(2);
	print_vec(vec);

	std::sort(vec.begin(), vec.end());
	print_vec(vec);

}

void print_vec(vector<int> vec)
{
	cout << "The vector elements are: ";
	/* auto deduces as iterator to a vector
	 * vector<int>::iterator ptr = vec.begin() 
	 */
	for(auto i = vec.begin(); i != vec.end(); i++)
		cout << *i << " ";
	cout << endl;
}
