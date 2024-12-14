/*
Nama Program : Soal 3A UAS
Nama         : Bagas Abrar Abhirama
NPM          : 140810240051
Tanggal Buat : 21 November 2024
Deskripsi    : Program mengambil input dari file txt, lalu memasukkan htungan dan sorting ke file txt yang lain.
*/

#include <iostream>
#include <fstream>

using namespace std;

struct Siswa {
    string nama;
    double nilaiAkhir;
};

void bacaNamaSiswa(const char* fileNama, Siswa siswa[], int &jumlahSiswa) {
    ifstream in_file(fileNama);
    jumlahSiswa = 0;
    while (getline(in_file, siswa[jumlahSiswa].nama)) {
        jumlahSiswa++;
    }
    in_file.close();
}

void hitungHasilAkhir(const char* fileNilai, Siswa siswa[], int jumlahSiswa) {
    ifstream in_file(fileNilai);
    for (int i = 0; i < jumlahSiswa; i++) {
        double tugas, uts, uas;
        in_file >> tugas >> uts >> uas;
        siswa[i].nilaiAkhir = (tugas * 0.25) + (uts * 0.35) + (uas * 0.40);
    }
    in_file.close();
}

void gabungkanData(const char* fileRekap, Siswa siswa[], int jumlahSiswa) {
    ofstream out_file(fileRekap);
    for (int i = 0; i < jumlahSiswa; i++) {
        out_file << siswa[i].nama << " " << siswa[i].nilaiAkhir << endl;
    }
    out_file.close();
}

void urutkanData(Siswa siswa[], int jumlahSiswa) {
    for (int i = 0; i < jumlahSiswa - 1; i++) {
        for (int j = i + 1; j < jumlahSiswa; j++) {
            if (siswa[i].nama > siswa[j].nama) {
                Siswa temp = siswa[i];
                siswa[i] = siswa[j];
                siswa[j] = temp;
            }
        }
    }
}

void tulisDataTerurut(const char* fileTerurut, Siswa siswa[], int jumlahSiswa) {
    ofstream out_file(fileTerurut);
    for (int i = 0; i < jumlahSiswa; i++) {
        if (i == 3) {
            out_file << siswa[i].nama << "\t" << "\t" << siswa[i].nilaiAkhir << endl;
        } else {
            out_file << siswa[i].nama << "\t" << siswa[i].nilaiAkhir << endl;
        }
    }
    out_file.close();
}

int main() {
    const char* fileNama = "soal_3_nama.txt";
    const char* fileNilai = "soal_3_nilai.txt";
    const char* fileRekap = "soal_3_rekap.txt";
    const char* fileTerurut = "soal_3_terurut.txt";

    Siswa siswa[100];
    int jumlahSiswa;

    bacaNamaSiswa(fileNama, siswa, jumlahSiswa);
    hitungHasilAkhir(fileNilai, siswa, jumlahSiswa);
    gabungkanData(fileRekap, siswa, jumlahSiswa);
    urutkanData(siswa, jumlahSiswa);
    tulisDataTerurut(fileTerurut, siswa, jumlahSiswa);

    cout << "Data berhasil diolah!" << endl;

    return 0;
}