#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int value) {
        data=value;
        next = nullptr;
    }
};
 int main () {
     Node *head = new Node(5);//first element
     Node *second = new Node(6);
     Node *third= new Node(7);
     head->next = second;
     second->next= third;
     third->next = nullptr;

     Node *current = head;
    while (current != nullptr)
    {
        cout<<"the node is:"<<current->data<<"\n";
        current=current->next;
    }
     
    //  while(head){
    //     cout<<"the node is:"<<head->data<<"\n";
    //     head=head->next;

    //  }
    Node *current = head;
    while (current != nullptr)
    {
        cout<<"the node is:"<<current->data<<"\n";
        current=current->next;
    }
    current =head;
    while (current != nullptr)
    {
        Node *temp= current;
        current=current->next;
        delete temp;
    }
    

    return 0;
    
 }