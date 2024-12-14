/*
Nama Program : Soal 3
Nama         : Katrina Grace Kwok
NPM          : 140810240011
Tanggal Buat : 21 November 2024
Deskripsi    : Menulis nilai akhir dan mengurut nama sesuai alfabet ke file
*/
#include <iostream>
#include <fstream>
using namespace std;
struct mahasiswa{
    string nama;
    double tugas;
    double uts;
    double uas;
    double rata;
};
bool name(const mahasiswa& a, mahasiswa& b){
    return a.nama < b.nama;
}
int main(){
    mahasiswa Data[8];
    ifstream infile;
    infile.open("soal_3_nama.txt");
    for(int i=0; i<8; i++){
        getline(infile, Data[i].nama);
    }
    infile.close();

    infile.open("soal_3_nilai.txt");
    for(int i=0; i<8; i++){
        infile>>Data[i].tugas>>Data[i].uts>>Data[i].uas;
    }
    infile.close();

    ofstream outfile;
    outfile.open("soal_3_rekap.txt");
    for(int i=0; i<8; i++){
        Data[i].rata = (Data[i].tugas*25/100)+(Data[i].uts*35/100)+(Data[i].uas*40/100);
        outfile<<Data[i].nama<<" "<<Data[i].rata<<endl;
    }
    outfile.close();

    for(int i=0; i<8; i++){
        for(int j=0; j<8-i-1; j++){
            if(Data[i].nama>Data[i+1].nama){
                mahasiswa temp = Data[i];
                Data[i]=Data[i+1];
                Data[i+1]=temp;
            }
        }
    }
    
    outfile.open("soal_3_terurut.txt");
    for(int i=0; i<8; i++){
        outfile<<Data[i].nama<<" "<<Data[i].rata<<endl;
    }
    outfile.close();
    cout<<"Data udah dimasukkan dan sudah diurutkan"<<endl;
    return 0;
}