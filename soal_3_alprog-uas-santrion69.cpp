/*
Nama Program : soal 3
Nama         : Satrio Rafi Fahrezi
NPM          : 140810240063
Tanggal Buat : 21 November 2024
Deskripsi    :
*/
// #include <iostream>
// #include <fstream>
// using namespace std;
// int main(){
//     ofstream file ("soal_3_nilai.txt");
//     if (!file.is_open()){
//         cout << "file tidak bisa dibuka!" << endl;
//         return 1;
//     }
// }
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Siswa {
    string nama;
    double tugas, uts, uas, nilaiAkhir;
};
double nilaiAkhir(double tugas, double uts, double uas) {
    return (tugas * 0.25) + (uts * 0.35) + (uas * 0.40);
}
int nama(const string& namaFile, Siswa siswa[], int maxSiswa) {
    ifstream file(namaFile);
    int i = 0;
    while (i < maxSiswa && getline(file, siswa[i].nama)) {
        ++i;
    }
    file.close();
    return i;
}
int nilai(const string& namaFile, Siswa siswa[], int jumlahSiswa) {
    ifstream file(namaFile);
    for (int i = 0; i < jumlahSiswa; ++i) {
        file >> siswa[i].tugas >> siswa[i].uts >> siswa[i].uas;
        siswa[i].nilaiAkhir = nilaiAkhir(siswa[i].tugas, siswa[i].uts, siswa[i].uas);
    }
    file.close();
    return 0;
}
void tulisKeFile(const string& namaFile, Siswa siswa[], int jumlahSiswa) {
    ofstream file(namaFile);
    for (int i = 0; i < jumlahSiswa; ++i) {
        file << siswa[i].nama << " " << siswa[i].nilaiAkhir << endl;
    }
    file.close();
}
void sorting(Siswa siswa[], int jumlahSiswa) {
    for (int i = 0; i < jumlahSiswa - 1; ++i) {
        for (int j = 0; j < jumlahSiswa - i - 1; ++j) {
            if (siswa[j].nilaiAkhir < siswa[j + 1].nilaiAkhir) {
                swap(siswa[j], siswa[j + 1]);
              }
         }
     }
} 

int main() {
    const int MAX_SISWA = 100;
    Siswa siswa[MAX_SISWA];

    int jumlahSiswa = nama("soal_3_nama.txt", siswa, MAX_SISWA);
    if (jumlahSiswa == 0) return 1;

    if (nilai("soal_3_nilai.txt", siswa, jumlahSiswa) == 0) return 1;

    tulisKeFile("soal_3_rekap.txt", siswa, jumlahSiswa);

    sorting(siswa, jumlahSiswa);

    tulisKeFile("soal_3_terurut.txt", siswa, jumlahSiswa);

    return 0;
}
