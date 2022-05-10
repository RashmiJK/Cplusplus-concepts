#include <iostream>

using namespace std;

class Rational
{
    int _n = 0;
    int _d = 1;

    public:
        Rational(const int numerator = 0, const int denominator = 1):_n(numerator), _d(denominator) { }
        Rational(const Rational& rhs) : _n(rhs._n), _d(rhs._d) { } // copy constructor
        ~Rational ();
        int numerator() const { return _n;}
        int denominator() const { return _d;}
        Rational& operator = (const Rational&); // copy operator
        Rational operator + (const Rational&) const;
        Rational operator - (const Rational&) const;
        Rational operator * (const Rational&) const;
        Rational operator / (const Rational&) const;
};

Rational& Rational::operator = (const Rational& rhs)
{
    if(this != &rhs)
    {
        _n = rhs._n;
        _d = rhs._d;
    }
    return *this;
}

Rational Rational::operator + (const Rational& rhs) const
{
    return Rational(((this->_n * rhs._d) + (this->_d * rhs._n)), this->_d * rhs._d);
}

Rational Rational::operator - (const Rational& rhs) const
{
    return Rational(((this->_n * rhs._d) - (this->_d * rhs._n)), this->_d * rhs._d);
}

Rational Rational::operator * (const Rational& rhs) const
{
    return Rational(this->_n * rhs._n,this->_d * rhs._d);
}

Rational Rational::operator / (const Rational& rhs) const
{
    return Rational(this->_n * rhs._d,this->_d * rhs._n);
}

Rational:: ~Rational()
{
    _n = 0;
    _d = 1;
}


// for std::out non-member operator
std::ostream& operator << (std::ostream &o, const Rational &r)
{
    if(r.denominator() == 1) return o << r.numerator();
    else
    {
        return o << r.numerator() << "/" << r.denominator();
    }
}

int main()
{
    Rational a = 7; // 7/1
    cout << "a is: " << a << endl;

    Rational b(5,3); // 5/3
    cout << "b is: " << b << endl;

    Rational c = b; //copy constructor
    cout << "c is: " << c << endl;

    Rational d;
    cout << "d is: " << d << endl;
    d = c;
    cout << "d is: " << d << endl;

    Rational& e = d; // reference
    d = e;     // assignment to self!
    cout << "e is: "<< e << endl;

    e = e+a;
    cout << "after e+a did d change?" << "d is: " << d << endl;
    cout << "after e+a did d change?" << "e is: "<< e << endl;

    cout << a << " + " << b << " = " << a+b << endl;
    cout << a << " - " << b << " = " << a-b << endl;
    cout << a << " * " << b << " = " << a*b << endl;
    cout << a << " / " << b << " = " << a/b << endl;

    return 0;
}
