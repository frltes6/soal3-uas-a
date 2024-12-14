/*
Nama Program :
Nama         : Muhammad Rafif Widyadhana
NPM          : 140810240083
Tanggal Buat :
Deskripsi    : 
*/
#include<iostream>
#include<fstream>
using namespace std;

struct mahasiswa
{
    string nama;
    double nilai;
};

void tukar(mahasiswa &arr1, mahasiswa &arr2){
    mahasiswa temp = arr1;
    arr1 = arr2;
    arr2 = temp;
}

void bubbleShort(mahasiswa arr[], int panjang){
for ( int i = 0; i < panjang; i++){
    for (int j = 0; j < panjang; j++){
        if (arr[j].nama > arr[j+1].nama && j != panjang-1){
            tukar(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){

    mahasiswa mhs[100];
    fstream nilai;
    fstream nama;
    fstream rekap;
    nama.open("soal_3_nama.txt");
    nilai.open("soal_3_nilai.txt");
    rekap.open("soal_3_rekap.txt");


    string s;
    string n;
    int hitung = 0;
    while(getline(nilai,s)){
        getline(nama,n);
        int panjang = s.length();
        double ntotal = 0;
        int nilai[3];
        int counter = 0;
        for ( int i = 0; i < panjang; i++){
            if (isdigit(s[i])){
                nilai[counter] = stoi(s.substr(i,2));
                counter++;
                i+=2;
            }
        }
        ntotal = nilai[0]*0.25 + nilai[1]*0.35 + nilai[2]*0.4;
        rekap << n << " " << ntotal << endl;
        mhs[hitung].nama = n; mhs[hitung].nilai = ntotal;
        hitung++;
    }

    nama.close();
    nilai.close();
    ofstream sorted;
    sorted.open("soal_3_terurut.txt");
    bubbleShort(mhs,hitung);

    for (int i = 0; i < hitung; i++){
        sorted << mhs[i].nama << "\t" << mhs[i].nilai << endl;
    }
    sorted.close();
    return 0;
}