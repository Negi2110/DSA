#include <iostream>

// Definition for singly-linked list node.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to remove the Nth node from the end using a dummy node.
ListNode* removeNthFromEnd(ListNode* head, int n) {
    // Step 1: Create a dummy node and point its next to head.
    ListNode* dummy = new ListNode(0); // Dummy node with value 0
    dummy->next = head;

    // Step 2: Initialize two pointers, both starting at dummy.
    ListNode* first = dummy;
    ListNode* second = dummy;

    // Step 3: Move 'first' pointer n+1 steps ahead.
    for (int i = 0; i <= n; ++i) {
        first = first->next;
    }

    // Step 4: Move both pointers until 'first' reaches the end.
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // Step 5: 'second' now points to the node before the one to remove.
    ListNode* nodeToDelete = second->next;
    second->next = nodeToDelete->next; // Remove the node

    // Step 6: Clean up memory (if needed)
    delete nodeToDelete;

    // Step 7: Get the new head (could be different if head was removed)
    ListNode* newHead = dummy->next;

    // Step 8: Delete dummy node to avoid memory leak
    delete dummy;

    // Step 9: Return the new head
    return newHead;
}

// Helper function to print the list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val << " ";
        head = head->next;
    }
    std::cout << std::endl;
}

// Example usage
int main() {
    // Create list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    std::cout << "Original list: ";
    printList(head);

    // Remove 2nd node from end (should remove '4')
    head = removeNthFromEnd(head, 2);

    std::cout << "After removing 2nd node from end: ";
    printList(head);

    // Clean up remaining nodes
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}