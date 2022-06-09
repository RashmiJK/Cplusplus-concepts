#include <iostream>

using namespace std;


bool isPalindrome(int x) 
{
    if(x < 0 || ((x % 10 == 0) && x!=0))
        return (false);
    int rnum = 0;
    while( x > rnum)
    {
        rnum = x % 10 + rnum * 10 ;
        x /= 10;
    }
    return(x == rnum || x == rnum/10);
}


int main()
{
    (isPalindrome(1221) == true) ? (cout << "Yes palindrome") : (cout << "No");
    return 0;
}