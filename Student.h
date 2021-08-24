//
// Created by petrm on 22.08.2021.
//

#ifndef PROJECT_STUDENT_H
#define PROJECT_STUDENT_H





#include <string>
#include<vector>
#include <cmath>
#include <algorithm>
#include <iostream>

namespace student
{

    class Student {
        public:
            Student(std::string& name, std::string& faculty , int group, int score);
            friend std::ostream& operator<<(std::ostream& os, const Student& car);
            bool operator>(const Student& other);
            bool operator<=(const Student& other);
            bool operator<(const Student& other);
        private:
            int score;
            int group;
            std::string faculty;
            std::string name;

        };

}



#endif //PROJECT_STUDENT_H
