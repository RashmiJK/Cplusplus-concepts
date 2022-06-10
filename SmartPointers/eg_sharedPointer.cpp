#include <iostream>

using namespace std;

int main()
{
    shared_ptr<int> p1 = make_shared<int>(2);
    cout << p1.use_count() << endl;

    if(1)
    {
        shared_ptr<int> p2 = p1;
        cout << p1.use_count() << endl;
        cout << p2.use_count() << endl;

    }
    cout << p1.use_count() << endl;
    return 0;
}
