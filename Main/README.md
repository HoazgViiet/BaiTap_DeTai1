# 📚 Hệ thống Quản lý Thư Viện

Đây là ứng dụng dòng lệnh (CLI) bằng C++ hỗ trợ thư viện quản lý kho sách, thông tin độc giả và toàn bộ quy trình mượn/trả sách một cách tối ưu.

---

## 🛠 Cấu trúc dữ liệu sử dụng

| Cấu trúc | Vai trò | Lý do áp dụng |
| :--- | :--- | :--- |
| **BST (Cây nhị phân tìm kiếm)** | Quản lý kho sách | Tìm kiếm, thêm, xóa theo mã sách đạt hiệu suất cao với độ phức tạp $O(\log n)$. |
| **Queue (Hàng đợi)** | Danh sách chờ mượn sách | Đảm bảo tính công bằng theo nguyên tắc "Vào trước - Ra trước" (FIFO) khi sách hết. |
| **Stack (Ngăn xếp)** | Lịch sử thao tác mượn/trả | Hỗ trợ tính năng Hoàn tác (Undo) nhanh chóng theo nguyên tắc "Vào sau - Ra trước" (LIFO). |
| **Linked List (Danh sách liên kết)** | Quản lý danh sách độc giả | Cấp phát bộ nhớ động linh hoạt, thêm/xóa nhanh chóng mà không cần dịch chuyển dữ liệu. |

---

## 🚀 Hướng dẫn cài đặt và chạy

Mở Terminal/Command Prompt tại thư mục gốc của dự án và chạy lệnh biên dịch sau:

```bash
g++ -std=c++17 src/main.cpp src/functions.cpp -o app && ./app
