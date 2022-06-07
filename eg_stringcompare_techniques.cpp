/*  3 techniques
 *  String strcmp() function. C header <string.h> processing C-strings => strlen, strcpy, strcat. C++ header <cstring>.
 *  In-built compare() function
 *  C++ Relational operator ('==', '!=')
 * 
 * C-strings are simply implemented as a char array which is terminated by a null character (aka 0). 
 * This last part of the definition is important: all C-strings are char arrays, but not all char arrays are c-strings
 */

#include <iostream>
#include <string>

using namespace std;

bool cstyle_compare(const char* lhs, const char*rhs)
{
    int comp_val = strcmp(lhs, rhs);
    cout << " comp_val = " << comp_val << endl;
    //char* new_str = new char [40];
    char new_str[40];
    cout << strlen(lhs) << " <=> " << strlen(rhs) << endl;
    strcpy(new_str,lhs);
    strcat(new_str,rhs);
    cout << "new_str = " << new_str << " strlen = " << strlen(new_str) << " sizeof = " << sizeof(new_str)/sizeof(char) << endl;

    
    return comp_val;
}

bool stdstringstyle_compare(const char* lhs, std::string my_str)
{
    return(strcmp(lhs, my_str.c_str()));
}

int main()
{
    const char* lhs = "abc";
    cstyle_compare(lhs, "Abc");

    std::string my_str("Abcdefghi");
    std:string sub_str(my_str, 4);
    std::string filled(16, 'A');
    cout <<  "stdstringstyle_compare = " << stdstringstyle_compare(lhs, my_str) << endl;
    cout <<  "sub_str = " << sub_str << endl;
    cout << "filled constuctor = " << filled << endl;

    my_str = "test";
    std::string str2("buo");
    const char* c_str = "This is a c_Str";

    cout << my_str.append(str2,1,2) << endl;
    //cout << my_str.append(c_str) << endl;

    return 0;
}