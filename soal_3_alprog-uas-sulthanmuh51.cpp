/*
Nama Program :
Nama         : Sulthan Muhammad Hizbullah Saripudin
NPM          : 140810240053
Tanggal Buat :
Deskripsi    :
*/

#include <iostream>
#include <fstream>
using namespace std;

struct siswa
{
    string nama;
    double nilai;
};
int main()
{
    ifstream fileNama, fileNilai;
    fileNama.open("soal_3_nama.txt");
    fileNilai.open("soal_3_nilai.txt");
    string nama;
    double nilai, sum = 0;
    int angka = 1;
    char buff;
    while (fileNilai >> nilai)
    {
        fileNilai.get(buff);
        if (buff == ' ')
        {
            angka++;
        }
        switch (angka)
        {
            case 1:
            sum += nilai * 25 / 100;
            break;

            case 2:
            sum += nilai * 35 / 100;
            break;

            case 3:
            sum += nilai * 40 / 100;
            nilai = sum;
            angka = 1;
            sum = 0;
            break;
        }
    }
    int count = 0;
    while(getline(fileNama, nama))
    {
        count++;
    }

}