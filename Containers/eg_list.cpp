/* Double linked list
 * Optimized for rapid insert and delete operations
 * Does not support random access.
 */

#include <iostream>
#include <list>

using namespace std;

// print the elements of list
template<typename T>
void printl(list<T>& l)
{
    if(l.empty()) return;
    for(T& ele : l) cout << ele << " ";
    cout << endl;
}

// print a simple message
void message(const char* s) {cout << s << endl;}
void message(const char*s, const int n) { cout << s << " : " << n << endl; } 


int main()
{
    list<int> l1 = {11, 22, 3, 4, 5, 6, 7, 8, 9, 10};
    printl(l1);

    message("size : ", (int)l1.size());
    message("front : ", (int)l1.front());
    message("back : ", (int)l1.back());

    message("push_back 47");
    l1.push_back(47);
    printl(l1);
    message("\n");

    // post and pre-increment trials
    message("post and pre-increment study : ");
    list<int>::iterator it1 = l1.begin();
    cout << *it1++ << endl;
    cout << *it1 << endl;
    cout << ((*it1)++) << endl;
    cout << *it1 << endl;
    printl(l1);
    message("\n");
    
    // need an iterator to insert because list doesn't store elements in contiguous memory. Rather it's a list
    message("insert : ");
    it1 = l1.begin();
    while(*it1 != 5 && it1 != l1.end())
    {
        it1++;
    }
    if(it1 != l1.end())
    {
        // 5 was found
        message("insert 112 before 5");
        l1.insert(it1, 112);
    }
    printl(l1);
    message("\n");

    // find element with value 7 and erase
    list<int>::iterator it2 = l1.begin();
    while(*it2 != 7 && it2 != l1.end())
    {
        it2++;
    }
    if(it2 != l1.end())
    {
        message("erase 7");
        l1.erase(it2);
    }
    printl(l1);
    message("\n");

    // remove element value 8
    message("remove 8");
    l1.remove(8);
    printl(l1);
    message("remove 88 (non-existing element)");
    l1.remove(88);
    printl(l1);

    message("erase all elements between 112 to 9 positionally : ");
    list<int>::iterator it3 = l1.begin();
    list<int>::iterator it4 = it3;
    while(*++it3 != 112 && it3 != l1.end());
    while(*++it4 != 9 && it4 != l1.end());
    if(it3 != l1.end() && it4 != l1.end())
    {
        l1.erase(it3, it4);
        printl(l1);
    }
    message("\n");



    return 0;
}

