#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
    public:
        vector<int> twoSum_uBrute(vector<int>& , int );
        vector<int> twoSum_uHash(vector<int>& , int);
};

vector<int> Solution::twoSum_uBrute(vector<int>& nums, int target) 
{
    vector<int> indices;

    for(int i = 0; i < nums.size() ; i++)
    {
        for(int j = i+1 ; j < nums.size(); j++)
        {
            if(nums[j] == target - nums[i])
            {
            indices.push_back(i);
            indices.push_back(j);
            }
        } 
    }
    return indices;
}

vector<int> Solution::twoSum_uHash(vector<int>& nums, int target) 
{
    map<int, int> m;
    vector<int> indices;

    for(int i = 0; i < nums.size(); i++)
        m[nums[i]] = i;
    
    /*for(auto c : m)
        cout << c.first << " : " << c.second << endl;*/

    for(int i = 0; i < nums.size(); i++)
    {
        int complement = target - nums[i];
        if((m.find(complement) != m.end()) && m.at(complement) != i )
            return {i,m.at(complement)};
    }
    return indices;
}

int main()
{
    vector<int> nums = {-1,5,7,3,6,7};
    int target = 11;
    Solution s;
    vector<int> ans = s.twoSum_uBrute(nums,target);
    for(auto m : ans)
        cout << m << " ";
    cout << endl;
    ans = s.twoSum_uHash(nums,target);
    for(auto m : ans)
        cout << m << " ";
    cout << endl;
    return 0;
}