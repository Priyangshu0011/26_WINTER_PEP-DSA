// You are working in a cloud data centre, each server sends a load value every sec u r given an array load[] where load[i] = load at server at sec a server is consider unstable if there exist a future sec where load j<load[0i] task : remove all unstable server a server is stable when there is no smaller value exist to its right keep the min values at the left. Don't use any inbuilt stack or vector. Use monotonic stack.
// Ex.: 8 4 6 2 3 
// Output : 2 3
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    stack<int> st;      // monotonic increasing stack (from top)
    stack<int> out;     // to print bottom -> top without reversing array

    // Traverse from right to left
    for(int i = n - 1; i >= 0; i--) {
        if(st.empty() || arr[i] <= st.top()) {
            st.push(arr[i]);    // this is stable
        }
        // else skip unstable server
    }

    // Now st contains elements in reverse order (right->left)
    // Move to 'out' so we print left->right naturally
    while(!st.empty()) {
        // out.push(st.top());
        cout << st.top() << " ";
        st.pop();
    }

    // Print results
    // while(!out.empty()) {
        
    //     out.pop();
    // }

    return 0;
}
