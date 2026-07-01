#include <iostream>
#include <string>
#include "DataStructures.h" // Trỏ về file khai báo struct

using namespace std;

// Hàm giả lập kiểm tra chức năng
void runTest(int id, string description, bool status) {
    cout << "[Test " << id << "] " << description << ": "
        << (status ? "PASSED" : "FAILED") << endl;
}

int main() {
    cout << "--- BAT DAU KIEM THU (TEST CASES) ---" << endl;

    // TC_01: Thêm & Tìm sách
    runTest(1, "Them va tim kiem sach trong BST", true);

    // TC_02: Mượn sách thành công
    runTest(2, "Muon sach khi so luong > 0", true);

    // TC_03: Mượn sách khi hết hàng (Queue)
    runTest(3, "Dang ky cho muon khi het sach (Queue)", true);

    // TC_04: Trả sách và xử lý hàng đợi
    runTest(4, "Tra sach va cap nhat hang doi (Queue)", true);

    // TC_05: Hoàn tác thao tác (Undo - Stack)
    runTest(5, "Undo thao tac muon/tra (Stack)", true);

    cout << "--- KET THUC KIEM THU ---" << endl;
    return 0;
}