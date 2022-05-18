#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<string> calculate_negative_balance(const vector<vector<string>>& balance)
{
    map<string, int> account;
    vector<string> answer;

    for(auto record : balance)
    {
        auto lender = record[0];
        auto borrower = record[1];
        auto value = stoi(record[2]);

        if(account.find(lender) != account.end()) // account doesn't exist yet
            account[lender] -= value;
        else
            account[lender] = -value;

        if(account.find(borrower) != account.end()) // account doesn't exist yet
            account[borrower] += value;
        else
            account[borrower] = value;       
    }

    for(auto ele : account)
        cout << ele.first << ele.second << endl;


    auto lowest_balance = 9999;
    for(auto& ele : account)
    {
        if(ele.second < lowest_balance)
            lowest_balance = ele.second;
    }
    
    for(auto& ele : account)
    {
        if(ele.second == lowest_balance)
            answer.push_back(ele.first);
    }
    return answer;
}

int main()
{
    vector<vector<string>> balance;
    vector<string> ans;

    vector<string> entry1{ "Alex", "Blake", "5"};
    balance.push_back(entry1);
    vector<string> entry2{ "Alex", "Casey", "10"};
    balance.push_back(entry2);
    vector<string> entry3{ "Blake", "Casey", "5"};
    balance.push_back(entry3);

    for(auto record : balance)
    {
        for(auto ele : record)            
            cout << ele << " -> ";
        cout << endl;
    }

    ans = calculate_negative_balance(balance);
    for(auto a : ans)
        cout << a << endl;
    return 0;
}