#include <iostream>
using namespace std;

int main() {
    double totalPesanan, subTotal, potonganHarga, potonganRecess;
    int waktuPesanan, totalDiskon, totalDiskonRecess;
    
    //Header dan Input
    cout << "=====================================\n";
    cout << "-----PROGRAM MENGHITUNG PROMO CAFE---\n";
    cout << "=====================================\n";
    cout << "Masukan Total Pesanan : ";
    cin >> totalPesanan;
    cout << "Masukan Jam saat pesan : ";
    cin >> waktuPesanan;

    //Validasi Input
    if (totalPesanan <= 0 || waktuPesanan < 0 || waktuPesanan > 23) {
        cout << "Input ada yang tidak valid. Tolong masukkan nilai yang benar!";
        return 0;
    }

    //Logika Program Utama (Menentukan Diskon more is better)
    if(totalPesanan > 150000) {
        potonganHarga = totalPesanan * 0.2;
        totalDiskon = 20;
    } else if(totalPesanan > 75000) {
        potonganHarga = totalPesanan * 0.12;
        totalDiskon = 12;
    } else if(totalPesanan > 40000) {
        potonganHarga = totalPesanan * 0.08;
        totalDiskon = 8;
    }
    
    //Mengurangi total pesanan dengan potongan yang sudah dihitung dengan diskon
    subTotal = totalPesanan - potonganHarga;

    //Logika Program Utama (Menentukan diskon recess hour)
    if(waktuPesanan >= 12 && waktuPesanan <= 14 || waktuPesanan >= 17 && waktuPesanan <= 19) {

        //Menghitung potongan dari promo recess hour lalu kurangi subTotal dengan potonganRecess
        potonganRecess = subTotal * 0.05;
        subTotal -= potonganRecess;
        potonganHarga += potonganRecess;
        totalDiskonRecess = 5; //Menambahkan diskon 5% untuk informasi lebih detail
    } else {
        totalDiskonRecess = 0;
    }

    //Print semua hasil
    cout << "=========================================\n";
    cout << "Total Pesanan Awal : Rp." << totalPesanan << endl;
    cout << "Total diskon yang didapat : " << totalDiskon <<"% " <<"+ " << totalDiskonRecess <<"%" << " atau " << "Rp." << potonganHarga << endl;
    cout << "Total Pesanan Akhir Setelah didiskon : Rp." << subTotal <<endl;
}