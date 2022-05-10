#include "strc.h"
#include <utility>
#include <memory>
#include <iostream>

using namespace std;

void message(const char* s)
{
    cout << s << endl;
    fflush(stdout);
}

// display object value from unique_ptr
void disp(std::unique_ptr<strc> & o)
{
    if(o)
        puts(o->value());
    else
        puts("null");
    fflush(stdout);
}

int main()
{
    message("create unique pointer one");
    std::unique_ptr<strc> a(new strc("one")) ;
    disp(a);
    cout << endl;

    message("make unique two");
    auto b = std::make_unique<strc>("two");
    disp(a);
    disp(b);
    cout << endl;

    message("reset a to three");
    a.reset(new strc("three"));
    disp(a);
    disp(b);
    cout << endl;

    message("move b to c");
    auto c = std::move(b);
    disp(a);
    disp(b);
    disp(c);
    cout << endl;

    message("reset a");
    a.reset();
    disp(a);
    disp(b);
    disp(c);
    cout << endl;

    message("release c");
    //c.release();
    disp(a);
    disp(b);
    disp(c);

    message("end of scope");

    return 0;
}