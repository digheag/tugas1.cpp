#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct data_roti {
    string nama;
    int kode;
    float harga;
};

const int n = 4; 

data_roti Roti[n] = {
    {"Roti Tawar", 101, 15000},
    {"Roti Coklat", 102, 12000},
    {"Roti Keju", 103, 18000},
    {"Roti Srikaya", 104, 14000}
};

void tampilkanData() {
    cout << "\nDaftar Roti:\n";
    cout << "No  | "  << setw(12) << left << "Nama " << "| Kode " << "| Harga " << endl;
    cout << "------------------------------------------------" << endl;
    data_roti *ptr = Roti;
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "    | " << setw(12) << left << (ptr+i)->nama
             << " | " << left << (ptr+i)->kode
             << " | " << left << (ptr+i)->harga << endl;
    }
}

int sequentialSearch(int kode) {
    for (int i = 0; i < n; i++) {
        if (Roti[i].kode == kode) {
            return i;
        }
    }
    return -1;
}

int binarySearch(string nama) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (Roti[mid].nama == nama) return mid;
        if (Roti[mid].nama < nama) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void quickSort(int low, int high) {
    if (low < high) {
        float pivot = Roti[high].harga;
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (Roti[j].harga < pivot) {
                i++;
                swap(Roti[i], Roti[j]);
            }
        }
        swap(Roti[i + 1], Roti[high]);
        int pi = i + 1;
        quickSort(low, pi - 1);
        quickSort(pi + 1, high);
    }
}

void bubbleSort() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (Roti[j].harga < Roti[j + 1].harga) {
                swap(Roti[j], Roti[j + 1]);
            }
        }
    }
}

void menuUtama() {
    int menu;
    char pilihan;
    do {
        cout << "\nMENU UTAMA : " << endl;
        cout << "1. Tampilkan Roti" << endl;
        cout << "2. Cari berdasarkan kode" << endl;
        cout << "3. Cari berdasarkan nama" << endl;
        cout << "4. Sort harga roti (asc)" << endl;
        cout << "5. Sort harga roti (desc)" << endl;
        cout << "6. Exit" << endl;
        cout << "Pilihan : ";
        cin >> menu;

        switch (menu) {
            case 1:
                tampilkanData();
                break;
            case 2: {
                int kode;
                cout << "Masukkan kode roti: ";
                cin >> kode;
                int index = sequentialSearch(kode);
                if (index != -1)
                    cout << "Ditemukan: " << Roti[index].nama << " dengan harga " << Roti[index].harga << "\n";
                else
                    cout << "Kode tidak ditemukan!\n";
                break;
            }
            case 3: {
                string nama;
                cout << "Masukkan nama roti: ";
                cin.ignore();
                getline(cin, nama);
                int index = binarySearch(nama);
                if (index != -1)
                    cout << "Ditemukan: " << Roti[index].kode << " dengan harga " << Roti[index].harga << "\n";
                else
                    cout << "Nama tidak ditemukan!\n";
                break;
            }
            case 4:
                quickSort(0, n - 1);
                tampilkanData();
                break;
            case 5:
                bubbleSort();
                tampilkanData();
                break;
            case 6:
                cout << "Terima kasih!" << endl;
                return;
            default:
                cout << "Pilihan tidak valid." << endl;
                break;
        }
        cout << "\nApakah anda ingin kembali ke menu? (y/t): ";
        cin >> pilihan;
    } while (pilihan == 'y' || pilihan == 'Y');
}

int main() {
    menuUtama();
    return 0;
}
