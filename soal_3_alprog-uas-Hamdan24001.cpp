/*
Nama Program : Soal 3 (UAS)
Nama         : Hamdan Arif
NPM          : 140810240055
Tanggal Buat : 21 Nov 2024
Deskripsi    : Olah data 8 orang kemudian merekapnya
*/
#include <iostream>
#include <fstream>
using namespace std;

struct rapot{
    string nama;
    double nilai_akhir;
    double nilai_kuis;
    double nilai_uts;
    double nilai_uas;
};

void sorting(rapot repot[], int size){
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i;j++){
            if(repot[j].nama[0] < repot[j+1].nama[0]){
                rapot tukar = repot[j];
                repot[j] = repot[j+1];
                repot[j+1] = tukar;
            }
        }
    }
}

int main(){
    const int size = 8;
    rapot orang[size];
    // Input dari text
    ifstream in_file("soal_3_nama.txt");
    for(int i=0;i<size;i++){
        getline(in_file, orang[i].nama);
    }
    in_file.close();
    in_file.open("soal_3_nilai.txt");
    for(int i=0;i<size;i++){
        in_file >> orang[i].nilai_kuis >> orang[i].nilai_uts >> orang[i].nilai_uas;
        orang[i].nilai_akhir = ((0.25*orang[i].nilai_kuis)+(0.35*orang[i].nilai_uts)+(0.40*orang[i].nilai_uas));
    }
    in_file.close();

    // Output ke text
    ofstream out_file("soal_3_rekap.txt");
    for(int i=0;i<size;i++){
        out_file << orang[i].nama << " " << orang[i].nilai_akhir << endl;
    }
    out_file.close();
    sorting(orang,size);
    out_file.open("soal_3_terurut.txt");
    out_file << "_________________________________\n";
    out_file << "|\t\tNama\t\t\t|  Nilai|\n";
    out_file << "---------------------------------\n";
    for(int i=0;i<size;i++){
            out_file << "|" << orang[i].nama;
            if(orang[i].nama.length()>10 && orang[i].nama.length()<15) {out_file << "    \t\t|";}
            else if (orang[i].nama.length()>=15) {out_file << "    \t|";}
            else {out_file << "  \t\t\t|";}
            out_file << orang[i].nilai_akhir << "\t|\n";
    }
    out_file << "---------------------------------";
}