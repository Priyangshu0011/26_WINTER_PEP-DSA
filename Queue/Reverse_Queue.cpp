//You have a queue with some elements reverse that queue using a reverse function withing the same queue.
#include <iostream>
using namespace std;
class Queue {
    public:
    int front, rear;
    int *arr;
    Queue(int n) : front(-1), rear(-1), arr(new int[n]) {}
    void enqueue(int val, int n) {
         if (rear ==  n - 1) {
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
        //within the same queue we can reverse the queue by swapping the front and rear elements and then moving towards the center
        int i = front, j = rear;    
        while (i < j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
};
int main()
{
    int n;
    cout<<"Enter size of queue: ";
    cin>>n;
    int *arr=new int[n];
    Queue q(n);
    int choice, val;
    while (true) {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Reverse\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> val;
                q.enqueue(val, n);
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
