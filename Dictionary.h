#pragma once

#include "Node.h"
#include <fstream> 
#include <string>

using namespace std;

class Dictionary {
private:
    static const int TABLE_SIZE = 26;
    Node* table[TABLE_SIZE];

    int hashFunction(char keyChar);
    void clear(); 

public:
    Dictionary();
    ~Dictionary();

    // Thêm tham số 'verbose' để tắt thông báo khi load file
    void add(string eng, string viet, bool verbose = true);

    void find(string eng);
    bool update(string eng, string newViet);
    bool remove(string eng);

    void display();                 // Hiển thị tất cả
    void displayGroup(char group);  // Hiển thị theo nhóm ký tự 

    // Hai hàm xử lý file
    void loadFromFile(string filename);
    void saveToFile(string filename);
    bool isExist(string eng);
};