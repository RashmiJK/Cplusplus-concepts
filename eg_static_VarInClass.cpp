#include <iostream>

/* Static variables in a function - Usual like in C
 * Static variable in a class - Special to C++, described below. Static variable does not depend on object of a class.
 * Static Object - lifetime of scope for an object
 * Static function in a class - Special to C++. Can invoke using object and . operator and classname and scope resolution operator.
 * 				These functions are allowed to access only static data & other static functions. Cannot access non-static data or non-statuc functions.
 */
using namespace std;

class Test
{
	public: 
		static int i;

	Test()
	{
	}	
};

int Test::i = 10;


class Sample
{
	public:
		static void pprint()
		{
			cout << "I am static function" << endl;
		}
};

int main()
{
	Test obj1;
	Test obj2;
	Sample obj3;
	

	Test::i = 11;
	cout << obj1.i << " " << obj2.i << endl;

	obj3.pprint();
	Sample::pprint();

	return 0;
}
