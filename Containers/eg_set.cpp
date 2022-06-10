/* std::set and variants example
 * Change set to multiset to notice how the multiset allows duplicates
 * Change multiset to unordered_set to see how the ordering disappears
 */

#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

int main()
{
	set<int> this_set;
	int temp;

	cout << "Insterting..." << endl;
	while(temp >= 0)
	{
		cout<<"Enter number: ";
		cin >> temp;

		if(temp >= 0)
			this_set.insert(temp);
	}

	cout << "{  ";
	for(auto it = this_set.begin(); it!=this_set.end(); it++)
		cout << *it << "\t";
	cout<<"}"<<endl;

	temp = 0;
	cout << "Removing..."<<endl;

	while(temp >= 0)
	{
		cout << "Enter number: ";
		cin >> temp;
		if(temp >= 0)
			this_set.erase(temp); /* addressing by content */
	}	

	cout << "{  ";
	for(auto it = this_set.begin(); it!=this_set.end(); it++)
		cout << *it << "\t";
	cout<<"}"<<endl;

	return 0;
}

