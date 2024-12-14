/*
Nama Program : soal_3.cpp
Nama         : Muhammad Arkan Bintang Pratama
NPM          : 140810240037
Tanggal Buat : 21 November 2024
Deskripsi    : rekap dan mengurut
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Siswa {
    string nama;
    double ntotal;
};


bool compareByName(const Siswa &a, const Siswa &b) {
    return a.nama < b.nama;
}

int main() {
    ifstream nama("soal_3_nama.txt");
    ifstream nilai("soal_3_nilai.txt");
    ofstream rekap("soal_3_rekap.txt");
    ofstream terurut("soal_3_terurut.txt");

    
    if (!nama.is_open() || !nilai.is_open() || !rekap.is_open() || !terurut.is_open()) {
        cerr << "Gagal membuka salah satu file." << endl;
        return 1;
    }

    string s, n;
    vector<Siswa> siswaList;

    while (getline(nilai, s)) {
        if (getline(nama, n)) { 
            int panjang = s.length();
            double ntotal = 0;
            int nilai[3];
            int counter = 0;

            for (int i = 0; i < panjang && counter < 3; i++) {
                if (isdigit(s[i])) {
                    nilai[counter] = stoi(s.substr(i, 2));
                    counter++;
                    i += 2;
                }
            }

            if (counter == 3) { 
                ntotal = nilai[0] * 0.25 + nilai[1] * 0.35 + nilai[2] * 0.4;
                rekap << n << " " << ntotal << endl;
                siswaList.push_back({n, ntotal});
            } else {
                cerr << "Nilai tidak cukup untuk " << n << endl;
            }
        } else {
            cerr << "Tidak ada nama yang sesuai untuk nilai: " << s << endl;
        }
    }
    sort(siswaList.begin(), siswaList.end(), compareByName);

    
    for (const auto &siswa : siswaList) {
        terurut << siswa.nama << " " << siswa.ntotal << endl;
    }

   
    nama.close();
    nilai.close();
    rekap.close();
    terurut.close();

    return 0;
}



