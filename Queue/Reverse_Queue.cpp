//You have a queue with some elements reverse that queue using a reverse function
#include <iostream>
using namespace std;
class Queue {
    public:
    static const int MAX = 1000; // Maximum size of the queue
    int arr[MAX];
    int front, rear;
    Queue() : front(-1), rear(-1) {}
    void enqueue(int val) {
        if (rear == MAX - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        arr[++rear] = val;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        front++;
        if (front > rear) {
            front = rear = -1; // Reset queue when empty
        }
    }
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    bool isEmpty() {
        return front == -1;
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    void reverse() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        int temp[MAX];
        int j = 0;
        for (int i = rear; i >= front; i--) {
            temp[j++] = arr[i];
        }
        for (int i = 0; i < j; i++) {
            arr[front + i] = temp[i];
        }
    }
};
int main()
{
    int n;
    cout<<"Enter size of queue: ";
    cin>>n;
    Queue q;
    int choice, val;
    while (true) {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Reverse\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.reverse();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice" << endl;
        }
    }
}
