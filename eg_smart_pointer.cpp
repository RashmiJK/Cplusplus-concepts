/* Smart pointer is a technique to use to reduce potential memory leaks caused by
 * dynamic memory allocation.
 * It can be thought as a wrapper class over normal pointers.
 */

#include <iostream>

using namespace std;

class Smartptr
{
	int *ptr;

	public:
		Smartptr(int * p = NULL)
		{
			ptr = p;
			cout << "Smartptr Constructor called"<< "  Addresspassed = " << p << endl;
		}	

		~Smartptr()
		{
			delete ptr;
			cout << "I'm Smartptr Destructor" << endl;
		}

		/* Note: int& is the return type which is the c++ refernce type */
		int& operator * ()
		{
			cout << " Overloaded part = " << ptr << "=" << *ptr << endl;
			return *ptr;
		}
};

/* generic smart pointer */
template <class T>
class SmartPtrTemplate 
{
	T* ptr;
	
	public:
		explicit SmartPtrTemplate(T* p = NULL)
		{
			ptr = p;
		}

		~SmartPtrTemplate()
		{
			delete (ptr);
		}
		
		T& operator * ()
		{
			return *ptr;
		}
		T* operator -> ()
		{
			return ptr;
		}

};


int main()
{
	int * ptr;
	Smartptr pptr(new int);	
	SmartPtrTemplate<int> ppptr(new int());

	ptr = new int;
	*ptr = 11;
	cout << *ptr << endl;
	delete ptr;
	
	*pptr = 22;
	cout << *pptr << endl;

	*ppptr = 33;
	cout << *ppptr << endl;
}
