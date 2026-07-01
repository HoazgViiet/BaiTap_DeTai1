#include <iostream>
#include <string>
#include "LibraryManager.h"

using namespace std;

void inMenu() {
    cout << "\n=========== HE THONG QUAN LY THU VIEN ===========" << endl;
    cout << "1. Them Sach (BST)" << endl;
    cout << "2. Them Doc gia (Linked List)" << endl;
    cout << "3. Muon Sach (tu dong vao Queue neu het)" << endl;
    cout << "4. Tra Sach (chuyen cho nguoi trong Queue)" << endl;
    cout << "5. Undo thao tac cuoi (Stack)" << endl;
    cout << "6. Thong ke" << endl;
    cout << "0. Thoat" << endl;
    cout << "Chon chuc nang: ";
}

int main() {
    LibraryManager lib;

    // Dummy Data để bạn test nhanh
    lib.insertBook("B01", "Cau Truc Du Lieu");
    lib.insertBook("B02", "Giai Thuat C++");
    lib.addReader("R01", "Nguyen Van A");
    lib.addReader("R02", "Tran Thi B");
    lib.addReader("R03", "Le Van C");

    int choice;
    do {
        inMenu();
        cin >> choice;
        cin.ignore();

        string bId, rId, name, title;

        switch (choice) {
        case 1:
            cout << "Nhap Ma Sach: "; getline(cin, bId);
            cout << "Nhap Ten Sach: "; getline(cin, title);
            lib.insertBook(bId, title);
            break;
        case 2:
            cout << "Nhap Ma Doc Gia: "; getline(cin, rId);
            cout << "Nhap Ten Doc Gia: "; getline(cin, name);
            lib.addReader(rId, name);
            break;
        case 3:
            cout << "Ma Doc Gia muon: "; getline(cin, rId);
            cout << "Ma Sach muon: "; getline(cin, bId);
            lib.borrowBook(rId, bId);
            break;
        case 4:
            cout << "Ma Doc Gia tra: "; getline(cin, rId);
            cout << "Ma Sach tra: "; getline(cin, bId);
            lib.returnBook(rId, bId);
            break;
        case 5:
            lib.undoLastAction();
            break;
        case 6:
            lib.statMostBorrowedBook();
            lib.statMostActiveReader();
            break;
        case 0:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Loi! Chon lai.\n";
        }
    } while (choice != 0);

    return 0;
}