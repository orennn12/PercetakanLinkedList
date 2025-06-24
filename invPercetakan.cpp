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
void tambah_item(printing_item* head, string nm, string desk, int stok){
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
}

int main(){
    cout << "Hello World" << endl;

    return 0;
}