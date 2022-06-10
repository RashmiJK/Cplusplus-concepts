/* Set
 * Ordered, sorted 
 * Can contain only unique elements
 * Multiset allows duplicates, but in order
 * unrodered_set, again contains only unique elements, but not in order. No order, but provides
 * hashed keys for faster access.
 */

#include <iostream>
#include <string>
#include <set>
#include <unordered_set>

using namespace std;

// print the elements of set
template<typename T>
void printset(T& s)
{
    if(s.empty()) return;
    for(auto ele : s)
        cout << ele << " ";
    cout << endl;
}

// print a simple message
void message(const char* s) {cout << s << endl;}
template<typename T>
void message(const char* m, const T& v) { cout << m << " : " << v << endl; } 

int main()
{
    message("construct set set1");
    set<string> set1 = {"one", "two", "three", "four", "five"};
    message("size of set1", set1.size());
    message("ordered set is alphabetical");
    printset(set1);

    message("insert element six");
    set1.insert("six");
    printset(set1);

    message("find and erase element six");
    set<string>::iterator it1 = set1.find("six");
    if(it1 != set1.end())
    {
        message("erasing", *it1);
        set1.erase(it1);
    }
    else
    {
        cout << "not found" << endl;
    }
    printset(set1);

    message("inserting duplicate element five");
    auto r = set1.insert("five"); // insert method returns a pair. first element = iterator new/duplicate, second element = true/false
    cout << *(r.first) << " insertion -> " << r.second << endl;
    printset(set1);
    cout << endl;

    message("construct unordered set set1");
    unordered_set<string> set2 = {"one", "two", "three", "four", "five"};
    message("size of unordered_set", set2.size());
    message("unordered set has no defined order");
    printset(set2);

    message("insert element six");
    set2.insert("six");
    printset(set2);

    message("find and erase element six");
    unordered_set<string>::iterator it2 = set2.find("six");
    if(it2 != set2.end())
    {
        message("erasing", *it2);
        set2.erase(it2);
    }
    else
    {
        cout << "not found" << endl;
    }
    printset(set2);

    message("inserting duplicate element five");
    set2.insert("five");
    printset(set2);
    cout << endl;
    
    return 0;
}

