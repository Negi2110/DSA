#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

void addNodeAtHead(node *&head, int val) {
    node *curr = new node(val);
    curr->next = head;
    head=curr;

}
int findl(node*head) {
    node *curr = head;
    int count=0;
    while(curr != nullptr) {
        count++;
        curr=curr->next;
    }
    return count;
}
void removeNthNode(node *head,int pos) {
    
    node * dummy = new node(0);
    dummy->next=head;
    head=dummy;
    int l= findl(head);
    
    node *first = head;
    node *second=head;
    int n=l-n-1;
    node *curr=head;
    while(n){
        curr= curr->next;
    }
    node *nodedelet= curr->next;
    curr->next=nodedelet->next;
    delete nodedelet;
    
}
void printll(node *head) {
    node *temp=head;
    while(temp !=nullptr) {
        
    cout<<"the value of node is:"<<temp->data<<endl;
    temp=temp->next;
    }
}
int main()
{
    node *head= nullptr;
    addNodeAtHead(head,65);
    addNodeAtHead(head,6);
    addNodeAtHead(head,5);
    addNodeAtHead(head,3);
    addNodeAtHead(head,25);
    addNodeAtHead(head,95);
    addNodeAtHead(head,15);
    printll(head);
    removeNthNode(head,2);
    printll(head);
    return 0;
}
