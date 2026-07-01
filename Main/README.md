## Hệ thống Quản lý Thư Viện
Đây là ứng dụng dòng lệnh (CLI) bằng C++ hỗ trợ thư viện quản lý kho sách, thông tin độc giả và toàn bộ quy trình mượn/trả sách một cách tối ưu.

## Cấu trúc dữ liệu sử dụng
- **BST (Cây nhị phân tìm kiếm):** Dùng để lưu trữ và quản lý kho sách vì khả năng tìm kiếm, thêm, xóa theo mã sách đạt hiệu suất cao với độ phức tạp $O(\log n)$.
- **Queue (Hàng đợi):** Dùng để lưu danh sách độc giả chờ mượn khi một cuốn sách đã hết vì nó đảm bảo tính công bằng theo nguyên tắc "Vào trước - Ra trước" (FIFO).
- **Stack (Ngăn xếp):** Dùng để lưu lịch sử các thao tác mượn/trả vì hỗ trợ rất tốt cho chức năng Hoàn tác (Undo) theo nguyên tắc "Vào sau - Ra trước" (LIFO).
- **Linked List (Danh sách liên kết):** Dùng để quản lý danh sách độc giả vì tính linh hoạt khi cấp phát bộ nhớ động, thêm/xóa độc giả nhanh chóng mà không cần dịch chuyển dữ liệu như mảng.

## Compile và chạy
Mở Terminal/Command Prompt tại thư mục gốc của dự án và chạy lệnh sau:
`g++ -std=c++17 src/main.cpp src/functions.cpp -o app && ./app`

## Chức năng
1. Thêm, xóa, sửa thông tin sách.
2. Tìm kiếm sách theo mã hoặc tên.
3. Mượn sách (tự động chuyển vào Queue nếu sách đang được mượn hết).
4. Trả sách (cập nhật trạng thái và tự động thông báo cho người chờ tiếp theo).
5. Xem lịch sử mượn/trả và Undo thao tác cuối cùng.
6. Thống kê sách được mượn nhiều nhất và độc giả tích cực nhất.
7. Lưu và đọc dữ liệu từ file `.txt`.

## Test cases
1. **Thêm và tìm kiếm sách:** Thêm 3 cuốn sách vào hệ thống, sau đó tìm cuốn có mã "B002". Kết quả mong đợi: Hệ thống hiển thị đúng thông tin sách "B002".
2. **Mượn sách thành công:** Độc giả mượn sách khi số lượng tồn kho lớn hơn 0. Kết quả mong đợi: Số lượng sách giảm đi 1 và ghi nhận lịch sử.
3. **Mượn sách khi hết hàng:** Độc giả mượn sách khi số lượng tồn kho bằng 0. Kết quả mong đợi: Độc giả được tự động đưa vào danh sách chờ (Queue) của cuốn sách đó.
4. **Trả sách và xử lý hàng đợi:** Độc giả trả sách đang có người xếp hàng chờ. Kết quả mong đợi: Hệ thống lấy người đầu tiên trong Queue ra và cấp sách cho người đó.
5. **Undo thao tác (Hoàn tác):** Thực hiện mượn sách, sau đó chọn chức năng Undo. Kết quả mong đợi: Trạng thái sách và lịch sử quay trở lại chính xác như trước khi mượn.

## Cấu trúc file
src/
  main.cpp       - Menu giao diện console và điều khiển luồng chương trình
  structures.h   - Khai báo các struct (Book, Reader) và nguyên mẫu hàm
  functions.cpp  - Cài đặt chi tiết logic của các cấu trúc dữ liệu và chức năng