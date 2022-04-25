#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct Node
{
        int data;
        struct Node * next;
}Node;

void insert(Node ** head, int newData);
void printList(Node * head);
void deleteNode(Node ** head, int position);

int main()
{
    Node * head = NULL;

    insert(&head, 7);
    insert(&head, 1);
    insert(&head, 3);
    insert(&head, 8);
    insert(&head, 2);
    insert(&head, 6);

    printList(head);

    deleteNode(&head, 0);
    printList(head);

    deleteNode(&head, 2);
    printList(head);

    return 0;
}

void insert(Node ** head, int newData)
{
    Node * newNode = (Node *) malloc(sizeof(Node));
    newNode -> data = newData;
    newNode -> next = *head;
    *head = newNode;
}

void printList(Node * head)
{
    while(head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void deleteNode(Node ** head, int position)
{
    if(*head == NULL)
    {
        cout << "List is empty, hence unable to delete any element" << endl;
        return;
    }

    Node * temp = *head;

    if(position == 0)
    {
        // deleting head
        *head = temp -> next;
        free(temp);
        return;
    }

    for(int i = 0; temp != NULL && i<(position-1) ; i++)
        temp = temp->next;

    if(temp == NULL || temp->next == NULL)
        return;

    Node * next = temp->next->next;
    temp->next = next;
    free(temp->next);
}