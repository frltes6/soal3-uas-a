/*
Nama Program :
Nama         :Fitri Sahwalia
NPM          :140810240031
Tanggal Buat :21 November 2024
Deskripsi    :soal_3
*/

#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

struct Siswa{
    string Nama;
    int Nilai;
    int Rekap;
    int Terurut;
    int nilaiAkhir;
};




void urutkan(Siswa* data,int n){
    for (int i=0; i<n-1; i++){
        for (int j=0; j<n-1-i; j++){
            if(data[j].nilaiAkhir<data[j+1].nilaiAkhir){
                swap(data[j], data[j+1]);
                
            }
        }
    }
}

int main(){
    ifstream fileNama;
    ifstream fileNilai;
    ofstream fileRekap;
    ofstream fileTerurut;

    fileNama.open(soal_3_nama.txt);
    fileNilai.open(soal_3_nilai.txt);
    fileRekap.open(soal_3_rekap.txt);
    fileTerurut.open(soal_3_terurut.txt);

    fileNama.close();
    fileNilai.close();
    fileRekap.close();
    fileTerurut.close();



    

}