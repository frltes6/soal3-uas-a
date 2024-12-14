/*
Nama Program :
Nama         : Rehan Aziz Hardiansyah
NPM          : 140810240075
Tanggal Buat : 21/11/2024
Deskripsi    :
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Mahasiswa{
    string nama;
    float nilaiAkhir;
};

void urutkan(Mahasiswa* data, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(data[j].nilaiAkhir>data[j+1].nilaiAkhir){
                swap(data[j],data[j+1]);
            }
        }
    }
}

int main(){
    ifstream Nama;
    ifstream Nilai;
    ofstream Rekap;
    ofstream Terurut;

    Nama.open("soal_3_nama.txt");
    Nilai.open("soal_3_nilai.txt");
    Rekap.open("soal_3_rekap.txt");
    Terurut.open("soal_3_terurut.txt");

    Mahasiswa data[100];

    int n=0;
    while(getline(Nama,data[n].nama)){
        float total=0,temp;
        Nilai>>temp;
        total+=temp*0.25;
        Nilai>>temp;
        total+=temp*0.35;
        Nilai>>temp;
        total+=temp*0.4;

        data[n].nilaiAkhir=total;

        Rekap<<data[n].nama<<" "<<data[n].nilaiAkhir<<endl;
        
        n++;
    }

    urutkan(data,n);

    for(int i=0;i<n;i++){
        Terurut<<data[i].nama<<" "<<data[i].nilaiAkhir<<endl; 
    }

    Nama.close();
    Nilai.close();
    Rekap.close();
    Terurut.close();

}
