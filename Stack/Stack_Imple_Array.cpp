// Stack impelementation using array of n size stack and use switch case
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the stack: ";
    cin >> n;

    int* stack = new int[n]; // Dynamically allocate an array of size n for the stack
    int top = -1;

    int choice, value;

    do {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Push
                if (top == n - 1) {
                    cout << "Stack Overflow! Cannot push " << endl;
                } else {
                    cout << "Enter value to push: ";
                    cin >> value;
                    stack[++top] = value;
                    cout << value << " pushed to stack." << endl;
                }
                break;

            case 2: // Pop
                if (top == -1) {
                    cout << "Stack Underflow! Cannot pop." << endl;
                } else {
                    cout << stack[top--] << " popped from stack." << endl;
                }
                break;

            case 3: // Peek
                if (top == -1) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Top element is: " << stack[top] << endl;
                }
                break;

            case 4: // Display
                if (top == -1) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack elements: ";
                    for (int i = top; i >= 0; i--) {
                        cout << stack[i] << " ";
                    }
                    cout << endl;
                }
                break;

            case 5: // Exit
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    delete[] stack;
    return 0;
}
        

