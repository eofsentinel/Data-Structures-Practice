// Implementation of Queue using arrays

#include <bits/stdc++.h>
#define N 5

using namespace std;

template <class T>
class Queue {
private:
    T arr[N];
    int front, rear;
    bool empty;
public:
    Queue(): front(0), rear(0), empty(true) {};
    bool enqueue(T elem) {
        if (!empty && rear == front) {
            return false;
        }
        empty = false;
        arr[rear] = elem;
        rear = (rear + 1) % N;
        return true;
    };
    T dequeue() {
        if (empty) {
            return INT_MIN;
        }
        T elem = arr[front];
        if (front == rear) {
            empty = true;
        }
        front = (front + 1) % N;
        return elem;
    };
    bool print() {
        if (empty) {
            return false;
        }
        cout << "front -> ";
        for (int i = front; i != ((rear - 1) % N); i = (i + 1) % N) {
            cout << arr[i] << ", ";
        }
        cout << arr[rear - 1];
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
