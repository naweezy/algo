#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int v) : val(v), prev(NULL), next(NULL) {}
};

int main() {
    int N;
    string S;
    cin >> N >> S;

    Node* head = new Node(N);
    Node* tail = head;

    for (int i = N - 1; i >= 0; i--) {
        Node* newNode = new Node(i);

        if (S[i] == 'L') {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    for (Node* cur = head; cur != NULL; cur = cur->next) {
        cout << cur->val;
        if (cur->next) cout << ' ';
    }
    cout << '\n';

    Node* cur = head;
    while (cur) {
        Node* tmp = cur->next;
        delete cur;
        cur = tmp;
    }

    return 0;
}
