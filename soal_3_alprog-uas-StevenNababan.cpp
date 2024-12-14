/*
Nama Program : Soal 3
Nama         : Steven Hapnico Santagati Nababan
NPM          : 140810240065
Tanggal Buat : 21 November 2024
Deskripsi    : Soal 3 UAS
*/

#include <iostream>
#include <fstream>

using namespace std;

struct dataSiswa{
    string namadpn;
    string namablkg;
    double tugas;
    double uts;
    double uas;
};

int main(){
    int n = 8;
    dataSiswa siswa[n];
    ifstream nama("soal_3_nama.txt");
    for(int i = 0; i < n; i++){
        cin >> ws;
        nama >> siswa[i].namadpn >> siswa[i].namablkg;
    }
    ifstream nilai("soal_3_nilai.txt");
    for(int i = 0; i < n; i++){
        cin >> ws;
        nilai >> siswa[i].tugas >> siswa[i].uts >> siswa[i].uas;
    }
    double nilaiakhir[n];
    for(int i = 0; i < n; i++){
        nilaiakhir[i] =  siswa[i].tugas*25/100 + siswa[i].uts*35/100 + siswa[i].uas*40/100;
    }
    
    ofstream rekap ("soal_3_rekap.txt");
    if(!rekap.is_open()){
        cout << "file tidak bisa dibuka";
    }
    else{
        for(int i = 0; i < n; i++){
            rekap << siswa[i].namadpn << " " << siswa[i].namablkg << " " << nilaiakhir[i] << endl;
        }
    }

    ofstream terurut("soal_3_terurut.txt");
    
}