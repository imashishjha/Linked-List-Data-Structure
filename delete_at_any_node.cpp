#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *first = new Node();

//Creating Link List

void createLinkList(int arr[], int n)
{
    Node *t;
    Node *last;

    first->data = arr[0];
    first->next = NULL;

    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node();
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

// Displaying Link List

void Display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << endl;
        cout << " " << endl;
        p = p->next;
    }
}

// Deleting from Link List

void Delete(Node *p, int pos)
{

 if(pos==1){
     
 }
    Node *q = NULL;
    for (int i = 0; i < pos - 1; i++)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    delete (p);
}

int main()
{

    int n, pos;
    cout << "Enter Size of Linked List: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    createLinkList(arr, n);

    Display(first);

    cout << "Enter Index to Delete ";
    cin >> pos;


    Delete(first, pos);

    Display(first);
}
