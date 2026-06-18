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
