#include <iostream>
#include <vector>
using namespace std;

int main() {

    int x = 11;
    const int& y = x;

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "&x = " << &x << endl;
    cout << "&y = " << &y << endl;

    return 0;
}