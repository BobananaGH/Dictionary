#pragma once

#include <string>
#include <iostream>

using namespace std;

class Word {
private:
    string english; // Từ khóa(Key)
    string vietnamese; // Nhhiax của từ 

public:
    Word(string eng = "", string viet = "");

    string getEnglish() const;
    string getVietnamese() const;
    void setVietnamese(string viet);

    char getFirstChar() const;
    bool equals(string otherEng) const;
    void print() const;
};