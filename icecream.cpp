#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cout << "Masukkan jumlah test case: ";
    cin >> t;

    while (t--) {
        int m, n;

        cout << "Masukkan jumlah uang: ";
        cin >> m;

        cout << "Masukkan jumlah es krim: ";
        cin >> n;

        vector<int> harga(n);

        cout << "Masukkan harga: ";
        for (int i = 0; i < n; i++) {
            cin >> harga[i];
        }

        // mencari pasangan
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (harga[i] + harga[j] == m) {
                    cout << "Indeks: " << i + 1 << " " << j + 1 << endl;
                    break;
                }
            }
        }
    }

    return 0;
}