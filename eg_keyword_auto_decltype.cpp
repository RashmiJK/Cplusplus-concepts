/*
 * Categr]ory - type inference; automatic deduction of data type; all thetypes are duduced in the compiler phase only
 * auto - should be initialized during declaration. auto does the same thing as template type deduction.
 * decltype -  gives the declared type of the expression that is passed to it   
 * if you have a function that returns a reference, auto will still be a value (you need auto& to get a reference), but decltype 
 * will be exactly the type of the return value.   
 */

#include <iostream>
using namespace std;

int global {};
int& foo()
{
    return global;
}

int main()
{
    decltype(foo()) a = foo();  // a is an 'int&'
    cout << "a's type is : " << typeid(a).name() << endl;

    auto b = foo(); // b is an 'int'
    cout << "b's type is : " << typeid(b).name() << endl;
    b = 2;

    cout << "a = " << a << " b = " << b << endl;

    decltype(foo()) c = foo(); // c is also an 'int&'
    cout << "c's type is : " << typeid(c).name() << endl;
    cout << "a = " << a << " b = " << b << " c = " << c << endl;    

    c = 10;

    cout << "a = " << a << " b = " << b << " c = " << c << endl;    
    return 0;
}
