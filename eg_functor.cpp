/* A function object, or functor, is any type that implements operator().
 * C++ allows the function call operator() to be overloaded, such that an object 
 * instantiated from a class can be called like a function.
 * The main benefit of using function objects is that they are objects and hence can contain state, either 
 * statically across all instances of the function objects or individually on a particular instance.
 */


#include <iostream>
#include <string>

using namespace std;

class MultBy
{
    int mult = 1;
    MultBy();

    public:
        MultBy(int n) : mult(n) {}
        int operator () (int n) const {return mult * n;}
};

class Functor
{
    public:
        bool operator() (int a, int b)
        {
            return a < b;
        }
};

// abstarct base class
class Binaryfunction
{
    public:
        Binaryfunction() {}
        virtual double operator() (double left, double right) = 0; // pure virtual function. cannot instantiate.
        virtual ~Binaryfunction() { cout << "dtor" << endl;}
};

// add two doubles
class Add : public Binaryfunction
{
    public:
        Add() {}
        virtual double operator() (double left, double right) {return left+right;}
};

// multiply two doubles
class Multiply : public Binaryfunction
{
    public:
        Multiply() {}
        virtual double operator() (double left, double right) {return left*right;}
};

double binary_op(double left, double right, Binaryfunction* bin_func)
{
    return (*bin_func)(left, right);
}

int main()
{
    Functor f;
    int a = 25;
    int b = 17;
    bool ans = f(a, b);
    cout << ans << endl;


    double aa = 5.0;
    double bb = 10.0;
    Binaryfunction * pAdd = new Add();
    Binaryfunction * pMultiply = new Multiply();

    cout << "Add: " << binary_op(aa, bb, pAdd) << endl;
    cout << "Add: " << binary_op(aa, bb, pMultiply) << endl;

    delete pAdd;
    delete pMultiply;

    const MultBy times4(4);
    const MultBy times10(10);
    const MultBy times15(15);

    cout << "times4(5) = " << times4(5) << endl;
    cout << "times4(15) = " << times4(15) << endl;
    cout << "times15(15) = " << times15(15) << endl;

    return 0;
}