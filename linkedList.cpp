#include <bits/stdc++.h>
using namespace std;

// Struktur node untuk Doubly Linked List
struct Node {
    int val;       // menyimpan nilai node
    Node* prev;    // pointer ke node sebelumnya
    Node* next;    // pointer ke node berikutnya

    // Constructor
    Node(int v) : val(v), prev(NULL), next(NULL) {}
};

int main() {

    int N;
    string S;

    // Input:
    // N = jumlah node tambahan
    // S = instruksi L atau R
    cin >> N >> S;

    // Awalnya linked list hanya berisi node N
    Node* head = new Node(N);
    Node* tail = head;

    // Loop dari N-1 turun ke 0
    for (int i = N - 1; i >= 0; i--) {

        // Membuat node baru
        Node* newNode = new Node(i);

        // Jika karakter = 'L'
        // maka node baru ditaruh di kanan (tail)
        if (S[i] == 'L') {

            // Sambungkan tail ke newNode
            tail->next = newNode;

            // Hubungkan prev newNode ke tail
            newNode->prev = tail;

            // Geser tail ke node baru
            tail = newNode;

        } else {

            // Jika karakter = 'R'
            // maka node baru ditaruh di kiri (head)

            // Hubungkan newNode ke head lama
            newNode->next = head;

            // Head lama prev-nya jadi newNode
            head->prev = newNode;

            // Geser head ke node baru
            head = newNode;
        }
    }

    // Traversal dari head sampai akhir
    // untuk mencetak isi linked list
    for (Node* cur = head; cur != NULL; cur = cur->next) {

        cout << cur->val;

        // Tambahkan spasi jika bukan node terakhir
        if (cur->next)
            cout << ' ';
    }

    cout << '\n';

    // Menghapus semua node agar memory tidak bocor
    Node* cur = head;

    while (cur) {

        // Simpan node berikutnya
        Node* tmp = cur->next;

        // Hapus node sekarang
        delete cur;

        // Pindah ke node berikutnya
        cur = tmp;
    }

    return 0;
}    cout << '\n';

    Node* cur = head;
    while (cur) {
        Node* tmp = cur->next;
        delete cur;
        cur = tmp;
    }

    return 0;
}
