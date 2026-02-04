// split an ll into n parts (can be random sizes but as equal as possible and in the order of appearance in original ll is maintained) (Don't only create the code sticking solely to the example create a generalized code that works for any linked list and any n value)
// Ex.: 1-2-3-4-5 n=3
// 1. 1-2-3
// 2. 4-5
// 3. 3-4

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
        data = val;
        next = NULL;
    }
};

Node** splitListToParts(Node* head, int n) {
    Node** parts = new Node*[n];
    for (int i = 0; i < n; i++) {
        parts[i] = NULL;
    }

    // Count length
    int length = 0;
    Node* current = head;
    while (current) {
        length++;
        current = current->next;
    }

    int partSize = length / n;
    int extraNodes = length % n;

    current = head;

    for (int i = 0; i < n && current; i++) {
        parts[i] = current;

        int currentPartSize = partSize + (extraNodes > 0 ? 1 : 0);
        if (extraNodes > 0) extraNodes--;

        // Move inside the current part
        for (int j = 1; j < currentPartSize; j++) {
            if (current) {
                current = current->next;
            }
        }

        // Break the list
        if (current) {
            Node* nextHead = current->next;
            current->next = NULL;
            current = nextHead;
        }
    }

    return parts;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {

    int nNodes;
    cin >> nNodes;

    if (nNodes <= 0) return 0;

    int x;
    cin >> x;

    Node* head = new Node(x);
    Node* tail = head;

    // Build linked list from input
    for (int i = 2; i <= nNodes; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    int n;
    cin >> n;

    Node** parts = splitListToParts(head, n);

    for (int i = 0; i < n; i++) {
        printList(parts[i]);
    }

    delete[] parts;
    return 0;
}

