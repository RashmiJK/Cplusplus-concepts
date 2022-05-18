#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

void parseInts(string str) {
	// Complete this function
    stringstream ss(str);
    string word;;
    while(ss >> word)
    {
        cout << word << endl;
    }
}

int main() {
    string str = "2 3 4 56, rashmi +23 -55";
    //cin >> str;
    parseInts(str);
 
    return 0;
}