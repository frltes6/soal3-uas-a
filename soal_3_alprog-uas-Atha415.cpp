/*
Nama Program : 
Nama         : Muhammad Farras Atha
NPM          : 140810240033
Tanggal Buat : 21 November 2024
Deskripsi    : 
*/

#include <iostream>
#include <fstream>
using namespace std;

float hitung;

int main(){
    int n;
    string nama[8];
    ifstream infile("soal_3_nama.txt");
    for (int i = 0;i <2; i++){
        getline(infile, nama[i]);
    } 
    cout << nama[1];
}