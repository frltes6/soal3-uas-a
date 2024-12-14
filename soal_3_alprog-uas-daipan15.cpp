/*
Nama Program : nomor3.cpp
Nama         : Dhaifan Ramadhani Juliawan
NPM          : 1401810240015
Tanggal Buat : 21/11/2024
Deskripsi    : mendata nilai anak dan mengurutkannya
*/

#include <iostream>
#include <fstream>
using namespace std;


// struct structNilai{
//     float nilai1;
//     float nilai2;
//     float nilai3;
// };

// int main(){
//     ofstream nama;
//     string s[8];

    // nama.open("soal_3_nama.txt");
    //     for(int i=0; i<9; i++){
    //         getline(cin,s[i]);
    //         nama << s[i] << endl;
    //     }
    // nama.close();

    // ofstream nilai;
    // structNilai anak[8];
    // float nilaiTotal = 0;

    // nilai.open("soal_3_nilai.txt");
    //     for(int i=0; i<8; i++){
    //         cin >> anak[i].nilai1 >> anak[i].nilai2 >> anak[i].nilai3;
    //         nilai << anak[i].nilai1 << " " << anak[i].nilai2 << " " << anak[i].nilai3 << endl;
    //     }

    // nilai.close();
// }

struct dataAnak{
    string nama;
    float nilaiHasilUjung;
};

void sortUrutkan(dataAnak* data, int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(data[j].nilaiHasilUjung>data[j+1].nilaiHasilUjung){
                swap(data[j],data[j+1]);
            }
        }
    }
}

int main(){
    ifstream namaFile;
    ifstream isiNilai;
    ofstream rekapanNilai;
    ofstream fileUrutan;

    namaFile.open("soal_3_nama.txt");
    isiNilai.open("soal_3_nilai.txt");
    rekapanNilai.open("soal_3_rekap.txt");
    fileUrutan.open("soal_3_terurut.txt");

    dataAnak data[100];

    int n=0;
    while(getline(namaFile,data[n].nama)){
        float total=0,temp;

        isiNilai>>temp;
        total+=temp*0.25;

        isiNilai>>temp;
        total+=temp*0.35;

        isiNilai>>temp;
        total+=temp*0.4;

        data[n].nilaiHasilUjung=total;

        rekapanNilai<<data[n].nama<<" "<<data[n].nilaiHasilUjung<<endl;
        
        n++;
    }

    sortUrutkan(data,n);

    for(int i=0;i<n;i++){
        fileUrutan<<data[i].nama<<" "<<data[i].nilaiHasilUjung<<endl; 
    }

    namaFile.close();
    isiNilai.close();
    rekapanNilai.close();
    fileUrutan.close();
    return 0;
}