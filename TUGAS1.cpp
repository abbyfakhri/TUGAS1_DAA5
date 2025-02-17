/* Contoh Program ke : 1 */
/* Program : struktur data statis mahasiswa */
#include <ncurses.h> // #include <conio.h> for windows
#include <cstring>
#include <iostream>
#include <string.h>
#define nmax 5 // banyak data yang dapat ditampung
using namespace std;

int n = 0; // variable n sebagai banyak data yang telah tersimpan
struct data
{ // struktur data mahasiswa yg akan diinput

    int nim;
    string nama;
    char kom;
};
struct data maba[nmax]; // deklarasi variabel bertipe struct
void tambah_data();     // prototype fungsi void
void hapus_data();
void tampilkan_data();


void edit(){
    int n;
    cout << "pilih data ke-berapa yang ingin diedit: ";
    cin >> n;
    if(n>nmax){
        cout <<"data pada indeks tersebut tidak ditemukan"<<endl;
        return;
    }
    n--;
    cout << "data yang ingin diubah adalah data ke-"<<n+1<< endl;
    cout<<"masukkan nama baru: ";
   cin>>maba[n].nama;
     
    cout <<"masukkan nim baru: ";
    cin >> maba[n].nim;
    cout <<"masukkan kom baru: ";
    cin >> maba[n].kom;

}
int main(){
    int pil;
    menu:
    cout << " \t\t MENU \n";
    cout << "1. tambah data\n";
    cout << "2. hapus data \n";
    cout << "3. tampilkan data \n";
    cout << "4. edit data \n";
    cout << "5. keluar \n";
    cout << "\n Pilih menu (1/2/3/4) ? ";
    cin >> pil;
    if (pil == 1)
        tambah_data();
    else if (pil == 2)
        hapus_data();
    else if (pil == 3)
        tampilkan_data();
        else if(pil == 4)
        edit();
    else if (pil == 5)
        exit(1); // atau bisa pakai return(0)
    else
    {
        cout << "pilihan tak tersedia...!!!\n";
    }
    goto menu;
    getch();
}

void tambah_data()
{
    if (n < nmax)
    {
        cout << "nama : ";
        cin>>maba[n].nama;
        
        cout << "NIM : ";
        cin >> maba[n].nim;
        cout << "Kom : ";
        cin >> maba[n].kom;
        n++;
    }
    else
        cout << "\n data telah melebihi...!!!\n maksimal data = " << nmax;
}
void hapus_data()
{
    int x;
    cout << "pilih data yang akan dihapus (1 s.d. 5) : ";
    cin >> x;
    if (x < n && x > 0)
    {
        for (int i = x; i < n; i++)
        {
            //strncpy(maba[i - 1].nama, maba[x].nama);
            maba[i-1].nama=maba[x].nama;
            maba[i - 1].nim = maba[x].nim;
            maba[i - 1].kom = maba[x].kom;
        }
        n--;
    }
    else if (x == n)
        n--;
    else
        cout << "\n data yang ingin dihapus tidak ada...!!!\n";
}
void tampilkan_data()
{
    if (n == 0)
        cout << "Tidak ada data yang disimpan...!!!\n";
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << "Data ke-" << i + 1 << " : ";
            cout << "\nNama : " << maba[i].nama;
            cout << "\nNIM : " << maba[i].nim;
            cout << "\nKom : " << maba[i].kom;
            cout << endl;
        }
    }
}