// Implementation of singly linked list using pointers

#include <bits/stdc++.h>

using namespace std;

typedef struct Node {
    int data;
    Node *next;
} Node;

Node *head;

void insert(int val) {
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = val;
    newnode->next = head;
    head = newnode;
    return;
}

void del(int val) {
    Node *tmp1 = head, *tmp2 = NULL;
    if (head == NULL) {
        cout << "Empty linked list!" << endl;
        return;
    }
    while (tmp1 != NULL && tmp1->data != val) {
        tmp2 = tmp1;
        tmp1 = tmp1->next;
    }
    if (tmp1 == NULL) {
        cout << "Element not found!" << endl;
        return;
    }
    if (tmp2 == NULL) {
        head = head->next;
    }
    else {
        tmp2->next = tmp1->next;
    }
    free(tmp1);
    return;
}

void print() {
    if (head == NULL) {
        cout << "Empty linked list!" << endl;
        return;
    }
    Node *tmp1 = head;
    cout << "head" << " -> ";
    while (tmp1->next != NULL) {
        cout << tmp1->data << " -> ";
        tmp1 = tmp1->next;
    }
    cout << tmp1->data << endl;
    return;
}

int main() {
    int q;
    cin >> q;
    while (q--) {
        char c;
        int inp;
        cin >> c;
        switch(c) {
            case 'i':
                cin >> inp;
                insert(inp);
                break;
            case 'd':
                cin >> inp;
                del(inp);
                break;
            case 'p':
                print();
                break;
        }
    }
    return 0;
}
