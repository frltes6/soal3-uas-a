/*
Nama Program : Soal 3
Nama         : Nabil Rizky Aulia
NPM          : 140810240045
Tanggal Buat : 21/11/2024
Deskripsi    : Nilai mahasiswa
*/

#include <bits/stdc++.h>
using namespace std;

void sorting(string (&nama)[], int (&nilai)[]){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8 - i - 1; j++){
      for(int k = 0; k < (nama[j].length() && nama[j + 1].length()); k++){
        if(nama[j][k] > nama[j + 1][k]){
          string temps = nama[j + 1];
          nama [j + 1] = nama[j];
          nama[j] = temps;

          int temp = nilai[j + 1];
          nilai [j + 1] = nilai[j];
          nilai[j] = temp;
        }
      }
    }
  }
}

int main(){
  string nama[8];
  int nilai[8][3];
  int hasil[8];

  ifstream fnama ("soal_3_nama.txt");
  ifstream fnilai ("soal_3_nilai.txt");
  string baris;

  int count = 0;
  while(getline(fnama, baris)){
    nama[count] = baris;
    count++;
  }

  count = 0;
  int temp = 0;
  while(getline(fnilai, baris)){
    nilai[count][1] = stoi(baris.substr(0, 2));
    nilai[count][2] = stoi(baris.substr(3, 4));
    nilai[count][3] = stoi(baris.substr(6, 7));
    hasil[count] = nilai[count][1] + nilai[count][2] + nilai[count][3];
    hasil[count] /= 3;

    count++;
  }

  // dari sini kebawah meledak

  ofstream frekap ("soal_3_rekap.txt", ios::app);
  for(int i = 0; i < 8; i++){
    frekap << nama[i] << " " << hasil[i] << endl;
  }

  sorting(nama, hasil);

  ofstream fterurut ("soal_3_terurut.txt");
  for(int i = 0; i < 8; i++){
    fterurut << nama[i] << "\t\t" << hasil[i] << endl;
  }
}