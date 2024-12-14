/*
Nama            : Andrew Orisar Boekorsyom
NPM             : 140810217001
Hari/Tanggal    : Kamis, 21 November 2024
Deskripsi       : UAS Soal3
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;


struct Siswa {
    string nama;
    float tugas, uts, uas, akhir;
};


float hitungNilaiAkhir(float tugas, float uts, float uas) {
    return (tugas * 0.25f) + (uts * 0.35f) + (uas * 0.40f);
}


vector<string> bacaNama(const string &namaFile) {
    vector<string> namaSiswa;
    ifstream file(namaFile);
    string line;
    while (getline(file, line)) {
        namaSiswa.push_back(line);
    }
    file.close();
    return namaSiswa;
}


vector<vector<float>> bacaNilai(const string &namaFile) {
    vector<vector<float>> nilaiSiswa;
    ifstream file(namaFile);
    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        vector<float> nilai(3);
        ss >> nilai[0] >> nilai[1] >> nilai[2];
        nilaiSiswa.push_back(nilai);
    }
    file.close();
    return nilaiSiswa;
}


void tulisRekap(const string &namaFile, const vector<Siswa> &data) {
    ofstream file(namaFile);
    for (const auto &s : data) {
        file << s.nama << " " << s.akhir << endl;
    }
    file.close();
}


void tulisTerurut(const string &namaFile, const vector<Siswa> &data) {
    ofstream file(namaFile);
    for (const auto &s : data) {
        file << s.nama << " " << s.akhir << endl;
    }
    file.close();
}

int main() {
    
    string fileNama = "soal_3_nama.txt";
    string fileNilai = "soal_3_nilai.txt";
    string fileRekap = "soal_3_rekap.txt";
    string fileTerurut = "soal_3_terurut.txt";

    vector<string> namaSiswa = bacaNama(fileNama);
    vector<vector<float>> nilaiSiswa = bacaNilai(fileNilai);

    
    vector<Siswa> dataSiswa;
    for (size_t i = 0; i < namaSiswa.size(); ++i) {
        Siswa s;
        s.nama = namaSiswa[i];
        s.tugas = nilaiSiswa[i][0];
        s.uts = nilaiSiswa[i][1];
        s.uas = nilaiSiswa[i][2];
        s.akhir = hitungNilaiAkhir(s.tugas, s.uts, s.uas);
        dataSiswa.push_back(s);
    }

    
    tulisRekap(fileRekap, dataSiswa);

    
    sort(dataSiswa.begin(), dataSiswa.end(), [](const Siswa &a, const Siswa &b) {
        return a.akhir > b.akhir;
    });

    
    tulisTerurut(fileTerurut, dataSiswa);

    cout << "Proses selesai. Hasil telah disimpan di file " << fileRekap << " dan " << fileTerurut << endl;

    return 0;
}
