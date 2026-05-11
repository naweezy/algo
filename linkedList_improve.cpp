#include <bits/stdc++.h>
using namespace std;

// Struktur Node untuk Doubly Linked List
struct Node {
    int val;       // menyimpan nilai node
    Node* prev;    // pointer ke node sebelumnya
    Node* next;    // pointer ke node berikutnya

    // Constructor
    Node(int v) : val(v), prev(nullptr), next(nullptr) {}
};

// Maksimal jumlah node
const int MAXN = 500001;

// Array pointer untuk menyimpan alamat tiap node
// nodes[i] akan menunjuk ke node bernilai i
Node* nodes[MAXN + 1];

int main() {
    int N;
    string S;

    // Input:
    // N = jumlah operasi / banyak node tambahan
    // S = instruksi L atau R
    cin >> N >> S;

    // Membuat node dari 0 sampai N
    for (int i = 0; i <= N; i++)
        nodes[i] = new Node(i);

    // Awalnya head menunjuk node 0
    Node* head = nodes[0];

    // Loop untuk menyisipkan node 1 sampai N
    for (int i = 1; i <= N; i++) {

        // Node referensi = node sebelumnya (i-1)
        Node* ref = nodes[i - 1];

        // Node yang akan disisipkan
        Node* newNode = nodes[i];

        // Jika karakter = 'L'
        // maka node baru diletakkan di kiri ref
        if (S[i - 1] == 'L') {

            // Simpan node di sebelah kiri ref
            Node* leftNode = ref->prev;

            // Hubungkan newNode dengan ref
            newNode->next = ref;
            newNode->prev = leftNode;

            // Ref sekarang punya prev ke newNode
            ref->prev = newNode;

            // Jika ada node di kiri sebelumnya,
            // hubungkan ke newNode
            if (leftNode)
                leftNode->next = newNode;

            // Jika ref adalah head,
            // maka head pindah ke newNode
            if (ref == head)
                head = newNode;

        } else {

            // Jika karakter = 'R'
            // maka node baru diletakkan di kanan ref

            // Simpan node di kanan ref
            Node* rightNode = ref->next;

            // Hubungkan newNode dengan ref
            newNode->prev = ref;
            newNode->next = rightNode;

            // Ref sekarang punya next ke newNode
            ref->next = newNode;

            // Jika ada node di kanan sebelumnya,
            // hubungkan prev-nya ke newNode
            if (rightNode)
                rightNode->prev = newNode;
        }
    }

    // Traversal dari head sampai akhir
    // untuk mencetak isi linked list
    for (Node* cur = head; cur != nullptr; cur = cur->next) {
        cout << cur->val;

        // Tambahkan spasi jika bukan node terakhir
        if (cur->next)
            cout << ' ';
    }

    cout << '\n';

    // Menghapus semua node dari memory
    for (int i = 0; i <= N; i++)
        delete nodes[i];

    return 0;
}
