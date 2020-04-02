#include <iostream>
#include <vector>

using namespace std;

int swap (int& a, int& b);

int main()
{
	int x = 10;
	int& ref = x;
	int p = 2, q = 3;
	vector<int> vect{ 10, 20, 30, 40};
	vector<string> vec {"references", "have", "multiple", "benefits"};

	ref = 20;
	cout << "x = " << x << endl;

	x = 30;
	cout << "ref= " << ref << endl;

	cout << "p = " << p << " " << "q = " << q << endl;
	swap(p, q);
	cout << "p = " << p << " " <<"q = " << q << endl;

	for( int&x : vect)
		x = x + 5;

	for( int y : vect)
		cout << y << " ";

	for(const auto &p : vec)
		cout << p << " ";
	
	return 0;
}

int swap (int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
	return 0;
}
