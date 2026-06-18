#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    // Mengoptimalkan input/output C++ agar berjalan super cepat
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;
    cin >> n >> s;

    deque<int> dq;
    
    // Masukkan angka terakhir (N) terlebih dahulu
    dq.push_back(n);

    // Proses string dari belakang (dari indeks N-1 ke 0)
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == 'L') {
            // Jika karakternya 'L', angka i ditaruh di sebelah KANAN
            dq.push_back(i);
        } else {
            // Jika karakternya 'R', angka i ditaruh di sebelah KIRI
            dq.push_front(i);
        }
    }

    // Cetak hasil akhir
    for (int i = 0; i <= n; ++i) {
        cout << dq[i] << (i == n ? "" : " ");
    }
    cout << "\n";

    return 0;
}

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
}   
