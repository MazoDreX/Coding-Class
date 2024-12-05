#include <iostream>
using namespace std;

void printList(string buku[], int harga[], int size) {
    for(int i=0; i < size; i++) {
        cout << i + 1 << ". " << buku[i] << " - Rp." << harga[i] <<endl;
    }
}


int main() {
    string buku[3] = {"Atomic Habits", "Educated", "Why We Sleep"};
    int harga[3] = {10000, 20000, 300000};

    int size_buku = sizeof(buku) / sizeof(buku[0]);
    int pil, jumlah;

    cout << "Daftar Buku: " << endl;
    printList(buku, harga, size_buku);

    cout << "Pilih Buku: " << endl;
    
    do {
        cin >> pil;
        if (pil > 3 || pil < 1) {
            cout << "Pilihan tidak valid! Tolong input kembali..." << endl;
        }
    } while(pil > 3 || pil < 1);

    cout << "Masukan Jumlah buku yang ingin dibeli: ";
    
    do {
        cin >> jumlah;
    if(jumlah <= 0) {
        cout << "Jumlah tidak valid, Tolong input kembali..." << endl;
    }
    } while(jumlah <= 0);

    int totalHarga = harga[pil - 1] * jumlah;

    cout << "\nAnda memilih buku \"" << buku[pil - 1] << "\" sebanyak " << jumlah 
    << " buah.\n";
    cout << "Total harga: Rp" << totalHarga << endl;
    cout << "\nTerima kasih telah berbelanja di toko kami!\n";

    return 0;


}