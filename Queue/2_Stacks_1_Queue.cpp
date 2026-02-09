//Implementation of 2 Stacks using 1 Queue. Implementation of FIFO using LIFO.
//Without using inbuilt queue and stack libraries.
#include <iostream>
using namespace std;

// Node for queue
class QNode {
public:
    int val;
    int stackID;     // identifies stack1 or stack2
    QNode* next;

    QNode(int v, int id) {
        val = v;
        stackID = id;
        next = nullptr;
    }
};

// Queue implemented using linked list
class OneQueue {
public:
    QNode* front;
    QNode* rear;

    OneQueue() {
        front = rear = nullptr;
    }

    bool empty() {
        return front == nullptr;
    }

    // push element at rear
    void push(int v, int id) {
        QNode* temp = new QNode(v, id);
        if (rear == nullptr) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    // pop element from front
    QNode* pop() {
        if (front == nullptr) return nullptr;
        QNode* temp = front;
        front = front->next;
        if (front == nullptr) rear = nullptr;
        return temp;
    }

    // rotate queue (move front to rear)
    void rotate() {
        if (front == nullptr || front == rear) return;
        QNode* temp = pop();
        rear->next = temp;
        rear = temp;
        temp->next = nullptr;
    }
};

// Two stacks implemented using a single queue
class TwoStacks {
public:
    OneQueue q;

    // Count how many elements belong to Stack1 & Stack2
    int count1 = 0;
    int count2 = 0;

    // Push element into Stack1
    void push1(int x) {
        q.push(x, 1);
        count1++;

        // rotate all older elements behind the new one
        int rotateCount = (count1 + count2 - 1);
        while (rotateCount--) q.rotate();
    }

    // Push element into Stack2
    void push2(int x) {
        q.push(x, 2);
        count2++;

        // rotate all older elements behind the new one
        int rotateCount = (count1 + count2 - 1);
        while (rotateCount--) q.rotate();
    }

    // Pop from Stack1
    int pop1() {
        if (count1 == 0) return -1;

        while (true) {
            QNode* temp = q.pop();
            count1--;
            int value = temp->val;
            delete temp;
            return value;
        }
    }

    // Pop from Stack2
    int pop2() {
        if (count2 == 0) return -1;

        while (true) {
            QNode* temp = q.pop();
            if (temp->stackID == 2) {
                count2--;
                int value = temp->val;
                delete temp;
                return value;
            } else {
                // put Stack1 nodes back
                q.push(temp->val, temp->stackID);
                q.rotate();
                delete temp;
            }
        }
    }
};

int main() {
    TwoStacks st;

    int n;
    cout << "Enter the number of operations: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        int choice, stackNum, value;
        cout << "1. Push\n2. Pop\nEnter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter stack number (1 or 2): ";
            cin >> stackNum;
            cout << "Enter value to push: ";
            cin >> value;
            if (stackNum == 1) {
                st.push1(value);
            } else if (stackNum == 2) {
                st.push2(value);
            } else {
                cout << "Invalid stack number!" << endl;
            }
        } else if (choice == 2) {
            cout << "Enter stack number (1 or 2): ";
            cin >> stackNum;
            if (stackNum == 1) {
                int poppedValue = st.pop1();
                if (poppedValue != -1) {
                    cout << poppedValue << " popped from Stack 1." << endl;
                } else {
                    cout << "Stack 1 is empty!" << endl;
                }
            } else if (stackNum == 2) {
                int poppedValue = st.pop2();
                if (poppedValue != -1) {
                    cout << poppedValue << " popped from Stack 2." << endl;
                } else {
                    cout << "Stack 2 is empty!" << endl;
                }
            } else {
                cout << "Invalid stack number!" << endl;
            }
        } else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

    

