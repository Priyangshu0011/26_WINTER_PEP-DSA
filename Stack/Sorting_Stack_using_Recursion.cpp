// Sort a Stack using Recursion:
// Sort values without loops, using the call stack as temporary storage.
//create a stack of user inputs of n size
//Don't use any inbuilt stack or vector
#include <iostream>
using namespace std;
class Stack {
    int* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }   
    void push(int x) {
        if (top == capacity - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = x;
    }
    int pop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1;
        }
        return arr[top--];
    }
    int peek() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return -1;
        }
        return arr[top];
    }
    bool isEmpty() {
        return top == -1;
    }
    ~Stack() {
        delete[] arr;
    }

    int size() {
        return top + 1;
    }
};
void insertSorted(Stack &s, int element) {
    if (s.isEmpty() || element > s.peek()) {
        s.push(element);
        return;
    }
    int temp = s.pop();
    insertSorted(s, element);
    s.push(temp);
}
void sortStack(Stack &s) {
    if (s.isEmpty()) {
        return;
    }
    int topElement = s.pop();
    sortStack(s);
    insertSorted(s, topElement);
}
int main() {
    int n;
    cout << "Enter the number of elements in the stack: ";
    cin >> n;

    Stack s(n);
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        s.push(value);
    }

    sortStack(s);

    cout << "Sorted stack (top to bottom):\n";
    while (!s.isEmpty()) {
        cout << s.pop() << " ";
    }
    cout << endl;

    return 0;
}
