#include <iostream>
#include <string>

using namespace std;

class A
{
    int _value = 0;

    public:
        void setv(const int a)
        {
            _value = a;
        };
        void setav(const int a)
        {
            _value = a;
        }
        int getv() const
        {
            return _value;
        }
};

/* int A::getv() const
{
    return _value;
}*/


int main()
{
    const int p = 42;
    A a;
    a.setv(p);
    cout << a.getv() << endl;

    const A b = a;
    cout << b.getv()<< endl;
    return 0;
}