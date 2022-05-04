/*
 * A smart pointer is a wrapper class over a pointer with an operator like * and -> overloaded.
 * Since the destructor is automatically called when an object goes out of scope, the dynamically allocated memory would
 * automatically be deleted 
 */

#include <iostream>

using namespace std;

class SmartPtr
{
    private:
        int * ptr; // actual pointer
    
    public:
        explicit SmartPtr( int * p = NULL)
        {
            ptr = p;
        }
        ~SmartPtr()
        {
            //delete (ptr);
        }
        int& operator* ()
        {
            return *ptr;    
        }

};

SmartPtr test_SmartPtr()
{
    SmartPtr sptr(new int());
    *sptr = 20;
    cout << "In test_SmartPtr : " << *sptr << endl;
    return sptr;
}

int main()
{
    SmartPtr ssptr;
    ssptr = test_SmartPtr();
    cout << "In main : " << *ssptr << endl;

    // we don't need to call delete ptr when the object ptr goes out of scope
    // the destructor for it is automatically called
    // and destructor does delete ptr

    return 0;
}