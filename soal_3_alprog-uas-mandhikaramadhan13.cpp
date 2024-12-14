/*
Nama Program : soal_3.cpp
Nama         : Muhammad Andhika Ramadhan
NPM          : 140810240049
Tanggal Buat : 21 November 2024
Deskripsi    :
*/

#include <iostream>
#include <fstream>
using namespace std;

void fileNilai(fstream &myFile);

int main()
{
    fstream myFile;
    myFile.open("soal_3_nilai.txt");
    fileNilai(myFile);
}

void fileNilai(fstream &myFile)
{
    int nilai, index = 0, indexBaris = 0;
    float baris[8];
    if (myFile.is_open())
    {
        while (myFile >> nilai)
        {
            if (index == 0)
            {
                baris[indexBaris] += (nilai * 25) / 100;
            }
            else if (index == 1)
            {
                baris[indexBaris] += (nilai * 35) / 100;
            }
            else if (index == 2)
            {
                baris[indexBaris] += (nilai * 40) / 100;
                index = 0;
                indexBaris++;
            }
            index++;
        }
    }
}