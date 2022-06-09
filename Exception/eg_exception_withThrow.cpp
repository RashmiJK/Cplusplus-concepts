/* Exception handing in C++
 * try
 * catch
 * throw
 */
#include <iostream>
using namespace std;

int main()
{
	int n1, n2;

	cout << "Start of program" << endl;

	cout << "Enter the first numberi,n1 :";
	cin >> n1;
	cout << endl;

	cout << "Enter the second number,n2 :";
	cin >> n1;
	cout << endl;

	cout << "Checking the possibility for division n1/n2 ...." << endl;
	//cout <<(n1/n2) << endl;

	try
	{
		if(n2==0)
			throw n2;
		else
		{
			cout <<"n1/n2 = " << (n1/n2) << endl;
		}
	}
	catch(int x)
	{
		cout << "Cannot divide by " << x << ". Will lead to core dump. " << endl;
	}

	cout << "End of program" << endl;
	return 0;
}

