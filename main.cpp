#include <iostream>
#include <cstdlib>
#include <string.h>
#include <stdio.h>

#define MAX_STACK 10

using namespace std;
struct data_penyewa{
        string nama[MAX_STACK],alamat[MAX_STACK], no_hp[MAX_STACK], NIK[MAX_STACK];
        int lama_main[MAX_STACK];
    };
int front = -1;
int rear = -1;

class Penyimpanan_data{
protected:
    data_penyewa data;
public:
     void get_data(){


        if(front == -1){
            cout << "Data masih kosong !" << endl;
            return ;
        }

        cout << "NAMA \t\t\t";
        cout << "ALAMAT\t\t\t";
        cout << "NO HP\t\t\t";
        cout << "NIK\t\t\t";
        cout << "LAMA MAIN\n";
        for(int i = front ; i <= rear; i++){
            cout << data.nama[i] << "\t\t\t";
            cout << data.alamat[i] << "\t\t\t";
            cout << data.no_hp[i] << "\t\t";
            cout << data.NIK[i] << "\t\t\t";
            cout << data.lama_main[i] << "\n";
         }
     }

    void  save_data(string  nama ,string alamat,string no_hp, string NIK, int lama_main){

        data.nama[rear] = nama;
        data.alamat[rear] = alamat;
        data.no_hp[rear] = no_hp;
        data.NIK[rear] = NIK;
        data.lama_main[rear] = lama_main;

        get_data();
    }

};

class Proses_data : public Penyimpanan_data{
private:
        string nama, alamat, no_hp, NIK;
        int lama_main;

public:

    void input_data(){
        cin.ignore();


        if((front == 0 && rear == MAX_STACK - 1) || (front == rear-1)){
            cout << "Penyimpanan data penuh !!!" << endl;
            return;
        }
        if(front == -1){
            front = 0;
        }

        if(rear == MAX_STACK - 1){
            rear=0;
        }else{
            rear=rear+1;
        }

         cout << "Masukkan NAMA penyewa : " ; getline(cin,nama);
         cout << "Masukkan ALAMAT penyewa : " ;getline(cin,alamat);
         cout << "Masukkan NO HP penyewa : " ; getline(cin,no_hp);
         cout << "Masukkan NIK penyewa : " ; getline(cin,NIK);
         cout << "Masukkan LAMA MAIN penyewa : " ; cin >> lama_main;

         save_data(nama,alamat,no_hp,NIK,lama_main);
    }

    void show_data(){

        Penyimpanan_data::get_data();
    }

    void delete_data(){
        string nama;
        if(front == -1){
            cout << "Antrian masih kosong" << endl;
            return;
        }

        nama = data.nama[front];

        if(front == rear){
            front = -1;
            rear = -1;
        }
        else if (front == MAX_STACK - 1){
            front = 0;
        }
        else{
            front = front + 1;
        }

        cout << "Data dengan nama : " << nama << " telah terhapus" << endl;
    }

};



class Menu{
    Proses_data objPData;
public:
    int pilih_menu(){
        int pilih_menu;
        cout << "Penyewaan lapangan futsal\n";
        cout << "1. Masukkan data\n";
        cout << "2. Tampilkan data\n";
        cout << "3. Hapus data\n";
        cout << "4. Exit\n";
        cout << "PILIH MENU : "; cin >> pilih_menu;
        return pilih_menu;
    }

    void eksekusi_menu(){
        bool loop = true;

        while(loop){
            int pilihan = pilih_menu();
            switch(pilihan){
                case 1:
                    cout << "Masukkan data\n";
                    objPData.input_data();
                    break;
                case 2:
                    cout << "Tampilkan data\n";
                    objPData.show_data();

                    break;
                case 3:
                    cout << "Hapus data\n";
                    objPData.delete_data();
                    break;
                case 4:
                    cout << "Terimakasih\n";
                    loop = false;
                    break;
            }
            system("pause");
            system("CLS");
        }

    }
};

int main(){
    Menu objmenu;
    objmenu.eksekusi_menu();


}
