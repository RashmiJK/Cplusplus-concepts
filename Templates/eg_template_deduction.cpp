#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
void printv(vector<T> & v)
{
    if(v.empty()) return;
    for(typename vector<T>::iterator  it = v.begin(); it != v.end(); it++) 
    {
        cout << *it << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    vector<string> v2;
    v2.push_back("one");
    v2.push_back("two");
    v2.push_back("three");
    v2.push_back("four");
    v2.push_back("five");
    
    printv<int>(v1);
    printv<string>(v2);

    printv(v1);
    printv(v2);

    return 0;
}