#include <iostream>
#include <vector>
using namespace std;

struct data{
    string nama;
    string nim;
    string kom;
};

data mahasiswa[100]; // 100 equals to maximum data to be added to
int flag=0;

void add(){
    
    cout << "masukkan nama: "; 
    cin >>mahasiswa[flag].nama;
    //getline(cin,mahasiswa[flag].nama);
    cout <<"masukkan nim: ";
    cin>>mahasiswa[flag].nim;
    //getline(cin,mahasiswa[flag].nim);
    cout << "masukkan kom: ";
    cin >> mahasiswa[flag].kom;
    //getline(cin,mahasiswa[flag].kom);
    flag++;

}

void erase(){
    int n;
    cout <<"pilih data ke-berapa yang ingin dihapus: ";
    cin >> n;
    if(n>flag){
        cout <<"data pada indeks tersebut tidak ditemukan"<<endl;
        return;
    }
    n--;
    mahasiswa[n].nama = "kosong";
    mahasiswa[n].nim = "kosong";
    mahasiswa[n].kom = "kosong";
}

void display(){
    for (int i=0;i<flag;i++){
        cout << "data ke-"<<i+1<< endl;
        cout << "nama: "<<mahasiswa[i].nama<<endl;
        cout<<"nim: "<<mahasiswa[i].nim<<endl;
        cout <<"kom "<<mahasiswa[i].kom<<endl;
        cout << endl;
    }
}

void edit(){
    int n;
    cout << "pilih data ke-berapa yang ingin diedit: ";
    cin >> n;
    if(n>flag){
        cout <<"data pada indeks tersebut tidak ditemukan"<<endl;
        return;
    }
    n--;
    cout << "data yang ingin diubah adalah data ke-"<<n+1<< endl;
    cout<<"masukkan nama baru: ";
    //getline(cin,mahasiswa[n].nama);
    cin >> mahasiswa[n].nama;
    cout <<"masukkan nim baru: ";
    cin >> mahasiswa[n].nim;
    cout <<"masukkan kom baru: ";
    cin >> mahasiswa[n].kom;

}
int main(){
    int pil;

    menu:
    cout << " \t\t MENU \n";
    cout << "1. tambah data\n";
    cout << "2. hapus data \n";
    cout << "3. tampilkan data \n";
    cout << "4. edit data \n";
    cout << "5. keluar\n";
    cout << "\n Pilih menu (1/2/3/4/5) ? ";
    cin >> pil;

    switch (pil){
        case 1:
            add();
            break;
        case 2:
            erase();
            break;
        case 3:
            display();
            break;
        case 4:
            edit();
            break;
        case 5:
           
            break;
        default:
            break;
    }
   
    goto menu;
    
    


    
}