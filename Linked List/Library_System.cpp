// A library system - maintain a record list of book return 0 no return +ve means book return move all the +ve at the start and 0s at the last
//Ex: 4 0 5 6 9 0 5 0 3 7
//O/P: 4 5 6 9 5 3 7 0 0 0
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList {
   private:
    Node* head;

   public:
    LinkedList() : head(nullptr) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void rearrange() {
        Node* positiveHead = nullptr;
        Node* positiveTail = nullptr;
        Node* zeroHead = nullptr;
        Node* zeroTail = nullptr;

        Node* current = head;
        while (current) {
            if (current->data > 0) {
                if (!positiveHead) {
                    positiveHead = positiveTail = current;
                } else {
                    positiveTail->next = current;
                    positiveTail = positiveTail->next;
                }
            } else {
                if (!zeroHead) {
                    zeroHead = zeroTail = current;
                } else {
                    zeroTail->next = current;
                    zeroTail = zeroTail->next;
                }
            }
            current = current->next;
        }

        if (positiveTail) {
            positiveTail->next = zeroHead;
        }
        if (zeroTail) {
            zeroTail->next = nullptr;
        }

        head = positiveHead ? positiveHead : zeroHead;
    }
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    LinkedList list;
    list.append(4);
    list.append(0);
    list.append(5);
    list.append(6);
    list.append(9);
    list.append(0);
    list.append(5);
    list.append(0);
    list.append(3);
    list.append(7);

    cout << "Original List: ";
    list.display();

    list.rearrange();

    cout << "Rearranged List: ";
    list.display();

    return 0;
}