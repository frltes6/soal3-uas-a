/*
Nama Program : soal_3.cpp
Nama         : Yazid Aqila Haikal
NPM          : 140810240091
Tanggal Buat : 21 November 2024
Deskripsi    :
*/

#include <iostream>
#include <fstream>
using namespace std;

void urut(string nama[], double nilai[]){
    for(int i = 0; i < 8; i++){
        for(int j = i+1; j < 8; j++){
            for(int k = 0; k < nama[i].length(); k++){
                if(nama[i][k] < nama[j][k]){
                    string save = nama[i];
                    nama[i] = nama[j];
                    nama[j] = save;

                    int temp = nilai[i];
                    nilai[i] = nilai[j];
                    nilai[j] = nilai[i];
                    break;
                }
            }
        }
    }
}

int main(){
    ifstream inFile1, inFile2;
    inFile1.open("soal_3_nama.txt");
    inFile2.open("soal_3_nilai.txt");
    ofstream outFile1, outFile2;
    outFile1.open("soal_3_rekap.txt"); // ini gtw pakein ios_base nya gmn
    outFile2.open("soal_3_terurut.txt"); // ini juga, jadinya

    string nama[8];
    double nilai[8];

    for(int i = 0; i < 8; i++){
        getline(inFile1 >> ws, nama[i]);
        double a, b, c;
        inFile2 >> a >> b >> c;
        nilai[i] = (a*25/100) + (b*35/100) + (c*40/100);

        outFile1 << nama[i] << "\t\t" << nilai[i] << "\n";
    }

    urut(nama, nilai);

    for(int i = 0; i < 8; i++){
        outFile2 << nama[i] << "\t\t" << nilai[i] << "\n";
        cout << nama[i] << "\t\t" << nilai[i] << endl;
    }

    inFile1.close();
    inFile2.close();
    outFile1.close();
    outFile2.close();
}