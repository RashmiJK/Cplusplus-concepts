/* simple string wrapper class
 */

#include "strc.h"
#include <cstdio>
#include <cstring>
#include <utility>
#include <memory>
#include <iostream>

using namespace std;

void strc::msg(const char* s)
{
    if(data)
        cout << __strc_class << " : " << s << "(" << data << ")" << endl;
    else
        cout << __strc_class << " : " << s;

    fflush(stdout);
}

strc::strc() : data(nullptr)
{
    msg("default ctor");
}

strc::strc(const char* s)
{
    size_t slen = strnlen(s, _maxlen);
    data = new char[slen + 1];
    data[slen] = 0;
    memcpy(data, s, slen);
    msg("cstring ctor");
}

strc::strc(const strc & rhs)
{
    size_t slen = strnlen(rhs.data, _maxlen);
    data = new char[slen + 1];
    data[slen] = 0;
    memcpy(data, rhs.data, slen);
    msg("copy ctor");
}

strc::strc(strc && rhs)
{
    data = std::move(rhs.data);
    rhs.data = nullptr;
    msg("move ctor");
}

strc::~strc()
{
    msg("dtor");
    delete [] data;
}

void strc::swap(strc& o)
{
    msg("strc swap");
    std::swap(this->data, o.data);
}

strc& strc::operator = (strc rhs)
{
    swap(rhs);
    msg("copy and swap = ");
    return *this;
}

const char * strc::value() const
{
    return data;
}

strc::operator const char * () const
{
    return value();
}

