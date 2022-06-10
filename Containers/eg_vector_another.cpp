/* Strict sequential order.
 * Dynamic size.
 * 
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// print the elements of vector
template<typename T>
void printv(vector<T>& v)
{
    if(v.empty()) return;
    for(T& ele : v) cout << ele << " ";
    cout << endl;
}

// print a simple message
void message(const char* s) {cout << s << endl;}
void message(const char*s, const int n) { cout << s << " : " << n << endl; } 


int main()
{
    cout << "vector from initializer list: " << endl;
    vector<int> v1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printv(v1);

    // info
    message("size", (int)v1.size());
    message("front", (int)v1.front());
    message("back", (int)v1.back());
    message("\n");

    // index
    message("element at 5", v1[5]);
    message("element at 5", v1.at(5));
    message("\n");

    // insert
    message("insert 42 at begin + 5");
    v1.insert(v1.begin()+5, 42);
    printv(v1);
    message("\n");

    // erase
    message("erase at begin+5");
    v1.erase(v1.begin()+5);
    printv(v1);
    message("\n");

    // push_back
    message("push_back 47");
    v1.push_back(47);
    printv(v1);
    message("\n");

    // pop_back
    message("push_back 47");
    v1.pop_back();
    printv(v1);
    message("\n");

    // empty
    message("empty : ");
    vector<int> vx = {1, 2, 3};
    while(!vx.empty())
    {
        printv(vx);
        vx.pop_back();
    }
    message("\n");    

    // insert
    message("insert in a different way : ");
    vector<int> vy = {6, 7, 8, 9, 10};
    vx.insert(vx.begin(), {1, 2, 3, 4, 5}); // insert an array or another vector into vx
    vx.insert(vx.end(), vy.begin(), vy.end());
    printv(vx);
    message("vx size : ", (int) vx.size());
    message("vx clear :");
    vx.clear();
    message("vx size : ", (int) vx.size());
    printv(vx);
    message("\n");

    // constructors
    
    // construct from C-Array
    constexpr size_t size = 10;
    int ia[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    message("vector from C array");
    vector<int> v2(ia, ia + size);
    printv(v2);
    message("\n");

    // constructor : filled with strings
    message("vector filled with strings : ");
    vector<string> v3(5, "custom_string");
    printv(v3);
    message("\n");

    // copy constructor
    message("vector copied from vector : ");
    vector<string> v4(v3);
    printv(v4);
    message("\n");

    // move constructor
    message("vector(v5) moved from vector(v4)");
    message("size of v4 : ", (int) v4.size());
    vector<string> v5(std::move(v4));
    printv(v5);
    message("size of v4 : ", (int) v4.size());
    
    return 0;
}

