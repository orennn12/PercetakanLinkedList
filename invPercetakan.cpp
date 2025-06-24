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
}

// Di kerjakan oleh Dzaki
void update_item(printing_item* head, string nm){
}

// Dikerjakan oleh Rio
void hapus_item(printing_item* head, string nm){
}

// Di kerjakan oleh Hipni
void tampilkan_item(printing_item* head){
}

int main(){
    printing_item* inventaris = nullptr;
    tambah_item(inventaris, "Buku A", "Deskripsi Buku A", 10);
    return 0;
}
