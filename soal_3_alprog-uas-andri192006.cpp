/*
Nama Program :Mengururtkan nilai
Nama         :Muhammad Andri Firmansyah
NPM          :140810240009
Tanggal Buat :11/21/2024
Deskripsi    :membaca file dan merata ratakannya lalu diurutkan sesuai alphabet
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct DataSiswa{
    string nama;
    double score[3];
};

void HitungBanyak(int & JBaris){
    fstream infile("soal_3_nama.txt");
    if(!infile){
        cerr<<"error"<<endl;
    }
    string baris;
    JBaris=0;
    while(getline(infile,baris)){
        JBaris++;
    }
}

void getNama(DataSiswa Siswa[],int JBaris){
    fstream infile("soal_3_nama.txt");
    string line;
    int NoId=0;
    while(getline(infile,line)){
        Siswa[NoId].nama =line.substr();
        NoId++;
    }
    infile.close();
}

void getNilai (DataSiswa Siswa[],int JBaris){
    fstream infile("soal_3_nilai.txt");
    if (!infile) {
        cerr << "Error" << endl;
    }
    for (int i = 0; i < JBaris; i++) {
        infile >> Siswa[i].score[0] >> Siswa[i].score[1] >> Siswa[i].score[2];
    }
    infile.close();
}

void HitungNilai(DataSiswa Siswa[],int JBaris){
    for (int i = 0; i <JBaris; i++)
    {
            Siswa[i].score[0]=Siswa[i].score[0]/4;
            Siswa[i].score[1]=Siswa[i].score[1]*(35.0/100.0);
            Siswa[i].score[2]=Siswa[i].score[2]*(0.4); 
    }
    
}

void HitungTotal(DataSiswa Siswa[], int JBaris, double NilaiTotal[]) {
    for (int i = 0; i < JBaris; i++) {
        NilaiTotal[i] = 0;
        for (int j = 0; j < 3; j++) {
            NilaiTotal[i] += Siswa[i].score[j];
        }
    }
}
void tukardouble(double& x,double& y){
    double temp =x;
    x=y;
    y=temp;
}

void tukarsiswa(DataSiswa& x,DataSiswa& y){
    DataSiswa temp =x;
    x=y;
    y=temp;
}

void UrutkanNilai(DataSiswa Siswa[],int JBaris,double NilaiTotal[]) {
    for (int i = 0; i < JBaris - 1; i++) {
        for (int j = 0; j < JBaris - i - 1; j++) {
            if (NilaiTotal[j] > NilaiTotal[j + 1]) {
                tukardouble(NilaiTotal[j], NilaiTotal[j + 1]);
                tukarsiswa(Siswa[j], Siswa[j + 1]);
            }
        }
    }
}

void CetakRekap(DataSiswa Siswa[], double NilaiTotal[], int JBaris) {
    ofstream outfile("soal_3_rekap.txt");
    if (!outfile) {
        cerr << "Error" << endl;
        return;
    }
    for (int i = 0; i < JBaris; i++) {
        outfile << Siswa[i].nama << " " << NilaiTotal[i] << endl;
    }
    outfile.close();
}


int main(){
    int JBaris =0;
    HitungBanyak(JBaris);
    double NilaiTotal[JBaris];
    DataSiswa Siswa[JBaris];
    cout<<JBaris<<endl;
    getNama(Siswa,JBaris);
    getNilai(Siswa,JBaris);
    HitungNilai(Siswa,JBaris);
    HitungTotal(Siswa,JBaris,NilaiTotal);
    CetakRekap(Siswa,NilaiTotal,JBaris);
    UrutkanNilai(Siswa,JBaris,NilaiTotal);
    for (int i = 0; i <JBaris; i++)
    {
        cout<<"Nama siswa : "<<Siswa[i].nama<<endl;
        cout<<"Nilai : "<<endl;
        for (int j = 0; j < 3; j++)
        {
            cout<<Siswa[i].score[j]<<endl;
        }
        
    }
    
}
