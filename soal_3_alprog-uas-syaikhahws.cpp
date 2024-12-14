/*
Nama Program : Soal_3
Nama         : Syaikha Habibtiana Widi Sukamto
NPM          : 140810240025
Tanggal Buat : 21 November 2024
Deskripsi    : menyusun file
*/

#include <iostream>
#include <fstream>
using namespace std;

void tukar(int a, int b){
    int temp = a; 
    a=b;
    b=temp;
}

int main(){
    int character;
    character=0;
    string namaFile;
    cin >> namaFile;
    ifstream file;
    file.open(namaFile);{
        if(namaFile.get(character)){
            character++;
        }
    }
    cout<<character;

    string namaFile2;
    cin >> namaFile;
    ofstream file;
    file << namaFile2;
    
}












