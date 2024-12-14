/*
Nama Program : tugas 3
Nama         : Fauzan Dzaki Sulaiman
NPM          : 140810240017
Tanggal Buat : 21 November 2024
Deskripsi    : menghitung nilai kuis, uts, uas siswa
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
    string line;
    int nilai;
    char nama;
    ifstream infile;
    infile.open("soal_3_nama.txt");
    while (getline(infile, line)) {
        ifstream file;
        file.open("soal_3_nilai.txt");
        getline(file, nilai);
    }
    infile.close();
}