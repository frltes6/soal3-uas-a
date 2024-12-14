/*
Nama Program : soal_3
Nama         : Syifa Azzahra
NPM          : 140810240041
Tanggal Buat : 21 November 2024
Deskripsi    :
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Mahasiswa
{
    string namaMahasiswa;
    double nilaiMahasiswa;
};

void tukar(Mahasiswa &arr1, Mahasiswa &arr2){
    Mahasiswa temp = arr1;
    arr1 = arr2;
    arr2 = temp;
}

void bubbleShort(Mahasiswa arr[], int pjg){
for ( int i = 0; i < pjg; i++){
    for (int j = 0; j < pjg; j++){
        if (arr[j].nilaiMahasiswa > arr[j+1].nilaiMahasiswa && j != pjg-1){
            tukar(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){

    Mahasiswa mahasiwaa[100];
    fstream nilaiMahasiswa;
    fstream namaMahasiswaa;
    fstream rekapNilai;
    namaMahasiswaa.open("soal_3_nama.txt");
    nilaiMahasiswa.open("soal_3_nilai.txt");
    rekapNilai.open("soal_3_rekap.txt");


    string s;
    string n;
    int hasil = 0;
    while(getline(nilaiMahasiswa,s)){
        getline(namaMahasiswaa,n);
        int panjang = s.length();
        double jumlahtotal = 0;
        int nilai[3];
        int counter = 0;
        for ( int i = 0; i < panjang; i++){
            if (isdigit(s[i])){
                nilai[counter] = stoi(s.substr(i,2));
                counter++;
                i+=2;
            }
        }
        jumlahtotal = nilai[0]0.25 + nilai[1]0.35 + nilai[2]*0.4;
        rekapNilai << n << " " << jumlahtotal << endl;
        mahasiwaa[hasil].namaMahasiswa = n; mahasiwaa[hasil].nilaiMahasiswa = jumlahtotal;
        hasil++;
    }

    namaMahasiswaa.close();
    nilaiMahasiswa.close();
    ofstream sorted;
    sorted.open("sorted.txt");
    bubbleShort(mahasiwaa,hasil);

    for (int i = 0; i < hasil; i++){
        sorted << mahasiwaa[i].namaMahasiswa << "\t" << mahasiwaa[i].nilaiMahasiswa << endl;
    }
    sorted.close();
    return 0;
}
