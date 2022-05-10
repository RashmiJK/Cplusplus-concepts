#include <iostream>

using namespace std;

class c1
{
  int i = 0  ;

  public:
    void setvalue(const int& value) // refernce avoids copying value and saves time
    {
            i = value;
    }

    int getvalue() const
    {
        return i;
    }
};


int main()
{
    const int i = 47;
    c1 o1;
    o1.setvalue(i);
    cout << o1.getvalue() << endl;

    c1 o2;
    o2 = o1; // implicit copy constructor
    cout << "o1 = " << o1.getvalue() << endl;
    cout << "o2 = " << o2.getvalue() << endl;

    o1.setvalue(72);
    o2 = o1; // implicit copy operator,'=' operator
    cout << "o1 = " << o1.getvalue() << endl;
    cout << "o2 = " << o2.getvalue() << endl;

    return 0;
}