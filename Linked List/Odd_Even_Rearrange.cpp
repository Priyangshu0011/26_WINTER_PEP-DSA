// a singly linked list is given where each node contain a int value rearrange the linked list such that where the odd number position appear first followed by the even number position (size is n and 1 based indexing is used).
//For example: 10 20 30 40 50 -> 10 30 50 20 40
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

Node* rearrangeOddEven(Node* head) {
    if (!head || !head->next) 
        return head;

    Node* oddHead = head;
    Node* evenHead = head->next;

    Node* oddTail = oddHead;
    Node* evenTail = evenHead;

    Node* current = evenHead->next;
    int position = 3; // Start from 3rd position

    while (current) {
        if (position % 2 != 0) { 
            oddTail->next = current;
            oddTail = oddTail->next;
        } 
        else { 
            evenTail->next = current;
            evenTail = evenTail->next;
        }
        current = current->next;
        position++;
    }

    oddTail->next = evenHead;  // connect odd list → even list
    evenTail->next = NULL;     // terminate list

    return oddHead;
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

    // create full linked list from user input
    for (int i = 2; i <= n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    head = rearrangeOddEven(head);
    printList(head);

    return 0;
}


