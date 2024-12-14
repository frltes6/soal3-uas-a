/*
Nama Program :
Nama         : Hosea Dave Andersen
NPM          : 140810240089
Tanggal Buat : 21 November 2024
Deskripsi    : 
*/

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char ch;
    string nama[300];
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int nilai[300];

    ifstream infile1, infile2;
    infile1.open("soal_3_nama");
    infile2.open("soal_3_nilai");

    for (int i = 0; i < 7; i++){
        getline(infile1, nama[i]);
    }

}