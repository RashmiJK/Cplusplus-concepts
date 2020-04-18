/* Exception handing in C++
 * try
 * throw
 * catch - rethrow
 * catch
 */
#include <iostream>
using namespace std;

int main()
{

	cout << "End of program" << endl;
	
	try
	{

		try
		{
			throw 1;	
		}
		catch(int x)
		{
			cout << "Exception in inner try-catch block : " << x << endl;
			throw 2;
		}
	}
	catch(int x)
	{
		cout << "Exception in outer try-catch block - " << x << endl;
	}

	cout << "End of program" << endl;
	return 0;
}

