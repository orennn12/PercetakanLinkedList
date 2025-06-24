#include <iostream>
#include <conio.h>
#include "./interface.cpp"
using namespace std;

struct printing_item
{
    string nama;
    string deskripsi;
    int stok;
    printing_item *selanjutnya;
};

// Di kerjakan oleh Hipni
void tambah_item(printing_item*& head, string nm, string desk, int stok){

    printing_item* cek = head;
    while (cek != nullptr) {
        if (cek->nama == nm) {
            cout << "\033[1;31m[!] Item dengan nama '" << nm << "' sudah ada!\033[1;0m\n";
            return;
        }
        cek = cek->selanjutnya;
    }

    printing_item* itemBaru = new printing_item{nm, desk, stok, nullptr};

    if(head == nullptr) {
        head = itemBaru;
        return;
    } 

    printing_item* temp = head;
    while(temp->selanjutnya != nullptr) {
        temp = temp->selanjutnya;
    }

    temp->selanjutnya = itemBaru;
}

// Di kerjakan oleh Dzaki
void sisipkan_item(printing_item*& head, string nm, string desk, int stok){

    printing_item* cek = head;
    while (cek != nullptr) {
        if (cek->nama == nm) {
            cout << "\033[1;31m[!] Item dengan nama '" << nm << "' sudah ada!\033[1;0m\n";
            return;
        }
        cek = cek->selanjutnya;
    }

    printing_item* hanyar = new printing_item{nm, desk, stok, head};
    head = hanyar;
}

// Di kerjakan oleh Dzaki
void update_item(printing_item* head, string nm){
    printing_item* wahini = head;

    while(wahini != nullptr){
        if(wahini->nama == nm){
            int menu_pilih;
            cout << "Item yang anda cari ditemukan, silahkan ubah data\n";
            cout << "1. Ubah Nama\n";
            cout << "2. Ubah Stok\n";
            cout << "3. Ubah Deskripsi\n";
            cout << "Pilih Opsi: ";
            cin >> menu_pilih;
            cin.ignore();

            switch(menu_pilih){
                case 1:
                cout << "Masukan nama baru: ";
                getline(cin, wahini->nama);
                cout << "\nNama berhasil diganti";
                break;
                case 2:
                cout << "Masukan stok baru: ";
                cin >> wahini->stok;
                cout << "\nStok berhasil diganti";
                break;
                case 3:
                cout << "Masukan deskripsi baru: ";
                getline(cin, wahini->deskripsi);
                cout << "\nDeskripsi berhasil diganti";
                break;

                default:
                cout << "Pernyataan tidak valid!";
            }  
            return;
        }
        wahini = wahini->selanjutnya;
    }
    cout << "Item dengan nama" << nm << "tidak ditemukan\n";
}

// Dikerjakan oleh Rio
void hapus_item(printing_item*& head, string nm){
    if (head == nullptr) {
        cout << "Daftar Kosong." << endl;
        return;
    }

    printing_item* temp = head;
    if (temp->nama == nm){
        head = temp->selanjutnya;
        delete temp;
        cout << "Item Dihapus" << endl;
        return;
    }

    printing_item* sebelum = temp;
    temp = temp->selanjutnya;

    while (temp != nullptr){
        if (temp->nama == nm){
            sebelum->selanjutnya = temp->selanjutnya;
            delete temp;
            cout << "\n[!] Item Dihapus\n" << endl;
            return;
        }
        sebelum = temp;
        temp = temp->selanjutnya;
    }

    cout << "Item Tidak Ada" << endl;

}

// Di kerjakan oleh Hipni
void tampilkan_item(printing_item* head){
    if(head == nullptr) {
        cout << "Tidak ada item dalam inventaris." << endl;
        return;
    }

    printing_item* temp = head;
    int nomor = 1;
    while(temp != nullptr) {
        if(nomor == 1) cout << "----------------------------------" << endl;
        cout << "Invetaris Item #" << nomor << " :" << endl; nomor++;
        cout << "\tNama \t:" << temp->nama << endl;
        cout << "\tDesk \t:" << temp->deskripsi << endl;
        cout << "\tStok \t:" << temp->stok << endl;
        cout << "----------------------------------" << endl;
        temp = temp->selanjutnya;
    }
}

int main(){
    printing_item* inventaris = nullptr;

    string nama, deskripsi;
    int stok, pilihan = 1;

    while (pilihan != 0)
    {
        menu();

        cout << "\033[1;37mMasukkan pilihan Anda: \033[1;0m";
        cin >> pilihan;
        switch (pilihan)
        {
        case 0:
            cout << "\033[1;31mTerimakasih dan sampai jumpa ^-^\033[1;0m" << endl;
            break;
        case 1:
            system("cls");
            cout << "\033[1;32m=== Silahkan masukkan barang yang ingin anda tambah ===\033[1;0m" << endl;
            printNm(); cin.ignore(); getline(cin, nama);
            printDesk(); getline(cin, deskripsi);
            printStok(); cin >> stok;
            tambah_item(inventaris, nama, deskripsi, stok);
            cout << "\033[1;32mBarang berhasil ditambahkan!\033[1;0m" << endl; 
            cout << "\n\n\nTekan apa saja untuk keluar..."; getch();
            break;
        case 2:
            system("cls");
            cout << "\033[1;32m=== Silahkan masukkan barang yang ingin sisipkan ===\033[1;0m" << endl;
            printNm(); cin.ignore(); getline(cin, nama);
            printDesk(); getline(cin, deskripsi);
            printStok(); cin >> stok;
            sisipkan_item(inventaris, nama, deskripsi, stok);
            cout << "\033[1;32mBarang berhasil disisipkan!\033[1;0m" << endl; 
            cout << "\n\n\nTekan apa saja untuk keluar..."; getch();
            break;
        case 3:
            system("cls");
            cout << "\033[1;32m=== Silahkan masukkan nama barang yang ingin anda update ===\033[1;0m" << endl;
            printNm(); cin.ignore(); getline(cin, nama);
            update_item(inventaris, nama);
            cout << "\033[1;32mBarang berhasil diupdate!\033[1;0m" << endl; 
            cout << "\n\n\nTekan apa saja untuk keluar..."; getch();
            break;
        case 4:
            system("cls");
            cout << "\033[1;32m=== Silahkan masukkan nama barang yang ingin anda hapus ===\033[1;0m" << endl;
            printNm(); cin.ignore(); getline(cin, nama);
            hapus_item(inventaris, nama);
            cout << "\033[1;31mBarang berhasil hapus!\033[1;0m" << endl; 
            cout << "\n\n\nTekan apa saja untuk keluar..."; getch();
            break;
        case 5:
            system("cls");
            cout << "\033[1;32m=== Berikut daftar barang yang ada ===\n\033[1;0m" << endl;
            tampilkan_item(inventaris); 
            cout << "\n\n\nTekan apa saja untuk keluar..."; getch();
        default:
            cout << "\033[1;31mPilihan tidak valid! Silakan coba lagi.\033[1;0m" << endl;
            break;
        }
    }
}