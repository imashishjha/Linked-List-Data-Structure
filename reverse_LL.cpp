//In this Problem statement u have to do following things
// Create Link List by taking size and Array from User
// Then in Next line u have to reverse the element of Link List
// Try using Iterative method
// Try using Recursion



// Concept of Slidi Pointer
// Let say u have 3 pointers pointing to Nodes : p= first, q= NULL, r= NULL
// Now move r=q, q=p, p=p->next;
// if you continue this process this will be like a group of sliding pointer across Entire Linked List
// Now u can change Nodes direction using q and r and P will be like driver who will pull this slider forward

#include<bits/stdc++.h>

using namespace std;



struct Node
{
    int data;
    struct Node* next;
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

// Method using Sliding Pointer
void ReverseLinkList(Node *p){
  Node *q=NULL;
  Node *r=NULL;

  while(p != NULL){
    r=q;
    q=p;
    p=p->next;
    q->next = r;
  }
    first = q;
}

// Method using Recursion

void ReverseLLrec(Node *p, Node *q){
   
   if(p != NULL){
       ReverseLLrec(p->next, p);
       p->next = q;
   }else{
       first =q;
   }
}

int main(){

   int n;
   cout<<"size: ";
   cin>>n;

   int arr[n];

   for(int i=0; i< n;i++){
       cin>>arr[i];
   }

   createLinkList(arr,n);

//    ReverseLinkList(first);  //Using Sliding Pointer

   ReverseLLrec(first, NULL);  //Using Recursion , my faviorate

   Display(first);

}