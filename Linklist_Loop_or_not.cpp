// You have given a link list,  u have to check whther link list is looped or not
// a link list is said to be loop link list if it last node pointing to itself
// if its last node is not pointing to itself then it is not called loop linklist


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


// I am going to take two pointers p and q, and moving p by 1 node and q by two node
// if this link list is forming loop, then it is pretty evident that both nodes will meet each other again

int isLoop(){
    Node *p, *q;
    p=q= first;

    do{
        p=p->next;
        q=q->next;
        if(q != NULL){
            q= q->next;
        }else return 0;
    }while (p and q and p != q);

    if(p == q){
        return 1;
    }else return 0;
    
}

// I am also creating a function for making our linear linst into loop
// i am taking pos which will linked to last node from the user
void makeLoop(int pos, int size){
    Node *p= first;
    Node *q= first;
   for(int i=0; i< pos-1; i++){
       p=p->next;
   }

   for(int i=0; i< pos-1; i++){
       p=p->next;
   }
   for(int i=0; i< size-1; i++){
        q=q->next;
   }
   
   q->next = p;

}



int main(){
    int n;
    cout << "Enter size of Linked List: ";
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    createLinkList(arr, n);
    makeLoop(n-3, n);
    cout<<isLoop();

}