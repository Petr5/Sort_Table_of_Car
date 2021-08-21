//
// Created by petrm on 21.08.2021.
//

#ifndef PROJECT_CAR_H
#define PROJECT_CAR_H

#include <string>
#include<vector>
#include <cmath>
#include <algorithm>
#include <iostream>

namespace car
{
    class Car {
        public:
        Car(std::string& name, std::string& faculty , int score, int group);
        friend std::ostream& operator<<(std::ostream& os, const Car& car);
        bool operator>(const Car& other);
        bool operator<=(const Car& other);
        bool operator<(const Car& other);
        private:
            int score;
            int group;
            std::string faculty;
            std::string name;

    };
}



#endif //PROJECT_CAR_H
