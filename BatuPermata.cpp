#include <iostream>
#include <iomanip> // Untuk manipulasi output / formatting
//fixed setprecision(2) digunakan untuk mengubah format double dari 
//notasi ilmiah menjadi angka dengan pendekatan 2 angka dibelakang ,
using namespace std;

int main() {
    const int MAKSIMAL_KARAT = 24;

    int tipeBatu, karatBatu, bentukBatu;
    int hargaPokok;
    double kenaikanHarga = 0, subTotal;

    cout << "=====================================\n";
    cout << "PROGRAM MENGHITUNG HARGA BATU PERMATA\n";
    cout << "=====================================\n";
    cout << "Masukan Harga Pokok : ";
    cin >> hargaPokok;
    cout << "Masukan Tipe Batu: ";
    cin >> tipeBatu;
    
    if(cin.fail() || hargaPokok <= 0 || tipeBatu <= 0) { //Mengecek kondisi input tipeBatu apakah valid sesuai tipe data yang dideklarasikan
        cout << "Input harus berupa angka dan tidak boleh negatif";
        return 0;
    }
    

    cout << "\n--- Proses Perhitungan ---" << endl;
    cout << "Harga Pokok: " << fixed << setprecision(2) << hargaPokok << endl;

    // Logika utama program, mengecek tipe batu
    if (tipeBatu == 1) {
        cout << "Tipe Batu: 1 (Kenaikan Harga 20%)" << endl;
        kenaikanHarga = hargaPokok * 0.2;
        subTotal = hargaPokok + kenaikanHarga;
        cout << "Kenaikan Harga (20%): " << fixed << setprecision(2) << kenaikanHarga << endl;
        cout << "Harga batu saat ini: " << subTotal <<endl;

        // Masukan input karat
        cout << "\n";
        cout << "Jumlah karat batu permata: ";
        cin >> karatBatu;

        // Cek input karat
        if (karatBatu > 0 && karatBatu <= MAKSIMAL_KARAT) {

            //PERHATIKAN PERHITUNGAN KODE DI BAWAH
            double hargaKaratBatu = subTotal * (karatBatu * 0.035); // Kenaikan 3.5% per karat
            kenaikanHarga += hargaKaratBatu;
            subTotal += hargaKaratBatu;
            cout << "Kenaikan Harga dari karat: " << karatBatu << " karat, 3.5%/karat): " 
                 << fixed << setprecision(2) << hargaKaratBatu << endl;
            cout << "Harga batu saat ini: " << subTotal << endl;

        } else {
            cout << "Input jumlah karat tidak benar!" << endl;
            return 0;
        }

        // Cek bentuk batu permata
        cout << "\n";
        cout << "Bentuk Batu Permata (1 = Kotak, 2 = Oval, 3 = Bentuk lain): ";
        if(cin>>bentukBatu) {
            if (bentukBatu == 1) {
                double kenaikanBentuk = subTotal * 0.1; // Kenaikan 10% untuk bentuk kotak
                kenaikanHarga += kenaikanBentuk;
                subTotal += kenaikanBentuk;
                cout << "Kenaikan Harga Bentuk (Kotak, 10%): " 
                    << fixed << setprecision(2) << kenaikanBentuk << endl;
                cout << "Harga batu saat ini: " << subTotal << endl;
        } else if (bentukBatu == 2) {
                double kenaikanBentuk = subTotal * 0.07; // Kenaikan 7% untuk bentuk oval
                kenaikanHarga += kenaikanBentuk;
                subTotal += kenaikanBentuk;
                cout << "Kenaikan Harga Bentuk (Oval, 7%): " 
                    << fixed << setprecision(2) << kenaikanBentuk << endl;
                cout << "Harga batu saat ini: " << subTotal << endl;
        }
        } else {
            cout << "Masukan input yang benar!";
            return 0;
        }

        

    } else if (tipeBatu == 2) {
        cout << "Tipe Batu: 2 (Kenaikan Harga 15%)" << endl;
        kenaikanHarga = hargaPokok * 0.15;
        cout << "Kenaikan Harga (15%): " << fixed << setprecision(2) << kenaikanHarga << endl;
        

        double kenaikanLabour = hargaPokok * 0.03; // Kenaikan 3% karena labour
        kenaikanHarga += kenaikanLabour;
        subTotal = hargaPokok + kenaikanHarga;
        cout << "Kenaikan Harga Labour (3%): " << fixed << setprecision(2) << kenaikanLabour << endl;
        cout << "Harga batu saat ini: " << subTotal << endl;

    } else {
        cout << "Tipe Batu: Lainnya (Kenaikan Harga 7%)" << endl;
        kenaikanHarga = hargaPokok * 0.07; // Kenaikan 7% untuk tipe lainnya
        subTotal = hargaPokok + kenaikanHarga;
        cout << "Kenaikan Harga (7%): " << fixed << setprecision(2) << kenaikanHarga << endl;
        cout << "Harga batu saat ini: " << subTotal << endl;
    }

    // Output hasil akhir
    
    cout << "\n=====================================\n";
    cout << "Harga Pokok Batu Permata   : " << fixed << setprecision(2) << hargaPokok << endl;
    cout << "Total Kenaikan Harga       : " << fixed << setprecision(2) << kenaikanHarga << endl;
    cout << "Harga Akhir Batu Permata   : " << fixed << setprecision(2) << subTotal << endl;

    return 0;
}
