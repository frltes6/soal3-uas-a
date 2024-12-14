/*
Nama Program : Nilai pada file
Nama         : Hansel Stevan Boike
NPM          : 140810240079
Tanggal Buat : 21/11/24
Deskripsi    : Menghitung nilai akhir dan mengurutkannya kedalam file
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student
{
    string name;
    double finalScore;
};

double calculateFinalScore(int tugas, int uts, int uas)
{
    return tugas * 0.25 + uts * 0.35 + uas * 0.40;
}

bool compareStudents(const Student &a, const Student &b)
{
    return a.finalScore > b.finalScore;
}

int main()
{
    ifstream nameFile("soal_3_nama.txt");
    ifstream scoreFile("soal_3_nilai.txt");
    ofstream rekapFile("soal_3_rekap.txt");
    ofstream sortedFile("soal_3_terurut.txt");

    vector<Student> students;
    string name;
    int tugas, uts, uas;

    while (getline(nameFile, name) && scoreFile >> tugas >> uts >> uas)
    {
        double finalScore = calculateFinalScore(tugas, uts, uas);
        students.push_back({name, finalScore});
        rekapFile << name << " " << finalScore << endl;
    }

    sort(students.begin(), students.end(), compareStudents);

    for (const auto &student : students)
    {
        sortedFile << student.name << " " << student.finalScore << endl;
    }

    nameFile.close();
    scoreFile.close();
    rekapFile.close();
    sortedFile.close();
}