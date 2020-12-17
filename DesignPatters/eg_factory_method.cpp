#include <iostream>

/* The product interface declares the operations that all concrete products must implement */
class Product
{
	public:
		virtual ~Product() {}
		virtual std::string Operation() const = 0; /* const here indicates that this 
																									method is not supposed to change 
																									the data of the class */
};

/* Concrete Products provide various implementations of the product interface */
class ConcreteProduct1 : public Product
{
	public:
		std::string Operation() const override
		{
			return "{Result of the ConcreteProduct1}";
		}
};

class ConcreteProduct2 : public Product
{
	public:
		std::string Operation() const override
		{
			return "{Result of the ConcreteProduct2}";
		}
};

/* The creator class declares the factory method that is supposed to return an object of a 
 * Product class. The Creator's subclasses usually provide the implementation of this method */
class Creator
{
	public:
		virtual ~Creator() {};
		virtual Product* FactoryMethod() const = 0;

		std::string SomeOperation() const 
		{
			Product* product = this->FactoryMethod();

			std::string result = "Creator: The same creator's code has just worked with" + product->Operation();
			delete product;
			return result;
		}
};

class ConcreteCreator1 : public Creator
{
		public:
			Product* FactoryMethod() const override
			{
				return new ConcreteProduct1();
			}
};

class ConcreteCreator2 : public Creator
{
		public:
			Product* FactoryMethod() const override
			{
				return new ConcreteProduct2();
			}
};

void ClientCode(const Creator& creator)
{
		std::cout << "Client: I'm not aware of the creator's class, but it still works.\n" << creator.SomeOperation() << std::endl;
}


int main()
{
	std::cout << "App: Launched with the ConcreteCreator1. \n";
	Creator* creator = new ConcreteCreator1();
	ClientCode(*creator);
	std::cout << std::endl;

	Creator* creator2 = new ConcreteCreator2();
	ClientCode(*creator2);

	delete creator;
	delete creator2;

	return 0;
}


