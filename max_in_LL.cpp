#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
};

Node *first = new Node();
Node *t = first->next;

int ans= INT_MIN;

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


void getMax(Node* p){
    if(p == NULL){
        return;
    }

    ans = max(ans, p->data);
    return getMax(p->next);
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

int main()
{
    int n;
    cout << "Enter size of Linked List: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    createLinkList(arr, n);
    Display(first);
    getMax(first);
    cout << ans;
    
}