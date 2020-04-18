/* Single linked list in C++ class style
 */

#include <iostream>

using namespace std;

template <typename T>
struct node
{
	T data;
	node<T> * next;
};

template <typename T>
class single_linked_list
{
	private:
		node<T> * head;
	public:
		single_linked_list()
		{
			head = NULL;
		}
	
		void print_list()
		{
			if(this->head == NULL)
				cout << "List is empty" << endl;
			else
			{
				node<T> * tmp = this->head;
				do
				{
					cout << "|" << tmp->data << ":" << tmp->next <<"|" << "->";
					tmp = tmp->next;
				}while(tmp != NULL);
			}
			cout << endl;
		}
	
		void insert_last(node<T> n)
		{
			node<T> *tmp = new node<T>;
			tmp->data = n.data;
			tmp->next = NULL;

			if(this->head == NULL) /* if the list is empty */
			{				
				this->head = tmp;
				cout << "added "<< n.data << endl;
			}
			else
			{
				node<T> * conductor = this->head;
				while(conductor -> next != NULL)
					conductor = conductor->next;
				conductor->next = tmp;
				cout << "added "<< n.data << endl;
			}
		}

		void insert_first(node<T> n)
		{
			node<T> *tmp = new node<T>;
			tmp->data = n.data;
			tmp->next = NULL;
			
			tmp->next = this->head;
			this->head = tmp;
			cout << "added " << n.data << endl;

		}
	
		void delete_item(node<T> x)
		{
			if(this->head == NULL)
				cout << "List is empty; delete is forbid" << endl;
			else
			{				
				if(this->head->data == x.data)
				{
					/* first item is for delete*/
					node<T> *tmp = this->head;
					this->head = this->head->next;
					delete tmp;	
					cout << "Deleted " << x.data << endl;					
				}
				else
				{
					node<T> *n, *p;
					n = p = this->head;
					while(n->next != NULL)
					{
						if(n->data == x.data)
						{
							/* delete n */
							p->next = n->next;
							delete n;
							cout << "Deleted " << x.data << endl;
							return;
						}
						else
						{
							p = n;
							n = n->next;
						}
					}
					if(n->data == x.data)
					{
						p->next = NULL;
						delete n;
						cout << "Deleted " << x.data << endl;
					}
					else
						cout << x.data << " not found in the list" << endl;
				}
			}
		}
};

int main()
{
	single_linked_list<int> l;
	node<int> temp = {0, NULL};

	l.print_list();
	cout << endl;
	
	temp.data = 3;
	l.insert_last(temp);
	l.print_list();
	cout << endl;

	temp.data = 4;
	l.insert_last(temp);
	l.print_list();
	cout << endl;
	
	temp.data = 5;
	l.insert_last(temp);
	l.print_list();
	cout << endl;
	
	temp.data = 6;
	l.insert_last(temp);
	l.print_list();
	cout << endl;

	temp.data = 7;
	l.insert_last(temp);
	l.print_list();
	cout << endl;

	temp.data = 8;
	l.insert_first(temp);
	l.print_list();
	cout << endl;

	temp.data = 8;
	l.delete_item(temp);
	l.print_list();
	cout << endl;

	temp.data = 6;
	l.delete_item(temp);
	l.print_list();
	cout << endl;
	
	temp.data = 7;
	l.delete_item(temp);
	l.print_list();
	cout << endl;
	
	temp.data = 5;
	l.delete_item(temp);
	l.print_list();
	cout << endl;

	return 0;
}
	
