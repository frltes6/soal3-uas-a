/*
Nama Program : soal_3
Nama         : Aulia Fadhila Mumtaza
NPM          : 140810240005
Tanggal Buat : 21 November 2024
Deskripsi    : Memasukkan hasil gabungan 2 file kedalam 1 file
*/
#include<iostream>
#include<fstream>
using namespace std;

struct mahasiswa{
    string nama;
    double nilai;
};

void sorting(mahasiswa mhs[], string n){
    for(int i=0; i < n; i++){
        for(int j=0; j < n;j++){
            if(mhs[j].nilai < mhs[j+1].nilai){
                swap(mhs[j].nilai,mhs[j+1].nilai)
            }
        }
    }
}

int main(){
    mahasiswa mhs[100];
    string n;

    fstream nama;
    fstream nilai;
    nama.open("soal_3_nama.txt");
    nilai.open("soal_3_nilai.txt");

    ofstream rekap, urutan;
    rekap.open("soal_3_rekap.txt");
    urutan.open("soal_3_terurut.txt");
    sorting(mhs,n);
    
}
