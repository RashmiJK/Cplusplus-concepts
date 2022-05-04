// auto keyword for type inference

#include <iostream>
//#include <bits/stdc++.h>
#include <set>
#include <string>

using namespace std;

template <typename lT, typename rT>
void tf(const lT & lhs, const rT & rhs)
{
	auto z = lhs+rhs;
	cout << "z is " << z << endl;
	cout << "Type of z is " << typeid(z).name() << endl;
}

int main()
{
	//create a set of strings
	set<string> st;
	const char * cstr = "this is a c string";
	const string sclass = string("this is a string class string");

	st.insert({"auto", "keyword", "is resolved during runtime"});

	// variable evaluates to iterator to set of string
	for(auto i = st.begin(); i != st.end(); i++)
		cout << *i << " ";

	tf<string, const char *>(sclass, cstr);
	
	return 0;
}
