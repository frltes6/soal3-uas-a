/*
Nama Program : Soal 3
Nama         : Muhammad Zefa Inzaghi
NPM          : 140810240067
Tanggal Buat : 21 November 2024
Deskripsi    : 
*/
#include <iostream>
#include <fstream>
using namespace std;


struct siswa
{
    string nama;
    float tugas;
    float uts;
    float uas;
    float nilaiAkhir;

float hitungNilaiAkhir() {

    float nilaiAkhir = (tugas * 0.25) + (uts * 0.35) + (uas * 0.40 );
}

};

int bacaDataSiswa(const string &soal_3_nilai, const string &soal_3_nama, siswa dataSiswa[]){
    ifstream file("soal_3_nilai.txt");

    int index = 0;
    float tugas, uts, uas;

    while(file >> tugas >> uts >> uas){
        dataSiswa[index].tugas;
        dataSiswa[index].uts;
        dataSiswa[index].uas;
    }

    file.close();
    
    int index = 0;
    string nama;

    while(file >> nama){
        dataSiswa[index].nama;
    }

    file.close();

}

int main() {

    

}