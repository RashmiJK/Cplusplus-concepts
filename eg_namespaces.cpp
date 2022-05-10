#include <iostream>
#include <string>
#include <cstdio>

namespace bw
{
    const std::string prefix = "(bw::string) ";

    class string
    {
        std::string _s = "";
        string (); // default constructor in private

        public:
            string (const std::string& s) : _s(prefix + s) { }
            const char * c_str() const { return _s.c_str(); }
            //operator std::string & (void) { return _s; }; // ?
            operator const char * (void) const {return _s.c_str(); } // ?
    };
}; // namespace bw string

int main()
{
    const std::string s1("This is a string");
    std::puts(s1.c_str());

    bw::string s2(s1);
    std::puts(s2);

    return 0;
}