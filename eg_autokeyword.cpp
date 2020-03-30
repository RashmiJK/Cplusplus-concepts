#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	//create a set of strings
	set<string> st;

	st.insert({"auto", "keyword", "is resolved during runtime"});

	// variable evaluates to iterator to set of string
	for(auto i = st.begin(); i != st.end(); i++)
		cout << *i << " ";

	return 0;
}
