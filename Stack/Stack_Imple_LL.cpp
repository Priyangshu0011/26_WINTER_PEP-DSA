//Stack Implementation using Linked List
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
class Stack {
    Node* top;
public: 
    Stack() {
        top = nullptr;
    }
    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << value << " pushed to stack." << endl;
    }
    void pop() {
        if (top == nullptr) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return;
        }
        Node* temp = top;
        cout << top->data << " popped from stack." << endl;
        top = top->next;
        delete temp;
    }
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return top->data;
    }
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main() {
    Stack stack;
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
                cout << "Enter value to push: ";
                cin >> value;
                stack.push(value);
                break;

            case 2: // Pop
                stack.pop();
                break;

            case 3: // Peek
                value = stack.peek();
                if (value != -1) {
                    cout << "Top element is: " << value << endl;
                }
                break;

            case 4: // Display
                stack.display();
                break;

            case 5: // Exit
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
