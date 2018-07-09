// Implementation of stack using array

// Input syntax:
// push <element>
// pop
// top
// empty?
// print

#include <bits/stdc++.h>

using namespace std;

template <class T>
class Stack {
private:
    T arr[1000];
    int head;
public:
    Stack(): head(-1) {};
    void push(T elem) {
        if (head == 999) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++head] = elem;
    };
    T pop() {
        T elem = INT_MIN;
        if (head == -1) {
            return elem;
        }
        elem = arr[head--];
        return elem;
    };
    bool isEmpty() {
        if (head != -1) {
            return false;
        }
        return true;
    };
    T top() {
        T elem = INT_MIN;
        if (head == -1) {
            return elem;
        }
        elem = arr[head];
        return elem;
    };
    void print() {
        if (this->isEmpty()) {
            cout << "Stack Empty!" << endl;
            return;
        }
        cout << "top -> ";
        for (int i = head; i > 0; i--) {
            cout << arr[i] << ", ";
        }
        cout << arr[0] << endl;
    };
};

int main() {
    int t;
    Stack<int> st;
    cin >> t;
    while (t--) {
        char inp[10];
        scanf(" %s", inp);
        if (strcmp(inp, "push") == 0) {
            int x;
            scanf(" %i", &x);
            st.push(x);
        }
        else if (strcmp(inp, "pop") == 0) {
            int ans = st.pop();
            if (ans == INT_MIN) {
                cout << "Stack Underflow!" << endl;
                continue;
            }
            cout << ans << " popped out.\n";
        }
        else if (strcmp(inp, "top") == 0) {
            int ans = st.top();
            if (ans == INT_MIN) {
                cout << "Stack Empty!" << endl;
                continue;
            }
            cout << ans << " is top element.\n";
        }
        else if (strcmp(inp, "empty?") == 0) {
            cout << (st.isEmpty() ? "Yes" : "No") << endl;
        }
        else if (strcmp(inp, "print") == 0) {
            st.print();
        }
        else {
            cout << "\nValid Options:" << endl;
            cout << "push <element>\npop\ntop\nempty?\nprint\n\n";
            t++;
        }
    }
}
