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
void sisipkan_item(printing_item* head, string nm, string desk, int stok){
printing_item* hanyar = new printing_item{nm, desk, stok, head};
head = hanyar;
}

// Di kerjakan oleh Dzaki
void update_item(printing_item* head, string nm){
}

// Dikerjakan oleh Rio
void hapus_item(printing_item* head, string nm){
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
    return 0;
}