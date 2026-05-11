#include <bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* prev;
    Node* next;
    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

const int MAXN = 500001;
Node* nodes[MAXN + 1];  // array pointer

int main() {
    int N;
    string S;
    cin >> N >> S;
    for (int i = 0; i <= N; i++)
        nodes[i] = new Node(i);
    Node* head = nodes[0];

    for (int i = 1; i <= N; i++) {
        Node* ref     = nodes[i - 1];  // langsung akses node i-1
        Node* newNode = nodes[i];
      
        if (S[i - 1] == 'L') {
            // sisip newNode di kiri ref
            Node* leftNode = ref->prev;
            newNode->next = ref;
            newNode->prev = leftNode;
            ref->prev = newNode;
            if (leftNode) leftNode->next = newNode;

            if (ref == head) head = newNode;
        } else {
            // sisip newNode di kanan ref
            Node* rightNode = ref->next;
            newNode->prev = ref;
            newNode->next = rightNode;
            ref->next = newNode;
            if (rightNode) rightNode->prev = newNode;
        }
    }

    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->val;
        if (cur->next) cout << ' ';
    }
    cout << '\n';

    for (int i = 0; i <= N; i++) delete nodes[i];
    return 0;
}
