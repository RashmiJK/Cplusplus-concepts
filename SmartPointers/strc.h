/* Simple string wrapper class
 */

#ifndef __STRC_H_
#define __STRC_H_

#include <cstddef>

constexpr const char * __strc_class = "strc"; // constexpr specifies that the value of a variable or function can appear in constant expressions
constexpr const char * __strc_version = "1.1";
constexpr size_t _maxlen = 10240;

class strc
{
    char * data = nullptr;
    void msg(const char*);

    public:
        strc(); // default
        strc(const char * s);
        strc(const strc &); // copy constructor
        strc(strc &&); // universal reference, lvalue reference, move constructor
        ~strc();
        strc& operator = (strc);
        const char * value() const;
        operator const char * () const;
        void swap(strc&);
};

#endif // __STRC_H_