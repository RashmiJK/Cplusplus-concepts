/* Example demonstrating overloading a cast operator
 */
#include <iostream>
#include <string>

using namespace std;

class Rational
{
    int _n = 0;
    int _d = 1;

    public:
        Rational (int numerator = 0, int denominator = 1) : _n(numerator), _d(denominator) {}
        Rational (const Rational& rhs) : _n(rhs._n), _d(rhs._d) {}// copy constructor
        ~Rational ();
        int numerator() const { return this->_n; }
        int denominator() const { return this->_d; }
        Rational& operator = ( const Rational& );
        operator std::string () const;
};

/* Copy operator, member function */
Rational& Rational::operator = (const Rational& rhs) // use references as applicable as possible to reduce unnecessary copy operations 
{
    if(this != &rhs)
    {
        this->_n = rhs._n;
        this->_d = rhs._d;
    }
    return *this;
}

Rational::~Rational()
{
    this->_n = 0;
    this->_d = 1;
}

Rational::operator std::string() const
{
    if(this->_d == 1) return std::to_string(_n);
    else return std::to_string(_n) + "/" + std::to_string(_d);
}

Rational operator + (const Rational& lhs, const Rational& rhs)
{
    return Rational(((lhs.numerator() * rhs.denominator()) + (lhs.denominator() * rhs.numerator())), lhs.denominator() * rhs.denominator());
}

Rational operator - (const Rational& lhs, const Rational& rhs)
{
    return Rational(((lhs.numerator() * rhs.denominator()) - (lhs.denominator() * rhs.numerator())), lhs.denominator() * rhs.denominator());
}

Rational operator * (const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.numerator() * rhs.numerator(), lhs.denominator() * rhs.denominator());
}

Rational operator / (const Rational& lhs, const Rational& rhs)
{
    return Rational(lhs.numerator() * rhs.denominator(), lhs.denominator() * rhs.numerator());
}

std::ostream& operator << (std::ostream& o, const Rational &rhs)
{
    return o << std::string(rhs);

}

int main()
{
    Rational a = 7; // 7/1
    cout << "a is: " << a << endl;

    Rational b(5,3); // 5/3
    cout << "b is: " << b << endl;

    Rational c(b); // copy constructor
    cout << "c is: " << c << endl;

    Rational d;
    cout << "d is: " << d << endl;
    d = c; // assignment operator
    cout << "d is: " << d << endl;

    Rational& e = d;
    d = e; // assignment to self
    cout << "e is: " << e << endl;


    cout << a << " + " << b << " = " << a+b << endl;
    cout << a << " - " << b << " = " << a-b << endl;
    cout << a << " * " << b << " = " << a*b << endl;
    cout << a << " / " << b << " = " << a/b << endl;

    string s = "Rational value is: ";
    s += (std::string) b;
    cout << s << endl; 

    return 0;
}