// Min-Stack in O(1):
// Design a stack that supports push, pop, top, and getMin all in constant time.
// Hint: Use an auxiliary stack to track minimums.
//create a stack of user inputs of n size
//Don't use vector or inbuilt stack
#include <iostream>
using namespace std;
class MinStack {
    int* mainStack;
    int* minStack;
    int topMain;
    int topMin;
    int capacity;
public:
    MinStack(int size) {
        capacity = size;
        mainStack = new int[size];
        minStack = new int[size];
        topMain = -1;
        topMin = -1;
    }
    void push(int value) 
    {
        if (topMain == capacity - 1) 
        {
            cout << "Stack Overflow\n";
            return;
        }
        mainStack[++topMain] = value;
        if (topMin == -1 || value <= minStack[topMin]) 
        {
            minStack[++topMin] = value;
        }
    }
    void pop() 
    {
        if (topMain == -1) 
        {
            cout << "Stack Underflow\n";
            return;
        }
        int poppedValue = mainStack[topMain--];
        cout<<"Popped value: "<<poppedValue<<endl;
        if (poppedValue == minStack[topMin]) 
        {
            topMin--;
        }
    }
    int top() 
    {
        if (topMain == -1) 
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return mainStack[topMain];
    }
    int getMin() {
        if (topMin == -1) 
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return minStack[topMin];
    }
    ~MinStack() 
    {
        delete[] mainStack;
        delete[] minStack;
    }
};
int main() 
{
    int n;
    cout << "Enter the size of the Min Stack: ";
    cin >> n;

    MinStack minStack(n);
    int choice, value;

    do {
        cout << "\nMin Stack Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Get Min\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                minStack.push(value);
                break;
            case 2:
                minStack.pop();
                break;
            case 3:
                cout << "Top element: " << minStack.top() << endl;
                break;
            case 4:
                cout << "Minimum element: " << minStack.getMin() << endl;
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

//Explanation:
//1. We define a MinStack class with two arrays: mainStack for regular stack operations 
//   and minStack to keep track of the minimum elements.
//2. The push operation adds an element to mainStack and updates minStack if the new
//   element is smaller than or equal to the current minimum.
//3. The pop operation removes the top element from mainStack and also updates minStack
//   if the popped element is the current minimum.
//4. The top operation returns the top element of mainStack.
//5. The getMin operation returns the top element of minStack, which is the minimum element.
//6. The main function provides a simple menu-driven interface for the user to interact
//   with the MinStack.
//Time Complexity: All operations (push, pop, top, getMin) run in O(1) time.
//Space Complexity: O(n) for storing elements in both stacks.
//when is the destructor called?
//The destructor is called when an object of the MinStack class goes out of scope or is explicitly deleted.