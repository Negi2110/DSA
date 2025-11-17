#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
    node(int val) {
        data = val;
        next = nullptr;
    }
};

void nodeAtHead(node *&head, int val) {
    node *var = new node(val);
    var->next = head;
    head = var;
}

void nodeAtLast(node *&head, int val) {
    if (head == nullptr) {             
        head = new node(val);
        return;
    }
    node *curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = new node(val);
}

void nodeAtPositionFromStart(node *&head, int pos, int val) {
    if (pos < 0) {
        cout << "Invalid position\n";
        return;
    }
    if (pos == 0 || head == nullptr) { 
        nodeAtHead(head, val);
        return;
    }

    node *curr = head;
    int count = 0;
    // move curr to node at index (pos-1) if possible
    while (curr != nullptr && count < pos - 1) {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) {
        cout << "Out of bounds (position too large)\n";
        return;
    }

    node *newNode = new node(val);
    newNode->next = curr->next;
    curr->next = newNode;
}

void printLL(node *head) {
    node *curr = head;
    while (curr != nullptr) {
        cout << "the value of node is: " << curr->data << endl;
        curr = curr->next;
    }
}

int main() {
    node *head = nullptr;

    nodeAtHead(head, 5);
    nodeAtHead(head, 6);
    nodeAtHead(head, 7);
    printLL(head);
    cout << "skipped" << endl;

    nodeAtLast(head, 11);
    nodeAtLast(head, 12);
    nodeAtLast(head, 13);
    printLL(head);
    cout << "skipped" << endl;

    nodeAtPositionFromStart(head, 3, 45);
    nodeAtPositionFromStart(head, 5, 35);
    nodeAtPositionFromStart(head, 6, 25);
    printLL(head);

    return 0;
}
