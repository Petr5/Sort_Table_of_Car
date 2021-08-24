//
// Created by petrm on 22.08.2021.
//

#include "Student.h"


namespace student
{

    Student::Student(std::string &name, std::string &faculty, int group, int score) {
        this->name = name;
        this->faculty = faculty;
        this->group = group;
        this->score = score;

    }
    std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << student.name << "\t" << student.faculty << "\t" << student.group << "\t" <<  student.score;
        return os;
    }

    bool Student::operator>(const Student& other) {
        // compare student's score
        if (this->score > other.score){
            return true;
        }
        else if (this->score < other.score){
            return false;
        }
        else{ // compare name of student
            for (int i =0; i < std::min(this->name.size(), other.name.size()); i++){
                if (this->name[i] < other.name[i]){
                    return true;
                }
                else if (this->name[i] > other.name[i]){
                    return false;
                }

            }
            return false; // because the same score and the same name mean eqaul student
        }
        return false;
    }
    bool Student::operator<(const Student& other) {
        // compare student's score
        if (this->score < other.score){
            return true;
        }
        else if (this->score > other.score){
            return false;
        }
        else{ // compare name of student
            for (int i =0; i < std::min(this->name.size(), other.name.size()); i++){
                if (this->name[i] > other.name[i]){
                    return true;
                }
                else if (this->name[i] < other.name[i]){
                    return false;
                }

            }
            return false; // because the same score and the same name mean eqaul student
        }
        return false;
    }
    bool Student::operator<=(const Student& other){
        return !operator>( other);
    }



}
