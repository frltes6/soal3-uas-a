/*
Nama Program : soal_3.cpp
Nama         : Aisha Kinasih Susanto
NPM          : 140810240047
Tanggal Buat : 21 November 2024
Deskripsi    :
*/

#include <iostream>
#include <fstream>
using namespace std;

void swap(int&a, int&b) {
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(int arr, int n){
    for(int i = 0; i < n-1; i++){
        for(int j = 0; j < n-1-i; j++){
            if(arr[j] < arr[j+1]){
                swap(arr[j], arr[j+1]);
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

    int arr[200];

    int n = 0;

    bubbleSort(arr[], n);

    for(int i=0;i<n;i++){
        fileTerurut << arr[i]
    }

    fileNama.close();
    fileNilai.close();
    fileRekap.close();
    fileTerurut.close();
}