#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) 
    {
        // count number of xy pairs and yx pairs in (s1,s2) positional order
        int xypairs = 0, yxpairs = 0;
        for(int i = 0; i < s1.length() ; i++)
        {
            if (s1[i] == 'x' && s2[i] == 'y')
                xypairs++;    
            else if ((s1[i] == 'y' && s2[i] == 'x'))
                yxpairs++;
        }
        cout << "xypairs = " << xypairs << " yxpairs = " << yxpairs << endl;

        int swaps = (xypairs / 2) + (yxpairs / 2);
        int xyremainder = xypairs % 2;
        int yxremainder = yxpairs % 2;       

        cout << "swaps = " << swaps << endl;
        cout << " xyremainder = " << xyremainder << endl;
        cout << " yxremainder = " << yxremainder << endl;

        if(xyremainder && yxremainder)
            return (swaps+2);
        else if(!xyremainder && !yxremainder)
            return swaps;
        else
            return (-1);
        
    }
};

int main()
{
    string s1 = "yyxxxy";
    string s2 = "xxyyyx";
    int swaps = 0;
    Solution s;

    swaps = s.minimumSwap(s1,s2);   
    cout << swaps << endl;
    return 0;
}