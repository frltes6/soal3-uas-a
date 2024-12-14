/*
Nama Program : soal 3
Nama         : Muhammad Haidar Arkan
NPM          : 140810240019
Tanggal Buat : 21/11/2024
Deskripsi    : program untuk membaca file txt dan kemudian mencari rata rata dari masing masing nama
*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct Siswa{
    string nama;
    double nilai[3];
};

void HitungBanyak(int & jumlahBaris){
    fstream file_masuk("soal_3_nama.txt");
    string baris;
    jumlahBaris=0;
    while(getline(file_masuk,baris)){
        jumlahBaris++;
    }
}

void nama(Siswa Siswa[],int jumlahBaris){
    fstream file_masuk("soal_3_nama.txt");
    string line;
    int NoId=0;
    while(getline(file_masuk,line)){
        Siswa[NoId].nama =line.substr();
        NoId++;
    }
    file_masuk.close();
}

void ambilNilai (Siswa Siswa[],int jumlahBaris){
    fstream file_masuk("soal_3_nilai.txt");

    for (int i = 0; i < jumlahBaris; i++) {
        file_masuk >> Siswa[i].nilai[0] >> Siswa[i].nilai[1] >> Siswa[i].nilai[2];
    }
    file_masuk.close();
}

void HitungNilai(Siswa Siswa[],int jumlahBaris){
    for (int i = 0; i <jumlahBaris; i++)
    {
            Siswa[i].nilai[0]=Siswa[i].nilai[0]/4;
            Siswa[i].nilai[1]=Siswa[i].nilai[1]*(35.0/100.0);
            Siswa[i].nilai[2]=Siswa[i].nilai[2]*(0.4); 
    }
    
}

void HitungTotal(Siswa Siswa[], int jumlahBaris, double NilaiTotal[]) {
    for (int i = 0; i < jumlahBaris; i++) {
        NilaiTotal[i] = 0;
        for (int j = 0; j < 3; j++) {
            NilaiTotal[i] += Siswa[i].nilai[j];
        }
    }
}

void CetakRekap(Siswa Siswa[], double NilaiTotal[], int jumlahBaris) {
    ofstream file_keluar("soal_3_rekap.txt");
    for (int i = 0; i < jumlahBaris; i++) {
        file_keluar << Siswa[i].nama << " " << NilaiTotal[i] << endl;
    }
    file_keluar.close();
}


int main(){
    int jumlahBaris =0;

    HitungBanyak(jumlahBaris);

    double NilaiTotal[100];
    Siswa Siswa[100];

    nama(Siswa,jumlahBaris);
    ambilNilai(Siswa,jumlahBaris);
    HitungNilai(Siswa,jumlahBaris);
    HitungTotal(Siswa,jumlahBaris,NilaiTotal);
    CetakRekap(Siswa,NilaiTotal,jumlahBaris);
    
}
