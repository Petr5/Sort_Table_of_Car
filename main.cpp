#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "Student.h"

using namespace std;
using namespace std::chrono;


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
void BubbleSort(std::vector<student::Student>& table){
    for (int count = 0; count < table.size(); count ++){
        for(int i=0; i < table.size() - 1; i++){
            if (table[i] < table[i + 1]){
                std::swap(table[i], table[i + 1]);
            }
        }
    }
}

int Partition(int low, int high, std::vector<student::Student>& table){
    int i = (low - 1);
    for (int j = low; j <= high- 1; j++){
        if (table[j] > table[high]){
            i++;
            std::swap(table[i], table[j]);
        }
    }
    std::swap(table[i + 1], table[high]);
    return (i + 1);
}

void QuickSort(int low, int high, std::vector<student::Student>& table){
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = Partition(low, high, table);

        // Separately sort elements before
        // partition and after partition
        QuickSort( low, pi - 1 ,table);
        QuickSort( pi + 1, high, table);
    }
}

//void ShakerSort

void merge(std::vector<student::Student>& table, int const left, int const mid, int const right)
{
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
            *rightArray = new int[subArrayTwo];
    std::vector<student::Student> leftTable, rightTable;
    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftTable.push_back(table[left + i]);
    for (auto j = 0; j < subArrayTwo; j++)
        rightTable.push_back(table[mid + 1 + j]);

    auto indexOfSubTableOne = 0, // Initial index of first sub-array
    indexOfSubTableTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubTableOne < subArrayOne && indexOfSubTableTwo < subArrayTwo) {
        if (leftTable[indexOfSubTableOne] <= rightTable[indexOfSubTableTwo]) {
            table[indexOfMergedArray] = leftTable[indexOfSubTableOne];
            indexOfSubTableOne++;
        }
        else {
            table[indexOfMergedArray] = rightTable[indexOfSubTableTwo];
            indexOfSubTableTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubTableOne < subArrayOne) {
        table[indexOfMergedArray] = leftTable[indexOfSubTableOne];
        indexOfSubTableOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubTableTwo < subArrayTwo) {
        table[indexOfMergedArray] = rightTable[indexOfSubTableTwo];
        indexOfSubTableTwo++;
        indexOfMergedArray++;
    }
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(std::vector<student::Student>& table, int const begin, int const end)
{
    if (begin >= end)
        return; // Returns recursivly

    auto mid = begin + (end - begin) / 2;
    mergeSort(table, begin, mid);
    mergeSort(table, mid + 1, end);
    merge(table, begin, mid, end);
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::cout << "i begin readnig file" << std::endl;
    int count = 0;
    int index = 100000;
    ofstream fout;
    std::string path3 = "C:\\Users\\petrm\\Documents\\SortTemplate\\Sorted Student table\\MergeSort\\graph.txt";
    fout.open(path3);
    fout << "MergeSort, seconds" << std::endl;
    while (count < 9)
    {

        std::string path = "C:\\Users\\petrm\\Documents\\SortTemplate\\csv files\\student " + std::to_string(index) + ".csv";

        std::string str;
        std::ifstream fin;
        fin.open(path);
        std::vector<student::Student> table;
        bool header = false;
        std::string head;
        while (!fin.eof()) {
            str = "";
            std::getline(fin, str);
            if (!header){
                head = str;
            }
            if (!str.empty()){
                std::vector<std::string> vec = split(str, ",");
                if (header && str!=",,,"){

                    student::Student my_student(vec[0], vec[1], std::stoi(vec[2]), std::stoi(vec[3]));
                    table.push_back(my_student);
                }

                header = true;
            }

        }

        auto start = high_resolution_clock::now();
//        QuickSort(0, index - 1, table);
        mergeSort(table, 0, index - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        std::cout << duration.count() / 1e6 <<"seconds" <<  std::endl;
        ofstream out;
        std::string path2 = "C:\\Users\\petrm\\Documents\\SortTemplate\\Sorted Student table\\MergeSort\\sorted student " + std::to_string(index) + ".csv";
        out.open(path2);
        out << head;
        for (int j = 0; j < table.size(); j++){
            out << table[j]  << std:: endl;
        }

        fout << duration.count() / 1e6 << "\t";
        index += 50000;
        count ++;
    }
    return 0;

}


