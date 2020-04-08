/* C++ has the ability to provide the operators with a special meaning
 * for a data type
 */

#include <iostream>

using namespace std;

class Complex {
	private:
		int real, img;
	public:
		Complex(int r = 0, int i = 0)
		{
			real = r;
			img = i;
		}

		Complex operator +  (Complex const &obj )
		{
			Complex res;
			res.real = this->real + obj.real;
			res.img = this->img + obj.img;
			return res;
		}
		
		void print()
		{
			cout << this->real << " + i " << this->img << endl;
		}
	
};

int main()
{
	Complex c1(10, 5), c2(2,4);
	Complex c3 = c1 + c2;
	c3.print();
}
