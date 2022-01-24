

// //     +---+------+     +---+------+    +---+------+    +---+------+
// //     | 2 | next |     | 8 | next |    | 10 | next|    | 15 | next |    //Link List 1
// //     +---+------+     +---+------+    +---+------+    +---+------+

// //     +---+------+     +---+------+    +---+------+    +---+------+
// //     | 4 | next |     | 7 | next |    | 12 | next|    |14 | next |    //Link List 2
// //     +---+------+     +---+------+    +---+------+    +---+------+

//        So you have to sorted Link List , U have to merge them so output should look Like this

// //     +---+------+     +---+------+    +---+------+    +---+------+   +---+------+     +---+------+    +---+------+    +---+------+
// //     | 2 | next |     | 4 | next |    | 7 | next |    |8  | next |   | 10 | next |    | 12 | next |   | 14 | next|    |15 | next |
// //     +---+------+     +---+------+    +---+------+    +---+------+   +---+------+     +---+------+    +---+------+    +---+------+

#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *first = new Node();  //pointing to head of first Link List
Node *second = new Node(); //pointing to head of second link list

Node *third = NULL; //pointing  to head node of merged linklist

//here we are creating Linked List 1

void createLinkList1(int arr[], int n)
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

//here we are creating link List 2

void createLinkList2(int arr[], int n)
{
    Node *t;
    Node *last;

    second->data = arr[0];
    second->next = NULL;

    last = second;

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

void MergeLinkList()
{

    Node *last = NULL;

    if (first->data < second->data)
    {

        third = last = first;
        first = first->next;
        third->next = NULL;
    }
    else
    {
        third = last = second;
        second = second->next;
        third->next = NULL;
    }

    while (first != NULL and second != NULL)
    {
        if (first->data < second->data)
        {
            last->next = first;
            last = first;
            first = first->next;
            last->next = NULL;
        }
        else
        {
            last->next = second;
            last = second;
            first = second->next;
            last->next = NULL;
        }
    }
    if (first != NULL)
    {
        last->next = first;
    }
    if (second != NULL)
    {
        last->next = second;
    }
}

int main()
{
    int n1, n2;

    cout << "Enter size of Linked List 1: ";
    cin >> n1;

    int arr1[n1];

    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }

    createLinkList1(arr1, n1);
    Display(first);





    cout << "Enter size of Linked List 2: ";
    cin >> n2;

    int arr2[n2];


    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }

    createLinkList2(arr2, n2);

    Display(second);


    MergeLinkList();
    Display(third);
}


//Conclusion : Program sucessfully Achieved
