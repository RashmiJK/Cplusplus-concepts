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

	cout << "Start of program" << endl;
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
	catch( ... )
	{
		cout << "Exception caught " << endl;
	}

	cout << "End of program" << endl;
	return 0;
}

