#include "Application.h"
#include <iostream>
#include <cstdlib> 

using namespace std;

Application::Application() : DATA_FILE("data.txt") {}

void Application::showMenu() {
    cout << "\n--- HE THONG TU DIEN TIN HOC ---" << endl;
    cout << "1. Them tu moi (Add)" << endl;
    cout << "2. Tra cuu (Find)" << endl;
    cout << "3. Sua nghia (Edit)" << endl;
    cout << "4. Xoa tu (Delete)" << endl;
    cout << "5. Xem tat ca (Display)" << endl;
    cout << "0. Luu & Thoat" << endl;
    cout << "Lua chon: ";
}

void Application::run() {
    myDict.loadFromFile(DATA_FILE);

    int choice;
    string eng, viet;

    do {
        showMenu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            choice = -1;
        }
        cin.ignore();

        switch (choice) {
        case 1:
            cout << "Nhap Tieng Anh: "; getline(cin, eng);
            cout << "Nhap Tieng Viet: "; getline(cin, viet);
            myDict.add(eng, viet, true);
            break;
        case 2:
            cout << "Nhap tu can tim: "; getline(cin, eng);
            myDict.find(eng);
            break;
        case 3:
            cout << "Nhap tu can sua: ";
            getline(cin, eng);
            if (myDict.isExist(eng)) {
                // Nếu có từ này thì mới hỏi nghĩa mới
                cout << "Nhap nghia moi: ";
                getline(cin, viet);
                myDict.update(eng, viet);
            }
            else {
                // Nếu không có thì báo lỗi ngay, không hỏi nghĩa nữa
                cout << "(!) Loi: Tu '" << eng << "' khong co trong tu dien!" << endl;
            }
            break;
        case 4:
            cout << "Nhap tu can xoa: "; getline(cin, eng);
            myDict.remove(eng);
            break;

        case 5:
            int subChoice;
            cout << "\n   >>> TUY CHON HIEN THI <<<" << endl;
            cout << "   1. Hien thi TAT CA (All)" << endl;
            cout << "   2. Hien thi theo NHOM (Group)" << endl;
            cout << "   Chon: ";
            cin >> subChoice;
            cin.ignore();

            if (subChoice == 1) {
                myDict.display();
            }
            else if (subChoice == 2) {
                char charGroup;
                cout << "   Nhap chu cai muon xem (VD: A, B...): ";
                cin >> charGroup;
                cin.ignore();
                myDict.displayGroup(charGroup);
            }
            else {
                cout << "   (!) Lua chon khong hop le!" << endl;
            }
            break;

        case 0:
            myDict.saveToFile(DATA_FILE);
            cout << "Tam biet!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);
}