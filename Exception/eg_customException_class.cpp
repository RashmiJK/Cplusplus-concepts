#include <iostream>
#include <exception>

using namespace std;

namespace my
{
    class my_exception : public exception
    {
        const char* msg;
        my_exception(); // constructor in private block prohibts instantiation of default type

        public:
            my_exception(const char* s) noexcept(true) : msg(s) {} //noexcept(true) is specifying that this function will not throw exception
            const char* what() const noexcept(true) {return msg;}
    };
}

my::my_exception e_silly("silly!");
my::my_exception e_bad("bad!");
my::my_exception e_worse("worse!");

void broken()
{
    cout << "this is a broken function" << endl;
    //throw e_silly;
    throw e_worse;
}

int main()
{
    cout << "let's call a function that throws exception" << endl;
    try
    {
         broken();
    }
    catch(const my::my_exception& e)
    {
        std::cerr << e.what() << '\n';
    }   
    
    return 0;
}