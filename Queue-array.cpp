// Implementation of Queue using arrays

#include <bits/stdc++.h>
#define N 5

using namespace std;

template <class T>
class Queue {
private:
    T arr[N];
    int front, rear;
public:
    Queue(): front(-1), rear(-1) {};
    bool enqueue(T elem) {
        if ((front == 0 && rear == N-1) || (front == rear + 1)) {
            return false;
        }
        rear = (rear + 1) % N;
        arr[rear] = elem;
        if (front == -1) {
            front = (front + 1) % N;
        }
        return true;
    };
    T dequeue() {
        if (front == -1) {
            return INT_MIN;
        }
        T elem = arr[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        else {
            front = (front + 1) % N;
        }
        return elem;
    };
    bool print() {
        if (front == -1) {
            return false;
        }
        cout << "front -> ";
        for (int i = front; i != rear; i = (i + 1) % N) {
            cout << arr[i] << ", ";
        }
        cout << arr[rear];
        cout << " <- rear" << endl;
        return true;
    };
};

int main() {
    int t;
    cin >> t;
    Queue<int> q;
    while(t--) {
        char inp[20];
        scanf(" %s", inp);
        if (strcmp(inp, "e") == 0) {
            int elem;
            scanf(" %i", &elem);
            bool res = q.enqueue(elem);
            if (!res) {
                cout << "Queue Overflow!" << endl;
            }
        }
        else if(strcmp(inp, "d") == 0) {
            int elem = q.dequeue();
            if (elem == INT_MIN) {
                cout << "Queue Underflow!" << endl;
            }
            else {
                cout << elem << " dequeued." << endl;
            }
        }
        else if (strcmp(inp, "p") == 0) {
            bool res = q.print();
            if (!res) {
                cout << "Queue is empty!" << endl;
            }
        }
        else {
            cout << "Invalid input!!!" << endl;
            t++;
        }
    }
    return 0;
}
