//check whether a linked list is palindrome or not

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

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL)
        return true;

    Node* slow = head;
    Node* fast = head;

    // find middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse second half
    Node* secondHalf = reverseList(slow);
    Node* firstHalf = head;

    // compare both halves
    while (secondHalf != NULL) {
        if (firstHalf->data != secondHalf->data)
            return false;
        firstHalf = firstHalf->next;
        secondHalf = secondHalf->next;
    }

    return true;
}

int main() {

    int n;
    cin >> n;

    if (n <= 0) return 0;

    int x;
    cin >> x;

    Node* head = new Node(x);
    Node* tail = head;

    // take remaining inputs
    for (int i = 2; i <= n; i++) {
        cin >> x;
        tail->next = new Node(x);
        tail = tail->next;
    }

    if (isPalindrome(head))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}

