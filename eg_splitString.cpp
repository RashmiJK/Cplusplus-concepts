#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> strsplit(string& s)
{
    vector<string> strs_v; // vector of results
    size_t start_loc = 0;
    size_t sep_loc = 0;

    while(true)
    {
        sep_loc = s.find(' ',start_loc);
        strs_v.push_back(s.substr(start_loc,sep_loc - start_loc));
        if(sep_loc == string::npos) break;
        start_loc = sep_loc + 1;
    }
    return strs_v;
}

int main()
{
    vector<string> splitted_string;
    string s = "I am learning DevOps. Will do lot better in few months;";
    splitted_string = strsplit(s);

    for(auto ele : splitted_string)
        cout << ele << endl;

    return 0;
}