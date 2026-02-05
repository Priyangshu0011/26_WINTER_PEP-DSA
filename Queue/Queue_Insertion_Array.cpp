//Insertion in Queue using Array
#include <iostream>
using namespace std;
int main()
{
    int n, front = -1, rear = -1;
    cout << "Enter the size of the queue: ";
    cin >> n;
    int* queue = new int[n];

    int choice, value;
    do
    {
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            if (rear == n - 1)
            {
                cout << "Queue is full!" << endl;
            }
            else
            {
                cout << "Enter value to enqueue: ";
                cin >> value;
                rear++;
                queue[rear] = value;
                if (front == -1) front = 0; // First element enqueued
            }
            break;
        case 2:
            if (front == -1 || front > rear)
            {
                cout << "Queue is empty!" << endl;
            }
            else
            {
                cout << "Dequeued value: " << queue[front] << endl;
                front++;
            }
            break;
        case 3:
            if (front == -1 || front > rear)
            {
                cout << "Queue is empty!" << endl;
            }
            else
            {
                cout << "Queue elements: ";
                for (int i = front; i <= rear; i++)
                {
                    cout << queue[i] << " ";
                }
                cout << endl;
            }
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    delete[] queue; // Free allocated memory
    return 0;
}