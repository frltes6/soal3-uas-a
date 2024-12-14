/*
Nama Program : Soal 3
Nama         : Dean Frederic Wijaya
NPM          : 140810240027
Tanggal Buat : 21 November 2024
Deskripsi    : Melakukan rekap data
*/

#include<iostream>
#include<fstream>
using namespace std;

int main(){
    string nama;
    string tugas, uts, uas;
    ifstream file_nama("soal_3_nama.txt");
    while(getline(file_nama, nama)){
        cout << nama << endl;
    }

    file_nama.close();

    ifstream file_nilai("soal_3_nilai.txt");
    while(getline(file_nilai, uts)){
        cout << uts << endl;
    }

    file_nilai.close();
}
