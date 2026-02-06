//A office printer can store 4 print jobs at a time employee send print request continuously once a job is printed the slot is free and should be reused. (Use Circular Queue to solve this problem)
#include <iostream>
using namespace std;
class CircularQueue {
    public:
    static const int MAX = 4; // Maximum size of the circular queue
    int arr[MAX];
    int front, rear;
    CircularQueue() : front(-1), rear(-1) {}
    void enqueue(int val) {
        if ((rear + 1) % MAX == front) {
            cout << "Queue Overflow" << endl;
            return;
        }
        if (front == -1) {
            front = 0;
        }
        rear = (rear + 1) % MAX;
        arr[rear] = val;
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }
        if (front == rear) {
            front = rear = -1; // Reset queue when empty
        } else {
            front = (front + 1) % MAX;
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
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % MAX;
        }
        cout << endl;
    }
};
int main()
{
    CircularQueue q;
    int choice, val;
    while (true) {
        cout << "1. Enqueue Print Job\n2. Dequeue Print Job\n3. View Next Print Job\n4. Display Print Queue\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter print job ID to enqueue: ";
                cin >> val;
                q.enqueue(val);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                val = q.getFront();
                if (val != -1) {
                    cout << "Next print job ID: " << val << endl;
                }
                break;
            case 4:
                q.display();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}

//Explanation:  
// This code implements a circular queue to manage print jobs for an office printer that can store up to 4 print jobs at a time.
// The CircularQueue class provides methods to enqueue and dequeue print jobs, check the front job, and display the current queue.
// The main function provides a simple menu-driven interface for users to interact with the print job queue.