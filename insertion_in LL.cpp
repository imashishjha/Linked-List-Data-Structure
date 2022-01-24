#include <iostream>
using namespace std;


struct Node{
    int data;
    struct Node* next;
};

Node* first = new Node();

void CreateLL(int arr[], int n){
   
     Node *t,*last;
    
    first->data = arr[0];
    first->next = NULL;
    last =first;
   
    for(int i=1; i<n; i++){
          t= new Node();
          t->data = arr[i];
          t->next = NULL;
          last->next = t;
          last =t;
    }

}


void InsertAtStart(int n){
     Node* p;
     p->data = n;
     p->next= first;
     first =p;
}

void InsertwithinLL(int pos, int ele){

    Node *p, *t;
    p=first;
    for(int i=0;i<pos-1; i++){
        p= p->next;
    }

    t->data = ele;
    t->next= p->next;
    p->next = t;
}

void Display(Node* p){
    while (p != NULL)
    {
        cout<<p->data<<endl;
        p= p->next;
    }
    
}

int main(){

    int n, k, ele,pos;
    cout<<"Enter Size of Linked List: ";
    cin>>n;
    int arr[n];
  
  for(int i=0;i<n;i++){
      cin>>arr[i];
  } 
   
  CreateLL(arr, n);
  Display(first);
//   cout<<"Element to be attached at start: ";
//   cin>>k;
//   InsertAtStart(k);
//   Display(first);

  cout<<"Element to be Inserted within Linked List: ";
  cin>>ele;
  cout<<"Enter Position: ";
  cin>>pos;

  InsertwithinLL(pos-1, ele);

  Display(first);

}