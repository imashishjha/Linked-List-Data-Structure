#include <iostream>

using namespace std;
               
// //     This is how a node will visualise      
// //     +---+---------+     
// //     | data | next |    
// //     +---+---------+   

struct Node
{
    int data;
    struct Node *next;                            
    
};

// void DisplayLinkList(Node *p){
//     while(p != NULL){
//        cout<<p->data<<endl;                     // this is also type of traversing through link list
//        p= p->next;
//     }
// }

void DisplayRecursive(Node* p){                     //This is also displaying but using recursion
    if(p != 0){
        cout<<p->data<<endl;
        DisplayRecursive(p->next);
    }
}

int main(){
    //Let say i want to create link list with size 3, so we have to create 3 nodes
    
    Node *first = NULL;
    Node *second = NULL;
    Node *third = NULL;

    // allocate 3 nodes in the heap
    first = new Node();
    second = new Node();
    third = new Node();
 
   first->data = 5;
   first->next = second;
   
   second->data = 8;
   second->next = third;

   third->data = 6;
   third->next = NULL;

// DisplayLinkList(first);
   DisplayRecursive(first);

   return 0;

}

