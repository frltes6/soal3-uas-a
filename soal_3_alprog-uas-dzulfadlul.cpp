/*
Nama Program : soal_3
Nama         : Dzulfadlul
NPM          : 140810230085
Tanggal Buat : 21/11/2024
Deskripsi    : rekap
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Student {
    std::string name;
    std::vector<double> scores;
    double average;
};

int main() {
    std::ifstream nameFile("soal_3_nama.txt");
    std::vector<Student> students;
    std::string name;
    while (std::getline(nameFile, name)) {
        students.push_back({ name, {}, 0.0 });
    }
    nameFile.close();

    std::ifstream scoreFile("soal_3_nilai.txt");
    double score;
    int i = 0;
    while (scoreFile >> score) {
        students[i].scores.push_back(score);
        if (students[i].scores.size() == 3) {
            students[i].average = (students[i].scores[0] + students[i].scores[1] + students[i].scores[2]) / 3.0;
            i++;
        }
    }
    scoreFile.close();

    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.average > b.average;
    });

    std::ofstream rekapFile("soal_3_rekap.txt");
    for (const auto& student : students) {
        rekapFile << std::fixed << std::setprecision(2);
        rekapFile << student.name << ": " << student.average << "\n";
    }
    rekapFile.close();

    std::ofstream terurutFile("soal_3_terurut.txt");
    for (const auto& student : students) {
        terurutFile << std::fixed << std::setprecision(2);
        terurutFile << student.name << ": " << student.average << "\n";
    }
    terurutFile.close();

    return 0;
}