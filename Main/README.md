# 📚 Hệ thống Quản lý Thư Viện

Ứng dụng CLI quản lý kho sách, độc giả và quy trình mượn/trả sách, được tối ưu hóa bằng các cấu trúc dữ liệu kinh điển (C++17).

> **Lệnh biên dịch & chạy:** `g++ -std=c++17 main.cpp LibraryManager.cpp -o app && ./app`
> *(Lưu ý: Trên Windows, đổi `./app` thành `app.exe`)*

---

### 🛠 1. Cấu trúc dữ liệu sử dụng

* **BST ($O(\log n)$):** Quản lý kho sách. Giúp thêm, xóa, sửa và tìm kiếm sách (theo mã) tốc độ cao.
* **Queue (FIFO):** Quản lý hàng đợi. Đảm bảo công bằng: ai đăng ký chờ sách trước sẽ được mượn trước.
* **Stack (LIFO):** Quản lý lịch sử thao tác. Hỗ trợ tính năng **Undo (Hoàn tác)** lại hành động mượn/trả vừa thực hiện.
* **Linked List:** Quản lý danh sách độc giả. Cấp phát bộ nhớ động linh hoạt, dễ dàng thêm/xóa mà không gây lãng phí.

---

### 🚀 2. Chức năng chính

* **Quản lý Sách:** Thêm, xóa, sửa và tìm kiếm (theo mã hoặc tên).
* **Mượn/Trả thông minh:** Tự động xếp khách vào Queue nếu sách hết; tự động xuất Queue cấp sách khi có người trả.
* **Hoàn tác:** Xem lịch sử và Undo thao tác cuối cùng.
* **Tiện ích:** Thống kê (Sách hot, Độc giả tích cực) & Lưu/Đọc toàn bộ dữ liệu qua file `.txt`.

---

### 🧪 3. Kịch bản kiểm thử (Test Cases)

1. **Thêm & Tìm kiếm:** Nhập sách mới vào hệ thống $\rightarrow$ Tìm theo mã $\rightarrow$ Hiển thị đúng thông tin sách.
2. **Mượn sách hợp lệ:** Mượn sách khi tồn kho > 0 $\rightarrow$ Số lượng giảm 1, ghi nhận lịch sử vào Stack.
3. **Vào hàng đợi (Queue):** Mượn sách khi tồn kho = 0 $\rightarrow$ Độc giả được tự động đẩy vào danh sách chờ.
4. **Trả sách tự động:** Trả cuốn sách đang có người đợi $\rightarrow$ Hệ thống lấy người đầu Queue ra và tự động cho mượn.
5. **Hoàn tác (Undo):** Chọn chức năng Undo $\rightarrow$ Hủy thao tác mượn/trả cuối cùng, khôi phục lại trạng thái cũ.

---

### 📂 4. Cấu trúc mã nguồn

```text
Code/
├── main.cpp           # Menu Console và luồng điều khiển chính
├── DataStructures.h   # Khai báo các cấu trúc dữ liệu (Book, Reader, Action)
├── LibraryManager.h   # Khai báo lớp quản lý (LibraryManager) và nguyên mẫu hàm
└── LibraryManager.cpp # Cài đặt chi tiết logic giải thuật (BST, Queue, Stack, LL)
