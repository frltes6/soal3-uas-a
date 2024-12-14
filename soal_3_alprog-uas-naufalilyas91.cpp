/*
Nama Program : soal_3.cpp
Nama         : Naufal Fakhri Ilyas
NPM          : 140810220068
Tanggal Buat : 21 November 2024
Deskripsi    : Merekap nilai
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <algorithm>

struct Siswa {
    std::string nama;
    double nilai_akhir;
};

std::vector<std::string> bacaNama(const std::string& namaFile) {
    std::ifstream file(namaFile);
    std::vector<std::string> daftarNama;
    std::string nama;
    while (std::getline(file, nama)) {
        daftarNama.push_back(nama);
    }
    return daftarNama;
}

std::vector<double> bacaNilaiDanHitung(const std::string& namaFile) {
    std::ifstream file(namaFile);
    std::vector<double> nilaiAkhir;
    std::string baris;
    while (std::getline(file, baris)) {
        std::istringstream iss(baris);
        double tugas, uts, uas;
        if (iss >> tugas >> uts >> uas) {
            double nilai = (tugas * 0.25) + (uts * 0.35) + (uas * 0.40);
            nilaiAkhir.push_back(nilai);
        }
    }
    return nilaiAkhir;
}

void simpanRekap(const std::string& namaFile, const std::vector<Siswa>& dataSiswa) {
    std::ofstream file(namaFile);
    for (const auto& siswa : dataSiswa) {
        file << siswa.nama << " " << std::fixed << std::setprecision(2) << siswa.nilai_akhir << "\n";
    }
}

void simpanTerurut(const std::string& namaFile, std::vector<Siswa> dataSiswa) {
    std::sort(dataSiswa.begin(), dataSiswa.end(), [](const Siswa& a, const Siswa& b) {
        return a.nilai_akhir < b.nilai_akhir;
    });
    std::ofstream file(namaFile);
    for (const auto& siswa : dataSiswa) {
        file << siswa.nama << " " << std::fixed << std::setprecision(2) << siswa.nilai_akhir << "\n";
    }
}

int main() {
    std::string fileNama = "soal_3_nama.txt";
    std::string fileNilai = "soal_3_nilai.txt";
    std::string fileRekap = "soal_3_rekap.txt";
    std::string fileTerurut = "soal_3_terurut.txt";

    std::vector<std::string> daftarNama = bacaNama(fileNama);

    std::vector<double> daftarNilai = bacaNilaiDanHitung(fileNilai);

    std::vector<Siswa> dataSiswa;
    for (size_t i = 0; i < daftarNama.size(); ++i) {
        dataSiswa.push_back({daftarNama[i], daftarNilai[i]});
    }

    simpanRekap(fileRekap, dataSiswa);

    simpanTerurut(fileTerurut, dataSiswa);

    std::cout << "Proses selesai. Data telah disimpan ke file.\n";

    return 0;
}