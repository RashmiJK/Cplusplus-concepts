/* Cast operator, unary iperator () is unsafe
 * C++ supports static cast as shown below
 */
#include <iostream>

using namespace std;

int main()
{
	int i = 13;
	char c = 'a';

	/* able to override error with (int *)
	 * this may pass at compile time, but might fail at run time	
 	*/
	int* m = (int *) &c;
	cout << "m = " << m << endl;

	/* this catches problem at compile time and shows intention is illegal */
	int* n = static_cast<int *>(&c);
	cout << "n = " << n << endl;

	return 0;
}
