#include <iostream>
#include <fstream>
#include <iostream>

using namespace std;

// helper class for runtime polymorphism demo below
class B
{
    public:
        virtual ~B() = default;
        virtual void bar()
        {
            cout << "B::bar\n";
        }
};

class D : public B // default type becomes private
{
    public:
        D()
        {
            cout << "D::D\n";
        }
        ~D()
        {
            cout << "D:;~D\n";
        }
        void bar() override
        {
            cout << "D::bar\n";
        }
};

// a function consuming a unique_ptr can take it by value or by rvalue reference
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)
{
    p->bar();
    return p;
}

// helper function for the custom deleter demo below
void close_file(std::FILE* fp)
{
    std::fclose(fp);
}

//unique_pointer based linked list demo
class List
{
    struct Node
    {
        int data;
        std::unique_ptr<Node> next;
    };

    std::unique_ptr<Node> head;

    ~List()
    {
        while(head)
            head = std::move(head->next);
    }

    void push(int data)
    {
        head = std::unique_ptr<Node> (new Node{data, std::move(head)});
    }
};

int main()
{
    std::cout << "1) Unique ownership semantics demo\n";
    {
        // create a uniquely owned resource
        std::unique_ptr<D> p = std::make_unique<D>();
        cout << "p : " << p << endl;

        // Transfer ownership to 'pass_through'
        // which in turn transfers ownership back through the return value
        std::unique_ptr<D> q = pass_through(std::move(p));
        cout << "q : " << q << endl;

        // 'p' is now in a moved-from 'empty' state, equal to 'nullptr'
        assert(!p); 
        assert(q);
    }

    std::cout << "\n 2) Runtime polymorphism demo\n";
    {
        // create a derived resource and point to it via base type
        std::unique_ptr<B> p = std::make_unique<D>();
        
        // Dynamic deispatch works as expected
        p->bar();

    }

    std::cout << "\n Custom deleter demo";
    std::ofstream("demo.txt") << 'x'; // prepare the file to read
    {
        using unique_file_t = std::unique_ptr<std::FILE, decltype(&close_file)>;
    }
    
}