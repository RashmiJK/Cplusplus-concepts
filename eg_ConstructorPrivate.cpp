#include <iostream>

using namespace std;

class c1
{
    int i = 0;
    c1(); // default constructor is private. This prohibts obeject instantiation without initializer.

    public:
    c1(const int& value) : i(value) {} ;
    void setvalue(const int& l) { i = l;}
    int getvalue() const { return i; }
};

int main()
{
    c1 o1(2);
    c1 o2;
    return 0;
}