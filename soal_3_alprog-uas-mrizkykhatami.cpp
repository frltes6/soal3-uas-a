/*
Nama Program :
Nama         :
NPM          :
Tanggal Buat :
Deskripsi    :
*/
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
   int n;
   cin >> n;
   string list_nama[n];
   string nilai_rata[n];
   ofstream myfile_nama;
   myfile_nama.open("soal_3_nama.txt");
   cout << "Masukan nama   :" << endl;
   for (int i = 0; i < n; i++)
   {
      string nama;
      cin.ignore();
      getline(cin, nama);
      myfile_nama << nama << endl;
      list_nama[i] = nama;
   }
   myfile_nama.close();

   ofstream myfile_nilai;
   myfile_nilai.open("soal_3_nilai.txt");
   cout << "Masukan nilai   :" << endl;
   for (int i = 0; i < n; i++)
   {
      string nilai;
      string buffer;
      double temp_nilai;
      for (int j = 0; j < 3; j++)
      {
         cin >> buffer;
         temp_nilai += stod(buffer);
         nilai.append(buffer + " ");
      }
      nilai_rata[i] = temp_nilai / 3;
      myfile_nilai << nilai << endl;
   }
   myfile_nilai.close();

   ofstream myfile_rekap;
   myfile_rekap.open("soal_3_rekap.txt");
   for (int i = 0; i < n; i++)
   {
      myfile_rekap << list_nama[i] << " " << nilai_rata[i] << endl;
   }
   myfile_rekap.close();
}