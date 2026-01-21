#include "Dictionary.h"
#include <iomanip>
#include <iostream>

int Dictionary::hashFunction(char keyChar) {
    if (keyChar >= 'a' && keyChar <= 'z') return keyChar - 'a';
    return -1;
}

void Dictionary::clear() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = table[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        table[i] = NULL;
    }
}
Dictionary::Dictionary() {
    for (int i = 0; i < TABLE_SIZE; i++) table[i] = NULL;
}

Dictionary::~Dictionary() {
    clear();
}

void Dictionary::loadFromFile(string filename) {
    ifstream inFile(filename.c_str());
    if (!inFile) {
        return; // Chưa có file thì bỏ qua
    }

    string line;
    int count = 0;
    while (getline(inFile, line)) {
        size_t delimiterPos = line.find(';');
        if (delimiterPos != string::npos) {
            string eng = line.substr(0, delimiterPos);
            string viet = line.substr(delimiterPos + 1);
            this->add(eng, viet, false);
            count++;
        }
    }
    inFile.close();
    if (count > 0) cout << "(i) Da tai " << count << " tu vung tu file." << endl;
}

void Dictionary::saveToFile(string filename) {
    ofstream outFile(filename.c_str());
    if (!outFile) {
        cout << "(!) Loi: Khong the ghi file!" << endl;
        return;
    }

    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = table[i];
        while (temp != NULL) {
            outFile << temp->data.getEnglish() << ";" << temp->data.getVietnamese() << endl;
            temp = temp->next;
        }
    }
    outFile.close();
    cout << "(i) Da luu du lieu vao file '" << filename << "'." << endl;
}

void Dictionary::add(string eng, string viet, bool verbose) {
    Word newWord(eng, viet);
    char key = newWord.getFirstChar();
    int index = hashFunction(key);

    if (index == -1) {
        if (verbose) cout << "(!) Loi: Tu phai bat dau bang chu cai tieng Anh." << endl;
        return;
    }

    Node* current = table[index];
    while (current != NULL) {
        if (current->data.equals(eng)) {
            if (verbose) cout << "(!) Tu '" << eng << "' da ton tai." << endl;
            return;
        }
        current = current->next;
    }

    Node* newNode = new Node(newWord);
    newNode->next = table[index];
    table[index] = newNode;

    if (verbose) cout << "(+) Da them: " << eng << endl;
}

void Dictionary::find(string eng) {
    if (eng.empty()) return;
    int index = hashFunction(tolower(eng[0]));

    if (index == -1) return;

    Node* current = table[index];
    while (current != NULL) {
        if (current->data.equals(eng)) {
            cout << "\n--- KET QUA ---" << endl;
            current->data.print();
            return;
        }
        current = current->next;
    }
    cout << "(!) Khong tim thay tu: " << eng << endl;
}

bool Dictionary::update(string eng, string newViet) {
    if (eng.empty()) return false;
    int index = hashFunction(tolower(eng[0]));
    if (index == -1) return false;

    Node* current = table[index];
    while (current != NULL) {
        if (current->data.equals(eng)) {
            current->data.setVietnamese(newViet);
            cout << "(i) Da cap nhat nghia moi cho '" << eng << "'." << endl;
            return true;
        }
        current = current->next;
    }
    cout << "(!) Khong tim thay tu can sua." << endl;
    return false;
}

bool Dictionary::remove(string eng) {
    if (eng.empty()) return false;
    int index = hashFunction(tolower(eng[0]));
    if (index == -1) return false;

    Node* current = table[index];
    Node* prev = NULL;

    while (current != NULL) {
        if (current->data.equals(eng)) {
            if (prev == NULL) {
                table[index] = current->next;
            }
            else {
                prev->next = current->next;
            }
            delete current;
            cout << "(-) Da xoa tu: " << eng << endl;
            return true;
        }
        prev = current;
        current = current->next;
    }
    cout << "(!) Khong tim thay tu can xoa." << endl;
    return false;
}

void Dictionary::display() {
    cout << "\n====== TU DIEN HIEN TAI ======" << endl;
    bool empty = true;
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] != NULL) {
            empty = false;
            cout << "Nhom [" << (char)('A' + i) << "]:" << endl;
            Node* temp = table[i];
            while (temp != NULL) {
                temp->data.print();
                temp = temp->next;
            }
        }
    }
    if (empty) cout << "(Tu dien trong)" << endl;
    cout << "==============================" << endl;
}

//HIỂN THỊ THEO NHÓM
void Dictionary::displayGroup(char group) {
    int index = hashFunction(tolower(group));

    if (index == -1) {
        cout << "(!) Ky tu khong hop le. Vui long nhap A-Z." << endl;
        return;
    }

    cout << "\n--- DANH SACH NHOM KY TU [" << (char)toupper(group) << "] ---" << endl;
    Node* temp = table[index];

    if (temp == NULL) {
        cout << "(Chua co tu nao trong nhom nay)" << endl;
    }
    else {
        while (temp != NULL) {
            temp->data.print();
            temp = temp->next;
        }
    }
    cout << "----------------------------------" << endl;
}
bool Dictionary::isExist(string eng) {
    if (eng.empty()) return false;
    int index = hashFunction(tolower(eng[0]));

    if (index == -1) return false;

    Node* current = table[index];
    while (current != NULL) {
        if (current->data.equals(eng)) {
            return true; // Tìm thấy!
        }
        current = current->next;
    }
    return false; // Duyệt hết mà không thấy
}