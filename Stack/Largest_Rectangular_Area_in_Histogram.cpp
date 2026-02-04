// Largest Rectangular Area in Histogram:
// Use a stack to store indices of increasing bar heights. Calculate area when a lower bar forces a pop. (Hard)
//use array or linked list to implement stack and don't use vector or inbuilt stack
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
};
int largestRectangleArea(int heights[], int n) {
    Stack s(n);
    int maxArea = 0;
    int i = 0;
    while (i < n) {
        if (s.isEmpty() || heights[s.peek()] <= heights[i]) {
            s.push(i++);
        } else {
            int tp = s.pop();
            int area = heights[tp] * (s.isEmpty() ? i : i - s.peek() - 1);
            if (area > maxArea) {
                maxArea = area;
            }
        }
    }
    while (!s.isEmpty()) {
        int tp = s.pop();
        int area = heights[tp] * (s.isEmpty() ? i : i - s.peek() - 1);
        if (area > maxArea) {
            maxArea = area;
        }
    }
    return maxArea;
};
int main() {
    int n;
    cout << "Enter number of bars in histogram: ";
    cin >> n;
    int* heights = new int[n];
    cout << "Enter heights of bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }
    int maxArea = largestRectangleArea(heights, n);
    cout << "Largest Rectangular Area in Histogram: " << maxArea << endl;
    delete[] heights;
    return 0;
}
//Explanation:
//1. We define a Stack class to implement stack operations using an array.
//2. The largestRectangleArea function calculates the largest rectangular area in a histogram.
//3. We iterate through the heights array, pushing indices onto the stack when the current height is greater than or equal to the height at the index stored at the top of the stack.
//4. When we encounter a height less than the height at the top index of the stack, we pop from the stack and calculate the area of the rectangle that can be formed with the popped height as the smallest height.
//5. We continue this process until we have processed all heights, and then we pop any remaining indices from the stack to calculate areas.
//6. The maximum area found during these calculations is returned as the result.


//Approach: 
//The approach uses a stack to efficiently calculate the largest rectangular area in a histogram.
//We maintain a stack of indices of the histogram bars in increasing order of their heights.
//When we encounter a bar with height less than the one at the top of the stack, we pop from the stack and calculate the area for the popped bar.
//This ensures that each bar is processed only once, leading to an O(n) time complexity.    
//Time Complexity: O(n) where n is the number of bars in the histogram.
//Space Complexity: O(n) for the stack used to store indices.
//Note: This implementation assumes that the input heights array is not empty and contains non-negative integers.