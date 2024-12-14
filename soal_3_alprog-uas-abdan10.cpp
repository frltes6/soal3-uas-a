/*
Nama Program : soal 3
Nama         : M Abdan Nur Falah
NPM          : 140810240023
Tanggal Buat : 21/11/2024
Deskripsi    : 
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Mahasiswa{
    string nama;
    float nilaiAkhir;
};

void urutkan(Mahasiswa* data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j].nama > data[j + 1].nama) { 
                swap(data[j], data[j + 1]);
            }
        }
    }
}

int main(){
    ifstream file_nama;
    ifstream file_nilai;
    ofstream file_rekap;
    ofstream file_terurut;

    file_nama.open("soal_3_nama.txt");
    file_nilai.open("soal_3_nilai.txt");
    file_rekap.open("soal_3_rekap.txt");
    file_terurut.open("soal_3_terurut.txt");

    Mahasiswa data[100];

    int n = 0;
    while(getline(file_nama,data[n].nama)){
        float total= 0,temp;
        file_nilai>>temp;
        total+=temp*0.25;
        file_nilai>>temp;
        total+=temp*0.35;
        file_nilai>>temp;
        total+=temp*0.4;

        data[n].nilaiAkhir=total;

        file_rekap<<data[n].nama<<" "<<data[n].nilaiAkhir<<endl;
        n++;
    }

    urutkan(data,n);

    for(int i=0;i<n;i++){
        file_terurut<<data[i].nama<<" "<<data[i].nilaiAkhir<<endl; 
    }

    file_nama.close();
    file_nilai.close();
    file_rekap.close();
    file_terurut.close();
   

    return 0;
}

