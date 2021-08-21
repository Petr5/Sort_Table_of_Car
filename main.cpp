#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Car.h"

using namespace std;
using namespace std::chrono;
void BubbleSort(std::vector<car::Car>& table);

std::vector<string> split (const string& s, const string& delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}
void BubbleSort(std::vector<car::Car>& table){
    for (int count = 0; count < table.size(); count ++){
        for(int i=0; i < table.size() - 1; i++){
            if (table[i] < table[i + 1]){
                std::swap(table[i], table[i + 1]);
            }
        }
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "i begin readnig file" << std::endl;
    std::string path = R"(C:\Users\petrm\Documents\SortTemplate\csv files\student 100000.csv)";

    std::string str;
    std::ifstream fin;
    fin.open(path);
    std::vector<car::Car> table;
    bool header = false;

    while (!fin.eof()) {
        str = "";
        std::getline(fin, str);
        if (!str.empty()){
            std::vector<std::string> vec = split(str, ",");
            if (header && str!=",,,"){

                car::Car my_car(vec[0], vec[1], std::stoi(vec[2]), std::stoi(vec[3]));
                table.push_back(my_car);
            }

            header = true;
        }

    }

    auto start = high_resolution_clock::now();
    BubbleSort(table);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << duration.count() / 1e6 <<"seconds" <<  std::endl;
    ofstream out;
    std::string path2 = R"(C:\Users\petrm\Documents\SortTemplate\csv files\sorted student 100000.csv)";
    out.open(path2);
    for (int j = 0; j < table.size(); j++){
        out << table[j]  << std:: endl;
    }

    return 0;
}
