//Implementation of queue using Global Array
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
};
int main()
{
    int n;
    cout<<"Enter size of queue: ";
    cin>>n;
    Queue q;
    for(int i=0;i<n;i++)
    {
        int val;
        cout<<"Enter value to enqueue: ";
        cin>>val;
        q.enqueue(val);
    }
    cout<<"Queue elements: ";
    q.display();
    return 0;
}

//Explanation:
// This code implements a queue using a global array in C++. The Queue class has methods to enqueue, dequeue, get the front element, check if the queue is empty, and display the queue elements. The main function allows the user to input the size of the queue and the elements to be enqueued, then displays the queue contents.
// The queue has a maximum size defined by the constant MAX.
// The enqueue method adds an element to the rear of the queue, while the dequeue method removes an element from the front. The getFront method retrieves the front element without removing it. The isEmpty method checks if the queue is empty, and the display method prints all elements in the queue.