#include <stdio.h>
#include <string.h>

int main() {
    int N, i;
    int jmlValid = 0, jmlInvalid = 0, jmlLulus = 0;
    float tesTulis, wawancara, nilaiAkhir, totalNilai = 0, avr = 0;
    float max1 = 0, max2 = 0;
    char nama[50], status[20];

    printf("Sistem Seleksi & Pemeringkatan Peserta Magang\n");
    printf("Masukkan jumlah pelamar: ");
    scanf("%d", &N);

    printf("\n%-15s | %-10s | %-10s\n", "Nama", "Nilai", "Status");
    printf("-------------------------------------------\n");

    for (i = 1; i <= N; i++) {
        scanf("%s %f %f", nama, &tesTulis, &wawancara);

        // 1. Validasi Data
        if (tesTulis < 0 || tesTulis > 100 || wawancara < 0 || wawancara > 100) {
            strcpy(status, "TIDAK VALID");
            jmlInvalid++;
            nilaiAkhir = 0; // Nilai tidak dihitung
        } else {
            // 2. Perhitungan Nilai Akhir
            jmlValid++;
            nilaiAkhir = (0.6 * tesTulis) + (0.4 * wawancara);
            totalNilai += nilaiAkhir;

            // 3. Penentuan Kelulusan
            if (nilaiAkhir >= 75) {
                strcpy(status, "LULUS");
                jmlLulus++;

                // 4. Update Dua Nilai Tertinggi (Tanpa Sorting)
                if (nilaiAkhir > max1) {
                    max2 = max1;
                    max1 = nilaiAkhir;
                } else if (nilaiAkhir > max2 && nilaiAkhir < max1) {
                    max2 = nilaiAkhir;
                }
            } else {
                strcpy(status, "TIDAK LULUS");
            }
        }
        // Menampilkan daftar per pelamar
        printf("%-15s | %-10.2f | %-10s\n", nama, nilaiAkhir, status);
    }

    // 5. Output Ringkasan
    if (jmlValid > 0) avr = totalNilai / jmlValid;

    printf("\n--- RINGKASAN DATA ---\n");
    printf("Jumlah Data Valid   : %d\n", jmlValid);
    printf("Jumlah Tidak Valid  : %d\n", jmlInvalid);
    printf("Jumlah Lulus        : %d\n", jmlLulus);
    printf("Rata-rata Nilai     : %.2f\n", avr);

    if (jmlLulus > 0) {
        printf("Nilai Tertinggi 1   : %.2f\n", max1);
        if (max2 > 0) printf("Nilai Tertinggi 2   : %.2f\n", max2);
    }

    return 0;
}