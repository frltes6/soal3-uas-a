/*
Nama Program : rekap nilai siswa
Nama         : rais abiyyu putra
NPM          : 140810220069
Tanggal Buat : 21 November 2024
Deskripsi    :
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct Siswa {
    string name;
    float tugas, uts, uas, final_score;
};

void sortir(Siswa paraSiswa[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (paraSiswa[j].final_score < paraSiswa[j + 1].final_score) {
                Siswa temp = paraSiswa[j];
                paraSiswa[j] = paraSiswa[j + 1];
                paraSiswa[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int MAX_paraSiswa = 100;
    Siswa paraSiswa[MAX_paraSiswa];
    int SiswaCount = 0;

    
    ifstream nameFile("soal_3_nama.txt");
    if (!nameFile) {
        cerr << "Error: File soal_3_nama.txt tidak ditemukan!" << endl;
        return 1;
    }


    string line;
    while (getline(nameFile, line) && SiswaCount < MAX_paraSiswa) {
        paraSiswa[SiswaCount].name = line;
        ++SiswaCount;
    }
    nameFile.close();


    ifstream scoreFile("soal_3_nilai.txt");
    if (!scoreFile) {
        cerr << "Error: File soal_3_nilai.txt tidak ditemukan!" << endl;
        return 1;
    }

    int index = 0;
    while (getline(scoreFile, line) && index < SiswaCount) {
        istringstream scoreStream(line);
        scoreStream >> paraSiswa[index].tugas >> paraSiswa[index].uts >> paraSiswa[index].uas;
     
        paraSiswa[index].final_score = paraSiswa[index].tugas * 0.25f + 
                                      paraSiswa[index].uts * 0.35f + 
                                      paraSiswa[index].uas * 0.40f;
        ++index;
    }
    scoreFile.close();

    if (index != SiswaCount) {
        cerr << "Error: Jumlah nilai tidak sesuai dengan jumlah nama siswa!" << endl;
        return 1;
    }

    
    ofstream rekapFile("soal_3_rekap.txt");
    for (int i = 0; i < SiswaCount; ++i) {
        rekapFile << paraSiswa[i].name << " " << paraSiswa[i].final_score << endl;
    }
    rekapFile.close();

 
    sortir(paraSiswa, SiswaCount);

    
    ofstream sortedFile("soal_3_terurut.txt");
    for (int i = 0; i < SiswaCount; ++i) {
        sortedFile << paraSiswa[i].name << " " << paraSiswa[i].final_score << endl;
    }
    sortedFile.close();

    cout << "Proses selesai. File soal_3_rekap.txt dan soal_3_terurut.txt telah dibuat." << endl;

    return 0;
}


