//Implementation of Priority Queue using Array (where higher value has higher priority) 
//Don't use MAX  size but size will be given by user at runtime
#include <iostream>
using namespace std;
class PriorityQueue {
public:
    int front, rear;
    int capacity;
    int *arr;
    PriorityQueue(int n) : front(-1), rear(-1), capacity(n), arr(new int[n]) {};
    
    void enqueue(int val) {
        if (rear == capacity - 1) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear++;
        arr[rear] = val;
        // After adding the new element, we need to maintain the priority order
        for (int i = rear; i > front; i--) {
            if (arr[i] > arr[i - 1]) { // Higher value has higher priority
                swap(arr[i], arr[i - 1]);
            } else {
                break; // No need to check further if the order is correct
            }
        }
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
};
int main()
{
    int n;
    cout<<"Enter size of priority queue: ";
    cin>>n;
    PriorityQueue pq(n);
    int choice, val;
    while (true) {
        cout << "1. Enqueue\n2. Dequeue\n3. View Front\n4. Display Queue\n5. Exit\n";
        cout << "Enter your choice: ";
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
                cout << "Queue elements: ";
                pq.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}

