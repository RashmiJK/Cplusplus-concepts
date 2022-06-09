/* Exception handing in C++
 * try
 * catch
 * std::bad_array_new_length is ia type of exception thrown by new to report invalid array length 
 */

#include <iostream>
#include <climits>
using namespace std;

int main()
{
	int negative = -1;
	int small = 1;
	int large = INT_MAX;

	cout<<"Start of program" << endl;
	try
	{
		new int[negative];
		//new int[small]{1,2,3};
		//new int[large][1000000];
	}	
	catch(const std::exception &e)
	{
		cout << e.what() << endl;
	}
	cout<<"End of program" << endl;
	return 0;
}

