# 📚 Hệ thống Quản lý Thư Viện

Ứng dụng CLI quản lý kho sách, độc giả và quy trình mượn/trả sách, được tối ưu hóa bằng các cấu trúc dữ liệu kinh điển (C++17).

> **Lệnh biên dịch & chạy:** `g++ -std=c++17 main.cpp LibraryManager.cpp -o app && ./app`
> *(Lưu ý: Trên Windows, đổi `./app` thành `app.exe`)*

---

### 🛠 1. Cấu trúc dữ liệu sử dụng

| Cấu trúc dữ liệu | Kỹ thuật | Vai trò và Ưu điểm |
| :--- | :--- | :--- |
| **BST** | Cây nhị phân tìm kiếm | Quản lý kho sách. Giúp thêm, xóa, sửa và tìm kiếm sách (theo mã) với tốc độ cao **O(log n)**. |
| **Queue** | Hàng đợi (FIFO) | Quản lý hàng đợi. Đảm bảo công bằng: ai đăng ký chờ sách trước sẽ được mượn trước. |
| **Stack** | Ngăn xếp (LIFO) | Quản lý lịch sử thao tác. Hỗ trợ tính năng **Undo (Hoàn tác)** lại hành động mượn/trả vừa thực hiện. |
| **Linked List** | Danh sách liên kết | Quản lý danh sách độc giả. Cấp phát bộ nhớ động linh hoạt, dễ dàng thêm/xóa mà không gây lãng phí. |

Hệ thống của bạn sử dụng 4 cấu trúc dữ liệu, mỗi cấu trúc giải quyết một bài toán cụ thể rất hợp lý:  
- Danh sách liên kết đơn (Linked List) - struct Reader:  
  *Vai trò: Quản lý danh sách độc giả.
  *Ý tưởng: Vì lượng độc giả đăng ký thẻ thư viện có thể tăng lên liên tục, việc dùng Linked List giúp hệ thống cấp phát bộ nhớ động linh hoạt (new Reader), không bị giới hạn dung lượng như dùng mảng cố định.  
- Cây nhị phân tìm kiếm (BST) - struct Book:
  *Vai trò: Quản lý kho sách.
  *Ý tưởng: Thư viện có rất nhiều sách. Việc tìm một cuốn sách theo mã (ID) trên mảng thông thường sẽ tốn thời gian $O(n)$. Việc tổ chức sách thành BST giúp phân nhánh dữ liệu (nhỏ sang trái, lớn sang phải), giảm thời gian tìm kiếm, thêm, xóa xuống mức trung bình là $O(\log n)$.  
- Hàng đợi (Queue) - queue<string> waitlist (Nằm trong Book):
  *Vai trò: Quản lý danh sách người chờ mượn khi sách đã hết.
  *Ý tưởng: Hoạt động theo cơ chế FIFO (First In - First Out). Ai đến xếp hàng trước sẽ được ưu tiên nhận sách trước khi có người trả. Việc đặt hàng đợi này nằm ngay bên trong mỗi cuốn sách là một thiết kế rất tối ưu, giúp quản lý hàng chờ cục bộ cho từng đầu sách riêng biệt
- Ngăn xếp (Stack) - stack<Action> history:
  *Vai trò: Lưu lịch sử mượn/trả để hỗ trợ tính năng Hoàn tác (Undo).
  *Ý tưởng: Hoạt động theo cơ chế LIFO (Last In - First Out). Thao tác nào vừa làm gần nhất sẽ nằm trên đỉnh Stack, khi gọi lệnh Undo, hệ thống chỉ cần bốc phần tử trên đỉnh này ra để đảo ngược trạng thái (VD: đang mượn thì thành chưa mượn).

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
