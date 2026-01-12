#include <iostream>
#include <string>
#include "hash.h"
#include "linkedlist.h"
#include "operations.h"
#include "display.h"
using namespace std;
void menu() {
    cout << "\n====== TU DIEN ANH - VIET ======";
    cout << "\n1. Them tu";
    cout << "\n2. Tra cuu tu";
    cout << "\n3. Hien thi danh sach tu";
    cout << "\n4. Sua tu";
    cout << "\n5. Xoa tu";
    cout << "\n0. Thoat";
    cout << "\n===============================";
}
void displayMenu() {
    cout << "\n--- HINH THUC HIEN THI ---";
    cout << "\n1. Hien thi tat ca";
    cout << "\n2. Hien thi theo nhom (A - Z)";
    cout << "\n-------------------------";
}
int main() {
    initHashTable();
    int choice;
    string eng, vie;
    do {
        menu();
        cout << "\nNhap lua chon cua ban: ";
        cin >> choice;
        cin.ignore();
        switch (choice) {
        case 1:
            cout << "\nNhap tu tieng Anh: ";
            getline(cin, eng);
            cout << "Nhap nghia tieng Viet: ";
            getline(cin, vie);
            addWord(eng, vie);
            break;
        case 2:
            cout << "\nNhap tu tieng Anh can tra cuu: ";
            getline(cin, eng);
            if (!searchWord(eng)) {
                cout << "Khong tim thay tu trong tu dien.";
            }
            else {
                cout << "Nghia cua tu " << searchWord(eng)->data.vietnamese;
            }
            break;
        case 3: {
            int sub;
            displayMenu();
            cout << "\nNhap lua chon cua ban: ";
            cin >> sub;
            cin.ignore();
            if (sub == 1)
                displayAll();
            else if (sub == 2) {
                char c;
                cout << "Nhap chu cai (A-Z): ";
                cin >> c;
                cin.ignore();
                displayByGroup(c);
            }
            else
                cout << "Lua chon khong hop le!\n";
            break;
        }
        case 4:
            cout << "\nNhap tu tieng Anh can sua: ";
            getline(cin, eng);
            cout << "Nhap nghia tieng Viet moi: ";
            getline(cin, vie);
            updateWord(eng, vie);
            break;
        case 5:
            cout << "\nNhap tu tieng Anh can xoa: ";
            getline(cin, eng);
            deleteWord(eng);
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Lua chon khong hop le! Vui long thu lai.\n";
            break;
        }
    } while (choice != 0);
    return 0;
}
