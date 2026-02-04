// You have to swap the position of kth node 1 from the beginning and one from the ending 
// Ex.: 3 9 14 21 27 -> 3 21 14 9 27

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

Node* swapKthNodes(Node* head, int k) {
    if (!head) return head;

    Node* firstK = head;
    Node* secondK = head;
    Node* current = head;
    int length = 0;

    // Find length of linked list
    while (current) {
        length++;
        current = current->next;
    }

    if (k > length) return head;

    // Move to kth node from start
    for (int i = 1; i < k; i++)
        firstK = firstK->next;

    // Move to kth node from end (length - k + 1)
    for (int i = 1; i < length - k + 1; i++)
        secondK = secondK->next;

    // Swap data
    if (firstK != secondK) {
        int temp = firstK->data;
        firstK->data = secondK->data;
        secondK->data = temp;
    }

    return head;
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

    int n;
    cin >> n;

    if (n <= 0) return 0;

    int x;
    cin >> x;

    Node* head = new Node(x);
    Node* tail = head;

    for (int i = 2; i <= n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    int k;
    cin >> k;

    head = swapKthNodes(head, k);
    printList(head);

    return 0;
}

// You have to swap the position of kth node 1 from the beginning and one from the ending 
// Ex.: 3 9 14 21 27 -> 3 21 14 9 27