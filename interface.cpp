#include <iostream>
#include <stdlib.h>
using namespace std;

void banner(){
    system("cls");
    cout << "\033[1;32m";
    cout << R"( 

.___                           __                                      
|   | _______  __ ____   _____/  |_  ___________ ___.__.               
|   |/    \  \/ // __ \ /    \   __\/  _ \_  __ <   |  |               
|   |   |  \   /\  ___/|   |  \  | (  <_> )  | \/\___  |               
|___|___|  /\_/  \___  >___|  /__|  \____/|__|   / ____|               
         \/          \/     \/                   \/                    
__________                            __          __                   
\______   \ ___________   ____  _____/  |______  |  | _______    ____  
 |     ___// __ \_  __ \_/ ___\/ __ \   __\__  \ |  |/ /\__  \  /    \ 
 |    |   \  ___/|  | \/\  \__\  ___/|  |  / __ \|    <  / __ \|   |  \
 |____|    \___  >__|    \___  >___  >__| (____  /__|_ \(____  /___|  /
               \/            \/    \/          \/     \/     \/     \/ 
    )"<< endl;
    cout << "\033[1;0m";
    cout << "\t\t\033[1;32m  @dibuat oleh : Hipni, Dzaki, Rio\033[1;0m\n\n" << endl;
}

void menu() {
    banner();
    cout << "\033[1;37mSelamat datang di sistem Inventory Percetakan!\033[1;0m" << endl;
    cout << "\n\033[1;37mSilahkan pilih opsi berikut:\033[1;0m" << endl;
    cout << "\033[1;32m1.\033[1;0m Tambah Barang" << endl;
    cout << "\033[1;32m2.\033[1;0m Sisipkan Barang" << endl;
    cout << "\033[1;32m3.\033[1;0m Update Barang" << endl;
    cout << "\033[1;32m4.\033[1;0m Hapus Barang" << endl;
    cout << "\033[1;32m5.\033[1;0m Tampilkan Barang" << endl;
    cout << "\033[1;31m0.\033[1;0m Keluar\n" << endl;
}

void printNm(){
    cout << "Masukkan nama barang: ";
}

void printDesk(){
    cout << "Masukkan deskripsi barang: ";
}

void printStok(){
    cout << "Masukkan stok barang: ";
}