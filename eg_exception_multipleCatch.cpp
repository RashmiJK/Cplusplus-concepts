/* Exception handing in C++
 * try
 * throw
 * Multiple catch
 */
#include <iostream>
using namespace std;

int main()
{
	int n;

	cout << " 1) throw int " << endl;
	cout << " 2) throw char " << endl;
	cout << " 3) throw float " << endl;
	cout << "Enter your option : ";
	cin >> n;
	cout << endl;

	try
	{
		if(n == 1)
			throw n;
		else if(n == 2)
			throw 'A';
		else if(n == 3)
			throw 4.5;
		else
			cout << "You enetered an invalid option" << endl;
		
	}
	catch(int x)
	{
		cout << "Interger exception " << x << endl;
	}
	catch(char x)
	{
		cout << "Char exception " << x << endl;
	}
	catch(double x)
	{
		cout << "Float exception " << x << endl;
	}


	cout << "End of program" << endl;
	return 0;
}

