/*
Nama Program : soal_3
Nama         : Hana' Azzahro'
NPM          : 140810240039
Tanggal Buat : 21/11/2024
Deskripsi    :
*/
#include <iostream>
#include <fstream>
using namespace std;

struct Siswa{
    string nama;
    double nilaiakhir;
};

double hitungnilai(double tugas, double uts, double uas){
    return tugas * 0.25 + uts * 0.35 + uas * 0.40;
}

int main(){
    ifstream file1("soal_3_nama.txt");
    ifstream file2("soal_3_nilai.txt");
    if (file1.fail() || file2.fail()) {
        cout << "Error membuka file!" << endl;
        return 1;
    }

    Siswa datasiswa[100];
    int jumlahsiswa = 0;
    string nama;
    double tugas, uts, uas;

    while (getline(file1, nama) && file2 >> tugas >> uts >> uas) {
        datasiswa[jumlahsiswa].nama = nama;
        datasiswa[jumlahsiswa].nilaiakhir = hitungnilai(tugas, uts, uas);
        jumlahsiswa++;
    }
    file1.close();
    file2.close();

    ofstream file3("soal_3_rekap.txt");
    if (file3.fail()) {
        cout << "Error membuka file" << endl;
        return 1;
    }
    for (int i = 0; i < jumlahsiswa; i++){
        file3 << datasiswa[i].nama << " " << datasiswa[i].nilaiakhir << endl;
    }
    file3.close();

    for (int i = 0; i < jumlahsiswa - 1; i++){
        for (int j = 0; j < jumlahsiswa - 1 - i; j++){
            if (datasiswa[j].nilaiakhir < datasiswa[j + 1].nilaiakhir){
                Siswa temp = datasiswa[j];
                datasiswa[j] = datasiswa[j + 1];
                datasiswa[j + 1] = temp;
            }
        }
    }

    ofstream file4("soal_3_terurut.txt");
    if (!file4.is_open()){
        cout << "Error membuka file" << endl;
        return 1;
    }
    for (int i = 0; i < jumlahsiswa; i++){
        file4 << datasiswa[i].nama << " " << datasiswa[i].nilaiakhir << endl;
    }
    file4.close();

    return 0;
}
