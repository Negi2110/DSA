#include <iostream>
using namespace std;
struct node {
    int data;
    node *next;
    node(int val) {
        data=val;
        next=nullptr;
    }
};
void insertAtHead(node *&head,int val) {
    node *var= new node(val);
    var->next=head;
    head=var;
}
void printLinkedList(node *head) {
    node *curr =head;
    while(curr != nullptr) {
        cout<<"the value of the node is:"<<curr->data<<endl;
        curr=curr->next;
    }
}
void deleteNode(node *&head,int val) {
    if (head == nullptr){
        cout<<"no head exist"<<endl;
        return;
    }
    if(head->data == val) {
        node *temp= head;
        head=head->next;
        delete temp;
        cout<<"deleted the value"<<val<<endl;
        return;
    }

    // Case 3: delete from middle or end
    node *prev = head;
    node *curr = head->next;

    while (curr != nullptr) {
        if (curr->data == val) {

            prev->next = curr->next;   // unlink
            delete curr;               // free memory
            return;                    // done

        } else {
            prev = curr;               // move prev forward
            curr = curr->next;         // move curr forward
        }
    }
    return;
    

}
int main() {
    node *head = new node(3);
    insertAtHead(head,4);
    insertAtHead(head,5);
    insertAtHead(head,6);
    insertAtHead(head,7);
    printLinkedList(head);

    deleteNode(head,7);
    deleteNode(head,3);
    printLinkedList(head);
    return 0;
}