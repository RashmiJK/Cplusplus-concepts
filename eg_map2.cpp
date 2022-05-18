#include <iostream>
#include <iterator>
#include <map>
#include <string>

using namespace std;

void print_map(string_view comment, const map<string,int> & m) // avoid copy by using reference
{
    cout << comment;

    for(const auto& [key, value] : m)
    {
        cout << "[" << key << "] = " << value << "; ";
    }
    cout << "\n";
}

int main()
{
    map<string, int> m = {{"CPU",10}, {"GPU",15}, {"RAM",20}};

    print_map("1) Initial map: ", m);

    m["CPU"] = 25;
    m["SSD"] = 30;

    print_map("1) Updated map: ", m);
    cout << "3) m[UPS] = " << m["UPS"] << "\n";
    print_map("4) Updated map: ", m);

    m.erase("GPU");
    print_map("5) After erase: ", m);

    return 0;
}