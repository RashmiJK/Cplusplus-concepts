#include <iostream>

using namespace std;

class Complex
{
	private:
		double real;
		double imag;

	public:
		explicit Complex(double r=0.0, double i=0.0) 
		{
			this->real = r;
			this->imag = i; 
			cout << "Constructor called" << endl;
		}

		bool operator == (Complex rhs)
		{
			return ((this->real == rhs.real && this->imag == rhs.imag) ? true : false);
		}
};

int main()
{
	Complex com1(3.0, 0.0);

	if(com1 == (Complex) 3.0)
		cout << "2 Objects are same" << endl;
	else
		cout << "Objects are different" << endl;

	return 0;
}
