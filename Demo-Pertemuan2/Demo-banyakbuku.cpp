#include <iostream>
using namespace std;

void printList(string buku[], int harga[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << ". " << buku[i] << " - Rp." << harga[i] << endl;
    }
}

int main() {
    string buku[3] = {"Atomic Habits", "Educated", "Why We Sleep"};
    int harga[3] = {10000, 20000, 300000};

    string bukuPilihan[10];
    int hargaPilihan[10];
    int jumlahPilihan[10];

    int size_buku = sizeof(buku) / sizeof(buku[0]);
    int pil, jumlah;
    int totalHarga = 0;
    int pilihanCount = 0;

    

    char lanjut;
    do {
        cout << "Daftar Buku: " << endl;
        printList(buku, harga, size_buku);
        // Pilih buku
        cout << "\nPilih Buku (1-" << size_buku << "): ";
        do {
            cin >> pil;
            if (pil > size_buku || pil < 1) {
                cout << "Pilihan tidak valid! Tolong input kembali..." << endl;
            }
        } while (pil > size_buku || pil < 1);

        // Masukkan jumlah buku
        cout << "Masukkan jumlah buku yang ingin dibeli: ";
        do {
            cin >> jumlah;
            if (jumlah <= 0) {
                cout << "Jumlah tidak valid, tolong input kembali..." << endl;
            }
        } while (jumlah <= 0);

        // Simpan data pilihan
        bukuPilihan[pilihanCount] = buku[pil - 1];
        hargaPilihan[pilihanCount] = harga[pil - 1];
        jumlahPilihan[pilihanCount] = jumlah;
        pilihanCount++;

        // Hitung total harga
        totalHarga += harga[pil - 1] * jumlah;

        // Tanyakan apakah ingin membeli buku lain
        cout << "\nApakah Anda ingin membeli buku lain? (y/n): ";
        cin >> lanjut;

    } while (lanjut == 'y' || lanjut == 'Y');

    // Tampilkan ringkasan pembelian
    cout << "\nRingkasan Pembelian:\n";
    for (int i = 0; i < pilihanCount; i++) {
        cout << i + 1 << ". " << bukuPilihan[i] << " - "
             << jumlahPilihan[i] << " buah - Total: Rp"
             << hargaPilihan[i] * jumlahPilihan[i] << endl;
    }
    cout << "Total keseluruhan: Rp" << totalHarga << endl;

    cout << "\nTerima kasih telah berbelanja di toko kami!\n";

    return 0;
}
