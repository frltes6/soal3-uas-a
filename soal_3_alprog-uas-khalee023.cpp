/*
Nama Program :soal_3.cpp
Nama         :Khalit Putra Afana
NPM          :140810240007
Tanggal Buat :21 november 2024
Deskripsi    :
*/


#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

int main(){
    ifstream nilai, nama;
    nilai.open("soal_3_nilai.txt");
    nama.open("soal_3_nama.txt");
    ofstream rekap;
    rekap.open("soal_3_rekap.txt", ios::app);
    // terurut.open("soal_3_terurut.txt", ios::app);

    // nama
    float rata;
    string avg, name;
    while(getline(nama, name)){
        rekap << name;

        // mencari rata"
        getline(nilai, avg);
        float a = stof(avg.substr(0,2))*0.25;
        float b = stof(avg.substr(3,4))*0.35;
        float c = stof(avg.substr(6,7))*0.4;
        float rata = a+b+c;
        rekap << " " << fixed << rata << endl;
    }
    rekap.close();
    ifstream rekap;
    rekap.open("soal_3_rekap.txt");
    string s;
    priority_queue <string> urut;
    while(getline(rekap, s)){
        urut.push(s);
    }
    while(){
        
    }


}
