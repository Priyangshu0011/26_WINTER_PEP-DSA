//Implementation of Priority Queue using Linked List (where higher value has higher priority)
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class PriorityQueue {
public:
    Node* front;
    PriorityQueue() : front(nullptr) {}
    
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (!front || front->data < val) { // Higher value has higher priority
            newNode->next = front;
            front = newNode;
        } else {
            Node* temp = front;
            while (temp->next && temp->next->data >= val) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty() {
        return !front;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    int n;
    cout << "Enter the number of elements to enqueue: ";
    cin >> n;
    PriorityQueue pq;
    while(true)
    {
        cout << "1. Enqueue\n2. Dequeue\n3. Get Front\n4. Display\n5. Exit\nEnter your choice: ";
        int choice, val;
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                pq.enqueue(val);
                break;
            case 2:
                pq.dequeue();
                break;
            case 3:
                cout << "Front element: " << pq.getFront() << endl;
                break;
            case 4:
                pq.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}