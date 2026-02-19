//
#include <iostream>
using namespace std;
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node *next; // Pointer to the next node in the same level
    Node(int val) : data(val), left(nullptr), right(nullptr), next(nullptr) {}
};
class Solution {
public:
    void connect(Node* root) {
        if (!root) return;
        Node* current = root; // Start with the root node
        while (current) {
            Node* dummy = new Node(0); // Dummy node to build the next level's linked list
            Node* tail = dummy; // Tail pointer for the next level
            while (current) {
                if (current->left) {
                    tail->next = current->left; // Connect left child
                    tail = tail->next; // Move tail
                }
                if (current->right) {
                    tail->next = current->right; // Connect right child
                    tail = tail->next; // Move tail
                }
                current = current->next; // Move to the next node in the same level
            }
            current = dummy->next; // Move to the next level
            delete dummy; // Clean up the dummy node
        }
    }
};
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);

    Solution sol;
    sol.connect(root);

    // Print the next pointers for each level
    Node* current = root;
    while (current) {
        Node* temp = current;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        current = current->left; // Move to the next level
    }

    return 0;
}