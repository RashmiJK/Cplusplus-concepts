/* Cast operator, unary iperator () is unsafe
 * C++ supports static cast as shown below
 */
#include <iostream>

using namespace std;

class Parent
{
	private:
		int a = 10;
	protected:
		int b = 20;
	public:
		int c = 30;
};

/* All the protected and public members of Parent class will get inherited as
 * private in Child class
 * */
class Child : private Parent
{	
	public:
		/* void read_private() cannot have this; its not even inherited, bcoz is private
		{
			cout << this->a << endl;
		} */
		void read_protectedPartOfBase()
		{
			cout << this->b << endl;
		}
		void read_publicPartOfBase() 
		{
			cout << this->c << endl;
		}
};

int main()
{
	Child d1;
	d1.read_protectedPartOfBase();
	d1.read_publicPartOfBase();
	//cout << d1.c << endl; /* error, bcoz is inherited as private into derived class*/
	
	//Parent* b1 =  (Parent*)&d1; /* this is masking the violation of breaking inaccessibility rule */
	//cout << "Accessing member through type casting -  " << b1->c << endl;
	Parent* b2 = static_cast<Parent *>(&d1); /* Tight type checking at rescue */
	
	return 0;
}
