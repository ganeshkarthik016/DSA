#include <bits/stdc++.h>
using namespace std;

// Function to insert element in sorted order
void insert(stack<int>& s, int temp) {
    // Base case: if the stack is empty or temp is larger than the top element
    if (s.empty() || s.top() <= temp) {
        s.push(temp);
        return;
    }
    
    // Otherwise, pop the top element and recursively insert
    int val = s.top();
    s.pop();
    insert(s, temp);
    
    // Push the popped element back
    s.push(val);
}

// Function to sort the stack
void sortStack(stack<int>& s) {
    if (!s.empty()) {
        int temp = s.top();
        s.pop();
        
        sortStack(s);
        
        insert(s, temp);
    }
}

// Main function
int main() {
    stack<int> s;
    s.push(4);
    s.push(1);
    s.push(3);
    s.push(2);

    sortStack(s);

    // Print the sorted stack
    cout << "Sorted stack (descending order): ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
