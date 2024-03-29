#include <iostream>
#include <algorithm>
#include <cstddef>

using namespace std;

bool gt15(int x) { return 15 < x;}

int main()
{
    int a[] = {10, 20, 30};
    const size_t SIZE = sizeof(a) / sizeof(a[0]);
    int b[SIZE];

    int* endb = remove_copy_if(a, a+SIZE, gt15);
    int* beginb = b;
    while(beginb != endb)
    {
        cout << *beginb++ << endl;
    }
    return 0;
}