//Implementation of Queue using Linked List
#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class Queue {
    public:
    Node* front;
    Node* rear;
    Queue() : front(nullptr), rear(nullptr) {}
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }
        rear->next = newNode;
        rear = newNode;
    }
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
    int getFront() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void display() {
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
};
int main()
{
    int n;
    cout<<"Enter size of queue: ";
    cin>>n;
    Queue q;
    for(int i=1;i<=n;i++)
    {
        q.enqueue(i*10);
    }
    cout<<"Queue elements: ";
    q.display();
    cout<<"Front element: "<<q.getFront()<<endl;
    q.dequeue();
    cout<<"Queue after one dequeue: ";
    q.display();
    return 0;
}