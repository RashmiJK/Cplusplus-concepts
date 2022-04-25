
#include <iostream>

using namespace std;

string IsPalindrome(string P)
{
    for(int i = 0; i < P.length()/2; i++)
    {
        if (P[i] != P[P.length() - i - 1])
        return "No";    
    }
    return "Yes";
}

int main()
{
    string S = "ABCDEFDCBA";
    cout << IsPalindrome(S) << endl;
    return 0;
}