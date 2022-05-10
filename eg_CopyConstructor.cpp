#include <iostream>
#include <string>

using namespace std;

const string unk = "unknown";
const string clone_prefix = "clone-";

class Animal
{
    string _type = "";
    string _name = "";
    string _sound = "";

    public:
        Animal(); // default constructor
        Animal(const string& type, const string& name, const string& sound); // constructor with 3 arguments
        Animal(const Animal&); // copy constructor
        Animal& operator = (const Animal&); // copy operator
        ~Animal(); // default destructor

        void print() const;
};

Animal::Animal() : _type(unk), _name(unk), _sound(unk)
{
    puts("default constructor");
}

Animal::Animal(const string& type, const string& name, const string& sound) : _type(type), _name(name), _sound(sound)
{
    puts("constructor with arguments");
}

Animal::Animal(const Animal& rhs)
{
    puts("copy constructor");
    this->_type = rhs._type;
    this->_name = clone_prefix + rhs._name;
    this->_sound = rhs._sound;
}

Animal::~Animal()
{
    cout << "destructor: "<< this->_name << " the " << this->_type << endl;
}

Animal& Animal::operator = (const Animal& rhs)
{
    puts("copy operator");
    if(this != &rhs)
    {
        this->_type = rhs._type;
        this->_name = clone_prefix + rhs._name;
        this->_sound = rhs._sound;
    }
    else
    {
        puts("same object copy is prohibited");
    }
    return *this;
}

void Animal::print() const
{
    cout << this->_name << " the " << this->_type << " says " << this->_sound << endl;
}

int main()
{
    Animal a;
    a.print();

    const Animal b("cat","fluffy","meow");
    b.print();

    a = b;
    a.print();

    const Animal d = a;
    d.print();
    return 0;
}