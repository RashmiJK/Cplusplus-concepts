#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int arr[5] = {1,4,8,12,16};
    int* p;
    p = arr;
    cout << p << endl;
    cout << *p++ << endl;
    cout << p << endl;
}