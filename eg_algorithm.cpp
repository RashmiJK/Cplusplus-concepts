#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// predicate is_odd
template<typename T>
bool is_odd(T& num)
{
    return ((num % 2) == 1);
}

// predicate is_prime
template <typename T>
const bool is_prime(const T num)
{
    if(num <= 1) return false;
    bool primeflag = true;
    for( T l = 2; l < num; l++)
    {
        if(num % l == 0)
        {
            primeflag = false;
            break;
        }
    }
    return primeflag;
}

// print container
template <typename T>
void disp_v(const T &v)
{
    if(!v.size()) 
        return;
    for(auto e : v)
        cout << e << " ";
    cout << endl;
}

int main()
{
    int n = 42;

    // prime numbers < 100, out of order
    vector<int> v1 = { 71, 13, 59, 7, 53, 29, 3, 97, 5, 11, 17, 19, 23, 2, 31, 83, 37, 41, 89, 43, 47, 61, 67, 73, 79};
    disp_v(v1);

    /* sort(v1.begin(), v1.end());
    disp_v(v1);

    if(binary_search(v1.begin(), v1.end(), n))
        cout << "found" << endl;
    else
        cout << "did not find " << n << endl; */

    if(all_of(v1.begin(), v1.end(), is_prime<int>))
        cout << "all_of - true" << endl;
    else
        cout << "all_of - false" << endl;   

    if(any_of(v1.begin(), v1.end(), is_prime<int>))
        cout << "any_of - true" << endl;
    else
        cout << "any_of - false" << endl;   

    if(none_of(v1.begin(), v1.end(), is_prime<int>))
        cout << "none_of - true" << endl;
    else
        cout << "none_of - false" << endl;   

    auto it = find(v1.begin(), v1.end(), 41);
    if(it != v1.end())
    {
        size_t index = it - v1.begin();
        cout << "found at index " << index << " : " << *it << endl;
    }
    else
        cout << " not found" << endl;

    auto iit = find_if(v1.begin(), v1.end(), is_odd<int>);
    if(it != v1.end())
    {
        size_t index = iit - v1.begin();
        cout << "found at index " << index << " : " << *iit << endl;
    }
    else
        cout << " not found" << endl;
    return 0;
}
