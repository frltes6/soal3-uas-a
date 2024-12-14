/*
Nama Program :soal 3
Nama         :Renadi Wilantar
NPM          :140810240061
Tanggal Buat :21/11/24
Deskripsi    :Rekap nilai
*/

#include <iostream>
#include <fstream> 
using namespace std;

int main() {
    ifstream file1;
    ifstream file2;
    ofstream file3;
    ofstream file4;

    file1.isopen("soal_3_nama.txt");

    //file1 >> ("soal_3_nama.txt") >> endl;

    file2.isopen("soal_3_nilai.txt");

    file3.isopen("soal_3_rekap.txt");
    
    file3 << ("soal_3_nama.txt") << " " << ("soal_3_nilai.txt") / 3 << endl;


}