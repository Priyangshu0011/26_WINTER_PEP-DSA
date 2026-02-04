// The Celebrity Problem:
// In a party of N people, find the one known by everyone but who knows no one.
// Use a stack to eliminate candidates pairwise.
// let the user put the size of the stack and the elements in it.
// Don't use any inbuilt stack or vector

#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int arr[MAX];
public:
    Stack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(int x) { if (!isFull()) arr[++top] = x; }
    int pop() { return isEmpty() ? -1 : arr[top--]; }
    int peek() { return isEmpty() ? -1 : arr[top]; }
    int size() { return top + 1; }
};

bool knows(int M[][MAX], int a, int b) {
    return M[a][b] == 1;
}

int findCelebrity(int M[][MAX], int n) {
    Stack s;
    for (int i = 0; i < n; i++) s.push(i);

    while (s.size() > 1) {
        int a = s.pop();
        int b = s.pop();
        if (knows(M, a, b)) s.push(b);
        else s.push(a);
    }

    int candidate = s.pop();

    for (int i = 0; i < n; i++) {
        if (i != candidate) {
            if (knows(M, candidate, i) || !knows(M, i, candidate))
                return -1;
        }
    }
    return candidate;
}

int main() {
    int n;
    cin >> n;

    int M[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> M[i][j];

    int celeb = findCelebrity(M, n);
    cout << celeb;
    return 0;
}

//Explanation:
// We use a stack to hold all the people (0 to n-1).
// We repeatedly pop two people off the stack and use the knows function to determine who could still be a celebrity.
// If person A knows person B, then A cannot be a celebrity, so we push B back onto the stack.
// If person A does not know person B, then B cannot be a celebrity, so we push A back onto the stack.
// This process continues until only one person remains on the stack, who is the potential celebrity.
// We then verify this candidate by checking two conditions for all other people:
// 1. The candidate should not know any other person.
// 2. Every other person should know the candidate.
// If both conditions are satisfied, we return the candidate's index; otherwise, we return -1, indicating there is no celebrity.

