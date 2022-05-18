
#include <iostream>
#include <string>

using namespace std;

class Solution
{
    public: 
        bool IsPalindrome(string);       
        bool IsPalindrome(int);        
};

bool Solution::IsPalindrome(string P)
{
    //cout << P.length()/2 << endl;
    for(int i = 0; i < P.length()/2; i++)
    {
        if (P[i] != P[P.length() - i - 1])
        return false;;    
    }
    return true;
}

/* Convert integer to string and process comparing first to last element until half the length is reached */
/*
bool Solution::IsPalindrome(int P)
{
    string str = to_string(P);
    return IsPalindrome(str);
}
*/
/* Leetcode suggested solution
 *
 */
bool Solution::IsPalindrome(int P)
{
    if(P < 0 || ((P % 10 == 0) && P!= 0))
        return false;
    
    int revertedNumber = 0;
    while( P > revertedNumber)
    {
        revertedNumber = revertedNumber * 10 + P % 10;
        P /= 10;
    }

    return P == revertedNumber || P == revertedNumber/10;
}

int main()
{
    string S = "ABCDEFDCBA";
    Solution s;
    string ans;
    ans = s.IsPalindrome(S) ? "Yes" : "No";
    cout << ans << endl;

    ans = s.IsPalindrome(123421) ? "Yes" : "No";
    cout << ans << endl;

    return 0;
}