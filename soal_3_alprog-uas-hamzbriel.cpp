/*
Nama Program : Soal 3
Nama         : Hamzah Abdillah Gabriela
NPM          : 140810240029
Tanggal Buat : 21 November 2024
Deskripsi    :
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Siswa {
    string nama;
    double nilaiAkhir;
};

double hitungNilaiAkhir(int tugas, int uts, int uas) {
    return tugas * 0.25 + uts * 0.35 + uas * 0.4;
}

void bubbleSort(Siswa siswa[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1 - i; ++j) {
            if (siswa[j].nama > siswa[j + 1].nama) {
                Siswa temp = siswa[j];
                siswa[j] = siswa[j + 1];
                siswa[j + 1] = temp;
            }
        }
    }
}


int main() {
    ifstream fileNama("soal_3_nama.txt");
    if (!fileNama) {
        cerr << "Gagal membuka file soal_3_nama.txt" << endl;
        return 1;
    }

    ifstream fileNilai("soal_3_nilai.txt");
    if (!fileNilai) {
        cerr << "Gagal membuka file soal_3_nilai.txt" << endl;
        return 1;
    }

    const int maxSiswa = 8;
    Siswa siswa[maxSiswa];
    string nama;
    int tugas, uts, uas;
    int index = 0;

    while (getline(fileNama, nama) && index < maxSiswa) {
        fileNilai >> tugas >> uts >> uas;
        siswa[index].nama = nama;
        siswa[index].nilaiAkhir = hitungNilaiAkhir(tugas, uts, uas);
        ++index;
    }

    fileNama.close();
    fileNilai.close();

    ofstream fileRekap("soal_3_rekap.txt");
    if (!fileRekap) {
        cerr << "Gagal membuka file soal_3_rekap.txt" << endl;
        return 1;
    }

    for (int i = 0; i < index; ++i) {
        fileRekap << siswa[i].nama << " " << siswa[i].nilaiAkhir << endl;
    }

    fileRekap.close();

    bubbleSort(siswa, index);

    ofstream fileTerurut("soal_3_terurut.txt");
    if (!fileTerurut) {
        cerr << "Gagal membuka file soal_3_terurut.txt" << endl;
        return 1;
    }

    for (int i = 0; i < index; ++i) {
        fileTerurut << siswa[i].nama << " " << siswa[i].nilaiAkhir << endl;
    }

    fileTerurut.close();
    return 0;
}