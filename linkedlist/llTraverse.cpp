#include <iostream>
using namespace std;
 
struct Node
{
    int data;
    Node *next;
    Node(int val) {
       data = val;
       next= nullptr;
    }
};
 void printLinkedList(Node * head) {
    Node *current =head;
    int count=0;
    while(current != nullptr) {
        cout<<"the value of node is:"<<current->data<<endl;
        current=current->next;
        count++;
    }
    cout<<"the lenght of:"<<count;
 }
int main() {
    Node *head = new Node(5);
    Node *second = new Node(6);
    Node *third = new Node(7);
    Node *fourth = new Node(8);
    
    head->next=second;
    second->next=third;
    third->next=fourth;

    printLinkedList(head);
   
   Node *current =head;
   while( current != nullptr) {
      Node *temp= current;
      current = current->next;
      delete temp;
   }
    return 0;
}