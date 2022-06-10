/* Pair will carry a pair of 2 strongly typed values
 * Whereas tuple can carry multiple size of stromgly typed languages
 * Sometimes, pair and tuple are far convenient to use than structs
 */

#include <iostream>
#include <tuple>
#include <string>

using namespace std;

// print the elements of tuple
template <typename T>
void print3tuple(T t)
{
    auto tsz = tuple_size<decltype(t)>::value;
    if(tsz != 3) return;
    cout << get<0>(t) << " <-> " << get<1>(t) << " <-> " << get<2>(t) << endl;
}

// print a simple message
void message(const char* s) {cout << s << endl;}
void message(const char*s, const int n) { cout << s << " : " << n << endl; } 


int main()
{
    // initilaizer list
    message("intializer list");
    tuple<int, string, int> t1 = {47, "forty-seven", 1};
    print3tuple(t1);

    // default constructor
    message("default constructor");
    tuple<int, string, int> t2(72, "seventy-two", 2);
    print3tuple(t2);

    // make_tuple
    message("make_tuple");
    tuple<int, string, int> t3;
    t3 = make_tuple(7, "seven", 3);
    print3tuple(t3);

    // comparision operator
    message(" t1 == t2 ?", t1 == t2);
    message(" t1 < t2 ?", t1 < t2);
    message(" t1 < t3 ?", t1 < t3);
    message(" t1 > t2 ?", t1 > t2);
    message(" t1 > t3 ?", t1 > t2);

    return 0;
}

