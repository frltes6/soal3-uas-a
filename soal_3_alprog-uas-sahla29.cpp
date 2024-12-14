/*
Nama Program : soal_3.cpp
Nama         : Nailatus Sahlah
NPM          : 140810240021
Tanggal Buat : 21 November 2024
Deskripsi    : membuat data nama dan nilai jadi terurut
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Siswa{
    string nama;
    double nilaiAkhir;
};

double hitungNilai(double tugas, double uts, double uas){
    return tugas * 0.25 + uts * 0.35 + uas * 0.40;
}

int main(){
    ifstream file1("soal_3_nama.txt");
    ifstream file2("soal_3_nilai.txt");
    if (file1.fail() || file2.fail()) {
        cout << "Error membuka file!" << endl;
        return 1;
    }

    Siswa dataSiswa[100];
    int jumlahSiswa = 0;
    string nama;
    double tugas, uts, uas;

    while (getline(file1, nama) && file2 >> tugas >> uts >> uas) {
        dataSiswa[jumlahSiswa].nama = nama;
        dataSiswa[jumlahSiswa].nilaiAkhir = hitungNilai(tugas, uts, uas);
        jumlahSiswa++;
    }
    file1.close();
    file2.close();

    ofstream file3("soal_3_rekap.txt");
    if (file3.fail()) {
        cout << "Error membuka file" << endl;
        return 1;
    }
    for (int i = 0; i < jumlahSiswa; i++){
        file3 << dataSiswa[i].nama << " " << dataSiswa[i].nilaiAkhir << endl;
    }
    file3.close();

    for (int i = 0; i < jumlahSiswa - 1; i++){
        for (int j = 0; j < jumlahSiswa - 1 - i; j++){
            if (dataSiswa[j].nilaiAkhir < dataSiswa[j + 1].nilaiAkhir){
                Siswa temp = dataSiswa[j];
                dataSiswa[j] = dataSiswa[j + 1];
                dataSiswa[j + 1] = temp;
            }
        }
    }

    ofstream file4("soal_3_terurut.txt");
    if (!file4.is_open()){
        cout << "Error membuka file" << endl;
        return 1;
    }
    for (int i = 0; i < jumlahSiswa; i++){
        file4 << dataSiswa[i].nama << " " << dataSiswa[i].nilaiAkhir << endl;
    }
    file4.close();

    return 0;
}

