#include "Word.h"
#include <iomanip>

Word::Word(string eng, string viet) : english(eng), vietnamese(viet) {}

string Word::getEnglish() const { return english; }
string Word::getVietnamese() const { return vietnamese; }
void Word::setVietnamese(string viet) { vietnamese = viet; }

char Word::getFirstChar() const {
    if (english.empty()) return '\0';
    return tolower(english[0]);
}

// So sánh không phân biệt hoa thường
bool Word::equals(string otherEng) const {
    string s1 = english;
    string s2 = otherEng;
    for (char& c : s1) c = tolower(c);
    for (char& c : s2) c = tolower(c);
    return s1 == s2;
}

void Word::print() const {
    cout << "   - " << left << setw(15) << english << ": " << vietnamese << endl;
}