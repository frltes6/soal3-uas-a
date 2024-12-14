/*
Nama Program :
Nama         : Ranabil Ramy
NPM          : 140810240085
Tanggal Buat :
Deskripsi    :
*/


#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct datas{
    string nama;
    double nilai;
};

void namaDanNilai(int banyak,datas kumpulan[]){
    ifstream file("soal_3_nama.txt");
    string temp;
    for (int i = 0; i < banyak; i++){
        getline(file,temp);
        kumpulan[i].nama = temp;
}
file.close();   
    ifstream file2("soal_3_nilai.txt");
    float angka1,angka2,angka3;
    for (int i = 0; i < banyak; i++){
        file2 >> angka1 >> angka2 >> angka3;
        kumpulan[i].nilai = (angka1*(25/100) + angka2*(35/100) + angka3*(40/100));
        cout << kumpulan[i].nilai << endl;
    }
file.close();
}

void masukinFile(int banyak,datas kumpulan[]){
    ofstream file("soal_3_rekap.txt");
    for (int i = 0; i < banyak; i++){
        file << kumpulan[i].nama << " " << kumpulan[i].nilai << endl;
    }
    file.close();
}
void masukinUrutAlfabet(int banyak,datas kumpulan[]){
    for (int i = 0; i < banyak; i++){
        for (int j = 0; j < banyak; j++){
            if (kumpulan[i].nama < kumpulan[j].nama){
                datas temp = kumpulan[i];
                kumpulan[i] = kumpulan[j];
                kumpulan[j] = temp;
            }
        }
    }
    
    ofstream file("soal_3_terurut.txt");
    for (int i = 0; i < banyak; i++){
        file << kumpulan[i].nama << " " << kumpulan[i].nilai << endl;
    }
    file.close();
}
int main(){
   datas kumpulan[100];
   ifstream file("soal_3_nama.txt");
   int banyak = 0;
   string temp;
   while (getline(file,temp)){
       banyak++;
   }
   cout << banyak;
   file.close();
   namaDanNilai(banyak,kumpulan);
//    masukinFile(banyak,kumpulan);
//    masukinUrutAlfabet(banyak,kumpulan);
}
//problem angka = 0