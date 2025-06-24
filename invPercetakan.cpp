#include <iostream>
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
            wahini = wahini->selanjutnya;
        }
    }
    cout << "Item dengan nama" << nm << "tidak ditemukan\n";
}

// Dikerjakan oleh Rio
void hapus_item(printing_item* head, string nm){
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

    tambah_item(inventaris, "A4 Sinar Dunia", "Kertas A4 Sinar Dunia 80gsm", 100);
    tambah_item(inventaris, "A4 PaperOne", "Kertas A4 PaperOne 70gsm", 200);
    
    tampilkan_item(inventaris);
    
    hapus_item(inventaris, "A4 PaperOne");
    tampilkan_item(inventaris);
    return 0;
}