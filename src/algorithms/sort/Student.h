#ifndef SELECTION_SORT_STUDENT_H
#define SELECTION_SORT_STUDENT_H

#include <iostream>

struct Student {
    std::string name;
    int score;

    // bool operator<(const Student &other) {
    //     return score != other.score ? score > other.score : name < other.name;
    // }

    friend std::ostream &operator<<(std::ostream &os, const Student &student) {
        os << student.name << ": " << student.score << "|";
        return os;
    }

    friend bool operator<(const Student &lhs, const Student &rhs) {
        return lhs.score != rhs.score ? lhs.score > rhs.score : lhs.name < rhs.name;
    }
};

#endif // SELECTION_SORT_STUDENT_H