/*
Nama Program : Program Rekap
Nama         : Zedka YA
NPM          : 140810240069
Tanggal Buat : 21/11/2024
Deskripsi    : Nilai
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream in_file1("soal_3_nama.txt");
  ifstream in_file2("soal_3_nilai.txt");
  ofstream out_file1("soal_3_rekap.txt");
  ofstream out_file2("soal_3_terurut.txt");
  for (int i = 0; i < 8; i++)
  {
      double nilai;
      string nama;
      nama >> in_file1;
      nilai >> in_file2;
      double hasil;
      hasil = nilai/3;
      out_file1 << nama << hasil << endl;
  }
  in_file1.close();
  in_file2.close();
  out_file1.close();
  out_file2.close();
}