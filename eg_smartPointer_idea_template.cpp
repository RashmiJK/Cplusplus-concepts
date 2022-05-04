#include <iostream>

using namespace std;

template <typename T>
class SmartPtr
{
    T* ptr;

    public:
        explicit SmartPtr(T* p = NULL)
        {
            ptr = p;
        }

        ~SmartPtr()
        {
            delete ptr;
        }

        T& operator* ()
        {
            return *ptr;
        }

        T* operator-> ()
        {
            return ptr;
        }

};

int main()
{
    SmartPtr<int> sptr(new int());

    *sptr = 200;
    cout << *sptr << endl;
    return 0;
}