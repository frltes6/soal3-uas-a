/*
Nama :Muhammad Rakha Al Rovi
Npm : 140810210052
kelas : B 
Tanggal : 21 November 2024
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

struct Siswa {
    std::string nama;
    float tugas, uts, uas, nilaiAkhir;
};

std::vector<std::string> bacaFileNama(const std::string& namaFile) {
    std::ifstream file(namaFile);
    std::vector<std::string> namaSiswa;
    std::string nama;

    if (!file.is_open()) {
        std::cerr << "Error: File \"" << namaFile << "\" tidak ditemukan atau tidak dapat dibuka.\n";
        return namaSiswa;
    }

    while (std::getline(file, nama)) {
        namaSiswa.push_back(nama);
    }

    file.close();
    return namaSiswa;
}

std::vector<std::vector<float>> bacaFileNilai(const std::string& namaFile) {
    std::ifstream file(namaFile);
    std::vector<std::vector<float>> nilaiSiswa;
    std::string line;

    if (!file.is_open()) {
        std::cerr << "Error: File \"" << namaFile << "\" tidak ditemukan atau tidak dapat dibuka.\n";
        return nilaiSiswa;
    }

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::vector<float> nilai(3); 
        if (iss >> nilai[0] >> nilai[1] >> nilai[2]) {
            nilaiSiswa.push_back(nilai);
        }
    }

    file.close();
    return nilaiSiswa;
}

std::vector<Siswa> hitungNilaiAkhir(const std::vector<std::string>& namaSiswa, const std::vector<std::vector<float>>& nilaiSiswa) {
    std::vector<Siswa> daftarSiswa;

    for (size_t i = 0; i < namaSiswa.size(); ++i) {
        Siswa siswa;
        siswa.nama = namaSiswa[i];
        siswa.tugas = nilaiSiswa[i][0];
        siswa.uts = nilaiSiswa[i][1];
        siswa.uas = nilaiSiswa[i][2];
        siswa.nilaiAkhir = (siswa.tugas * 0.25f) + (siswa.uts * 0.35f) + (siswa.uas * 0.40f);
        daftarSiswa.push_back(siswa);
    }

    return daftarSiswa;
}

void tulisFileRekap(const std::vector<Siswa>& daftarSiswa, const std::string& namaFile) {
    std::ofstream file(namaFile);

    if (!file.is_open()) {
        std::cerr << "Error: File \"" << namaFile << "\" tidak dapat dibuka untuk penulisan.\n";
        return;
    }

    for (const auto& siswa : daftarSiswa) {
        file << siswa.nama << " " << std::fixed << std::setprecision(2) << siswa.nilaiAkhir << "\n";
    }

    file.close();
}

void tulisFileTerurut(const std::vector<Siswa>& daftarSiswa, const std::string& namaFile) {
    std::ofstream file(namaFile);

    if (!file.is_open()) {
        std::cerr << "Error: File \"" << namaFile << "\" tidak dapat dibuka untuk penulisan.\n";
        return;
    }

    std::vector<Siswa> sortedSiswa = daftarSiswa;
    std::sort(sortedSiswa.begin(), sortedSiswa.end(), [](const Siswa& a, const Siswa& b) {
        return a.nilaiAkhir > b.nilaiAkhir;
    });

    for (const auto& siswa : sortedSiswa) {
        file << siswa.nama << " " << std::fixed << std::setprecision(2) << siswa.nilaiAkhir << "\n";
    }

    file.close();
}

int main() {
    std::string fileNama = "soal_3_nama.txt";   
    std::string fileNilai = "soal_3_nilai.txt"; 
    std::string fileRekap = "soal_3_rekap.txt"; 
    std::string fileTerurut = "soal_3_terurut.txt"; 

    std::vector<std::string> namaSiswa = bacaFileNama(fileNama);
    std::vector<std::vector<float>> nilaiSiswa = bacaFileNilai(fileNilai);

    if (namaSiswa.empty() || nilaiSiswa.empty() || namaSiswa.size() != nilaiSiswa.size()) {
        std::cerr << "Error: Data pada file input tidak sesuai.\n";
        return 1;
    }

    std::vector<Siswa> daftarSiswa = hitungNilaiAkhir(namaSiswa, nilaiSiswa);

    tulisFileRekap(daftarSiswa, fileRekap);
    tulisFileTerurut(daftarSiswa, fileTerurut);

    std::cout << "Proses selesai. Hasil disimpan di:\n";
    std::cout << "- " << fileRekap << "\n";
    std::cout << "- " << fileTerurut << "\n";

    return 0;
}


