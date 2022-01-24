#include <iostream>
using namespace std;


struct Node
{
    int data;
    Node* next;
};



int sumNodes(Node* p){
    int sum=0;
    while (p != 0){
       sum = sum + p->data;
       p= p->next;
    }
    return sum;
}


int main(){
     
    

}