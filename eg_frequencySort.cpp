#include <iostream>
#include <unordered_map>
#include <iterator>
#include <vector>
#include <map>

using namespace std;
class Solution
{
    public:
        vector<int>frequencySort(vector<int>&);
        static bool cmp(vector<int>a, vector<int>b);
};

bool Solution::cmp(vector<int>a, vector<int>b)
{
    if(a[0] < b[0]) return true;
    if(a[0] == b[0])
    {
        return a[1] > b[1];
    }
    return false;
}

vector<int> Solution::frequencySort(vector<int>& nums)
{
    unordered_map<int,int> m;
    for(auto a : nums) m[a]++;

    cout << "unordered_map : " << endl;
    for(auto x:m)
        cout << x.first << " : " << x.second << endl;

    vector<vector<int>> v;
    for(auto a: m)
    {
        v.push_back({a.second, a.first});
    }

    for(auto t: v)
    {
        for(auto p: t)
            cout << p << " ";
        cout << endl;
    }    

    sort(v.begin(), v.end(), cmp);
    cout << "after calling sort : " << endl;
    for(auto t: v)
    {
        for(auto p: t)
            cout << p << " ";
        cout << endl;
    }    

    vector<int> ans;
    for(auto a:v)
    {
        int x = a[0];
        while(x--)
        {
            ans.push_back(a[1]);
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {-1, 1, -6, 4, 5, -6, 1, 4, 1};
    Solution s;
    vector<int> ans = s.frequencySort(nums);
    for(auto m : ans)
        cout << m << " ";
    return 0;
}