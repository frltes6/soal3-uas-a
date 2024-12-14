/*
Nama Program : UAS Nomor 3 Praktikum Algoritma dan Pemrograman
Nama         : Ibnu Zaidan Akbar
NPM          : 140810240043
Tanggal Buat : 21 November 2024
Deskripsi    : Program menuliskan data baik tidak urut maupun urut ke dalam file lain berbentuk txt
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Mahasiswa{
    string nama;
    float nilaiAkhir;
};

void tukar(Mahasiswa data[], int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if(data[j].nama > data[j + 1].nama){
                Mahasiswa temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int main(){
    ifstream fileNama;
    ifstream fileNilai;
    ofstream fileRekap;
    ofstream fileTerurut;

    fileNama.open("soal_3_nama.txt");
    fileNilai.open("soal_3_nilai.txt");
    fileRekap.open("soal_3_rekap.txt");
    fileTerurut.open("soal_3_terurut.txt");

    Mahasiswa data[100];

    int n = 0;
    while(getline(fileNama,data[n].nama)){
        float total = 0,temp;
        fileNilai >> temp;
        total += temp * 0.25;
        fileNilai >> temp;
        total += temp * 0.35;
        fileNilai >> temp;
        total += temp * 0.4;

        data[n].nilaiAkhir = total;
        fileRekap << data[n].nama << " " << data[n].nilaiAkhir << endl;
        n++;
    }

    tukar(data, n);
    for(int i = 0; i < n; i++){
        fileTerurut << data[i].nama << "\t\t" << data[i].nilaiAkhir << endl; 
    }

    fileNama.close();
    fileNilai.close();
    fileRekap.close();
    fileTerurut.close();
}