// eg_templateClass_stack.h has the template class implementation
// eg_templateClass_stack.cpp has the caller

#include <exception>
#include <iostream>
#include <string>

using namespace std;

int nums[] = { 1, 2, 3, 4, 5};
const char * strs[] = {"one", "two", "three", "four", "five"};

// simple exception class
class StackException : public std::exception
{
    const char * msg;
    StackException(){}; // no default constructor

    public:
        explicit StackException(const char * s) throw() : msg(s) { }
        const char * what() const throw() {return msg;}
};

// simple fixed size LastInFirstOut stack template
template <typename T>
class Stack 
{
    private:
        static const int defaultSize = 10;
        static const int maxSize = 1000;
        int _size;
        int _top;
        T * stackPtr;

    public:
        explicit Stack(int s = defaultSize);
        ~Stack()
        {
            delete[] stackPtr;
        }
        T & push(const T &);
        T & pop();
        bool isEmpty() const
        {
            return _top < 0;
        }
        bool isFull() const
        {
            return _top >= _size - 1;
        }
        int top() const 
        {
            return _top;
        }
        int size() const
        {
            return _size;
        }

};

template <typename T>
Stack<T>::Stack(int s)
{
    if(s > maxSize || s < 1) throw StackException("invalid staxk size");
    else _size = s;
    stackPtr = new T[_size];
    _top = -1;
}

template <typename T>
T & Stack<T>::push(const T &i)
{
    if(isFull()) throw StackException("stack full");
    return stackPtr[++_top] = i;
}

template <typename T>
T & Stack<T>::pop()
{
    if(isEmpty()) throw StackException("stack empty");
    return stackPtr[_top--];
} 

int main()
{
    try 
    {
        Stack<int> si(5);

        cout << "si size" << si.size() << endl;
        cout << "si top" << si.top() << endl;

        for(int i=0; i<sizeof(nums)/sizeof(nums[0]); i++)
        {
            si.push(nums[i]);
        }

        cout << "si top after pushes" << si.top() << endl;
        cout << "si is" << (si.isFull() ? "" : "not ") << "full" << endl;

        while(!si.isEmpty())
            cout << "popped" << si.pop() << endl;

    }
    catch(StackException & e)
    {
        cout << "Stack error: " << e.what() << endl;
    }

    try
    {    
        Stack<string> ss(5);

        cout << "ss size" << ss.size() << endl;
        cout << "ss top" << ss.top() << endl;

        for(int i = 0; i<sizeof(strs)/sizeof(strs[0]); i++)
        {
            ss.push(strs[i]);
        }

        cout << "ss top after pushes" << ss.top() << endl;
        cout << "ss is" << (ss.isFull() ? "" : "not " )<< "full" << endl;

        while(!ss.isEmpty())
            cout << "popped" << ss.pop() << endl;

    }
    catch(StackException & e)
    {
        cout << "Stack error: " << e.what() << endl;
    }
    
    return 0;
}