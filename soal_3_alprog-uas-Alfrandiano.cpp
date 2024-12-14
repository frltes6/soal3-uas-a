/*
Nama Program :soal 3
Nama         : Alfrandiano Imanuel Rionaldo Holle
NPM          : 140810247001
Tanggal Buat : 21/11/2024
Deskripsi    : 
*/
#include <iostream>
#include <fstream>

using namespace std;


struct Siswa{
    string nama;
    int nilai;
}


int main(){
    ofstream myFile;
    int nilaiTotal = 0;

    myFile.open("soal_3_nilai.txt");
    Siswa siswa[10];

    for (int i = 0; i < 8; i++) {
        myFile >> siswa[i].nilai[0] >> siswa[i].nilai[1] >> siswa[i].nilai[2];
    }

    fstream infile("soal_3_nama.txt");
    string line;
    int no = 0;

    while(getline(infile,line)){
        siswa[no].nama =line.substr();
        no++;
    }

    for (int i = 0; i <JBaris; i++){
            siswa[i].nilai[0]=Siswa[i].nilai[0]/4;
            siswa[i].nilai[1]=Siswa[i].nilai[1]*(35.0/100.0);
            siswa[i].nilai0[2]=Siswa[i].nilai[2]*(0.4); 
    }
    




}
