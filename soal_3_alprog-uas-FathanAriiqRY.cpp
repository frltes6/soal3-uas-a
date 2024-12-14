/*
Nama Program :
Nama         : Fathan Ariiq Rasbi Yalis
NPM          : 140810240057
Tanggal Buat : 21/11/2024
Deskripsi    :
*/

#include <iostream>
#include <fstream>
using namespace std;


#include <iostream>
#include <fstream>
using namespace std;

struct mahasiswa{
    string nama;
    float nilaiAkhir;
};

void tukar(mahasiswa* status, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
                if (status[j].nama > status[j+1].nama){
                    swap(status[j],status[j+1]);
                }
        }
    }
}

int main(){
    ifstream fNama;
    ifstream nilai;
    ofstream rekap;
    ofstream urut;

    fNama.open("soal_3_nama.txt");
    nilai.open("soal_3_nilai.txt");
    rekap.open("soal_3_rekap.txt");
    urut.open("soal_3_terurut.txt");

    mahasiswa status[100];

    int n=0;
    while(getline(fNama,status[n].nama)){
        float total=0,angka;
        nilai>>angka;
        total+=angka*0.25;
        nilai>>angka;
        total+=angka*0.35;
        nilai >> angka;
        total+=angka*0.4;

        status[n].nilaiAkhir=total;

        rekap<<status[n].nama<<" "<<status[n].nilaiAkhir<<endl;
        
        n++;
    }

    tukar(status,n);

    for(int i=0;i<n;i++){
        urut<<status[i].nama<<"\t"<<status[i].nilaiAkhir<<endl; 
    }

    fNama.close();
    nilai.close();
    rekap.close();
    urut.close();
   

    return 0;
}

