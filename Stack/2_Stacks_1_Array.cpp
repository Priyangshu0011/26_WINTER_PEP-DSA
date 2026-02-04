//2 Stacks 1 Array Implementation
#include <iostream>
using namespace std;
class TwoStacks {
    int* arr;
    int size;
    int top1, top2;
public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    void push1(int value) {
        if (top1 < top2 - 1) {
            arr[++top1] = value;
            cout << value << " pushed to Stack 1." << endl;
        } else {
            cout << "Stack Overflow! Cannot push to Stack 1." << endl;
        }
    }
    void push2(int value) {
        if (top1 < top2 - 1) {
            arr[--top2] = value;
            cout << value << " pushed to Stack 2." << endl;
        } else {
            cout << "Stack Overflow! Cannot push to Stack 2." << endl;
        }
    }
    void pop1() {
        if (top1 >= 0) {
            cout << arr[top1--] << " popped from Stack 1." << endl;
        } else {
            cout << "Stack Underflow! Cannot pop from Stack 1." << endl;
        }
    }
    void pop2() {
        if (top2 < size) {
            cout << arr[top2++] << " popped from Stack 2." << endl;
        } else {
            cout << "Stack Underflow! Cannot pop from Stack 2." << endl;
        }
    }
};
int main() {
    int n;
    cout << "Enter the size of the array for two stacks: ";
    cin >> n;

    TwoStacks ts(n);
    int choice, stackNum, value;

    do {
        cout << "\nTwo Stacks Operations Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: // Push
                cout << "Enter stack number (1 or 2): ";
                cin >> stackNum;
                cout << "Enter value to push: ";
                cin >> value;
                if (stackNum == 1) {
                    ts.push1(value);
                } else if (stackNum == 2) {
                    ts.push2(value);
                } else {
                    cout << "Invalid stack number!" << endl;
                }
                break;

            case 2: // Pop
                cout << "Enter stack number (1 or 2): ";
                cin >> stackNum;
                if (stackNum == 1) {
                    ts.pop1();
                } else if (stackNum == 2) {
                    ts.pop2();
                } else {
                    cout << "Invalid stack number!" << endl;
                }
                break;

            case 3: // Exit
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}