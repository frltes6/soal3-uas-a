/*
Nama Program : Soal 3
Nama         : Srikandi Rahmawati
NPM          : 140810240071
Tanggal Buat : 21 Nov 2024
Deskripsi    : Rekap nilai
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    float total[8];

    ifstream namaFile1 ("soal_3_nama.txt");
    string nama[8];
    for (int i=0; i<8; i++){
    namaFile1 >> nama[i];
    }

    ifstream namaFile2 ("soal_3_nilai.txt");
    float nilai[3][8];
    for (int i=0; i<8; i++){
        namaFile2 >> nilai[1][i] >> nilai[2][i] >> nilai[3][i];
        total[i] = ((nilai[1][i])/4) + ((nilai[2][i])*0.35) + ((nilai[3][i]/3)*0.4);
    }

    ofstream namaFile3 ("soal_3_rekap.txt", ios::app);
    for (int i=0; i<8; i++){
        namaFile3 << nama[i];
        namaFile3 << " \t";
        namaFile3 << total[i];
    }
}