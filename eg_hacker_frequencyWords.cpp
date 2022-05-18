/* given a string of words, find frequencies of individual words.
 */

#include <iostream>
#include <unordered_map>
#include <sstream>


using namespace std;

void printfrequencies(const string& str)
{
    unordered_map<string,int> umap;

    stringstream ss(str);
    string word;
    while(ss >> word)
        umap[word]++;

    unordered_map<string, int>::iterator p;
    for( p = umap.begin(); p != umap.end() ; p++)
    {
      cout << "(" << p->first << ", " << p->second << ")\n";

    }

    cout << umap.at("fun") << endl; // to use uordered_map.at(), key needs to be known   

    try
    {
        cout << umap.at("test") << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    


    cout << umap.bucket_count() << endl;
    cout << umap.count("learning") << endl;
    //umap.insert(make_pair("learningg", 3));
    cout << "find c++ : " << umap.find("c++")->second << endl;

    for(auto i : umap)
    {
        /* i.second = 9; // returned value is a reference to the element */
        cout << i.first << " : " << i.second << endl;
    }
}

int main()
{
    string str = "learning c++ is fun and keep learning c++ and keep having fun";

    printfrequencies(str);
    
    return 0;
}