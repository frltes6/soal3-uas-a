/*
Nama Program :  soal_3.cpp
Nama         :  Valensius Alven
NPM          :  140810240059
Tanggal Buat :  21 November 2024
Deskripsi    :  Merekap dan Mengurutkan nilai dari siswa-siswa berdasarkan abjad a-z
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void bacaNama(const string& namaFile, string nama[], int& jumlah){
    ifstream file(namaFile);
    jumlah=0;
    while(getline(file, nama[jumlah])){
        jumlah++;
    }
    file.close();
}

void bacaNilai(const string& namaFile, int nilai[][3], int& jumlah){
    ifstream file(namaFile);
    jumlah=0;
    while(file>>nilai[jumlah][0]>>nilai[jumlah][1]>>nilai[jumlah][2]){
        jumlah++;
    }
    file.close();
}

void hitungNilai(string nama[], int nilai[][3], float nilaiAkhir[], int jumlah){
    for(int i=0;i<jumlah;i++){
        nilaiAkhir[i]=nilai[i][0]*0.25+nilai[i][1]*0.35+nilai[i][2]*0.40;
    }
}

void tulisRekap(const string& namaFile, string nama[], float nilaiAkhir[], int jumlah){
    ofstream file(namaFile);
    for(int i=0;i<jumlah;i++){
        file<<nama[i]<<" : "<<fixed<<setprecision(2)<<nilaiAkhir[i]<<endl;
    }
    file.close();
}

void swapString(string &a, string &b){
    string temp=a;
    a=b;
    b=temp;
}

void swapFloat(float &a, float &b){
    float temp=a;
    a=b;
    b=temp;
}
void bubbleSort(string nama[], float nilaiAkhir[], int jumlah){
    for(int i=0;i<jumlah-1;i++){
        for(int j=0;j<jumlah-i-1;j++){
            if (nama[j] > nama[j+1]){
                swapFloat(nilaiAkhir[j], nilaiAkhir[j+1]);
                swapString(nama[j], nama[j+1]);
            }
        }
    }
}

void tulisTerurut(const string& namaFile, string nama[], float nilaiAkhir[], int jumlah){
    ofstream file(namaFile);
    for(int i=0;i<jumlah;i++){
        file<<nama[i]<<" : "<<fixed<<setprecision(2)<<nilaiAkhir[i]<<endl;
    }
    file.close();
}

int main(){
    const string fileNama="soal_3_nama.txt";
    const string nilaiFile="soal_3_nilai.txt";
    const string recapFile="soal_3_rekap.txt";
    const string sortedFile="soal_3_terurut.txt";

    string nama[100];
    int nilai[100][3];
    float nilaiAkhir[100];
    int jumlah;

    bacaNama(fileNama, nama, jumlah);
    bacaNilai(nilaiFile, nilai, jumlah);

    hitungNilai(nama, nilai, nilaiAkhir, jumlah);

    tulisRekap(recapFile, nama, nilaiAkhir, jumlah);

    bubbleSort(nama, nilaiAkhir, jumlah);
    tulisTerurut(sortedFile, nama, nilaiAkhir, jumlah);

    cout<<"Proses selesai. File rekap dan terurut telah dibuat."<<endl;

    return 0;
}