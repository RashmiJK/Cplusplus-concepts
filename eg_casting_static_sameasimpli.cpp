/* Cast operator, unary operator () is unsafe
 * C++ supports static cast
 */
#include <iostream>
#include <string>

using namespace std;

class conv_int
{
	int x;
	public:
		conv_int(int in = 0) : x{ in }
		{
			cout << "Constructor called" << endl;
			cout << "obj x value = " << this->x << endl;
		}
		
		operator string()
		{
			cout << "Conversion operator string called " << endl;
			return to_string(x);
		}
};

int main()
{
	conv_int obj(3);
	cout << endl;
	
	/* obj of class conv_int type is converted to string type without using static_cast */
	string str = obj;
	cout << "str = " << str << endl;
	cout << endl;
	
	/* obj is assigned without static_cast */
	obj = 20;
	cout << endl;
	
	/* this is same operation as line 32, but with static_cast */
	string str1 = static_cast<string>(obj);
	cout << str1 << endl;
	cout << endl;
	
	/* this is same operation as line 37, but with static_cast */
	obj = static_cast<conv_int>(40);
	
	return 0;

}
