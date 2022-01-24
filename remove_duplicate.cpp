
#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *first = new Node();

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

void Display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << endl;
        cout << " " << endl;
        p = p->next;
    }
}

void RemoveDuplicates(Node *p)
{
    Node *q = p->next;
    while (q != NULL)
    {
        if (p->data == q->data)
        {
            p->next = q->next;
            delete (q);
            q = p->next;
        }
        else
        {
            p = q;
            q = q->next;
        }
    }
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

    RemoveDuplicates(first);

    Display(first);
}