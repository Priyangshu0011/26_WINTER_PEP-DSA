//Deleteing a node in linked list
#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

void deleteNode(Node** head_ref, int key)
{
    Node* temp = *head_ref;
    Node* prev = nullptr;

    // If head node itself holds the key to be deleted
    if (temp != nullptr && temp->data == key)
    {
        *head_ref = temp->next; // Changed head
        delete temp;            // Free old head
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != nullptr && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == nullptr) return;

    // Unlink the node from linked list
    prev->next = temp->next;

    delete temp; // Free memory
}

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* node)
{
    while (node != nullptr)
    {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    Node* head = nullptr;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    cout << "Created Linked list is: ";
    printList(head);

    cout << "\nDeleting node with value 1\n";
    deleteNode(&head, 1);
    cout << "Linked list after deletion: ";
    printList(head);

    return 0;
}
