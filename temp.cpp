#include <iostream>

using namespace std;

int main()
{
	//int i = static_cast<int>(2.2);
	
	int i = 13;
	double *d = &i;
	i = (int) d;
	cout << i << endl << d << endl;
	return 0;
}
