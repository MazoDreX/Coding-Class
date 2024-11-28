#include <iostream>
#include <iomanip> // Untuk mengatur output angka desimal (jika diperlukan)
using namespace std;

int main() {
    string buku;
    int jumlah, harga, potongan, subTotal, total;

    cout << "Masukan nama Buku: ";
    getline(cin, buku);
    cout << "Masukan harga buku (10000 - 20000): ";
    cin >> harga;
    cout << "\n";

    if (harga >= 10000 && harga <= 20000) {
        cout << "Nama Buku: " << buku << endl;
        cout << "Masukan jumlah buku: ";
        cin >> jumlah;

        if (jumlah <= 0) {
            cout << "Jumlah harus lebih dari 0!" << endl;
            return 1;
        }

        subTotal = jumlah * harga;

        if (jumlah < 2) {
            potongan = 0;
        } else if (jumlah <= 5) {
            potongan = subTotal * 0.2; // Diskon 20% untuk total pembelian
        } else if (jumlah <= 10) {
            potongan = subTotal * 0.5; // Diskon 50% untuk total pembelian
        } else {
            cout << "Pembelian terlalu besar... Tolong hubungi CS!" << endl;
            return 1;
        }

        total = subTotal - potongan;

        cout << "Subtotal: Rp" << subTotal << endl;
        cout << "Potongan: Rp" << potongan << endl;
        cout << "Total: Rp" << total << endl;
    } else {
        cout << "Harga buku tidak sesuai! Batas harga adalah 10000-20000." << endl;
    }

    return 0;
}
