#include <iostream>

using namespace std;

template <typename T>
T factorial(T n)
{
    T rc = n;
    while(n>1)
    {
            rc *= --n;
    }
    return rc;
}

template <typename T>
T factorial_recur(T n)
{
    if (n > 1)
        return (n * factorial_recur(n-1));
    else
        return 1;
}

int main()
{
    cout << factorial(4) << endl;
    cout << factorial((long long unsigned int)15) << endl;
    cout << factorial((long double)15) << endl;

    cout << factorial_recur(4) << endl;
    cout << factorial_recur((long long unsigned int)15) << endl;
    cout << factorial_recur((long double)15) << endl;
    return 0;
}
