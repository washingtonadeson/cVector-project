# cVector-project
Một lớp vector đa chiều bằng C++ (A C++ multidimensional vector class)

Vector phải được xác định trước kích thuớc.
Vector nếu chưa được xác định trước kích thước và data của vector
    => chương trình sẽ tự động VÔ HIỆU HÓA VECTOR (không thể dùng được, EMPTY VECTOR)

Vector có kích thuớc hợp lệ nhưng chưa xác định trước data của vector
    => KHÔNG THỂ truy xuất dữ liệu phần tử của data
    => Chương trình cho phép nhập data nhưng không thể xuất data cho đến khi đã được nhập
    Nếu xuất data chưa xác định
        => Chương trình báo lỗi chưa nhập
    
Vector có kích thước không hợp lệ (kể cả khi chưa xác định kích thước)
    => chương trình sẽ tự động HỦY vector bằng cách reset về dimension = 0, data = nullptr
        => Vector bị VÔ HIỆU HÓA (không thể dùng được, EMPTY VECTOR)
            => KHÔNG THỂ truy xuất dữ liệu phần tử của data
            => KHÔNG THỂ nhập data
            => Xuất data vector dưới dạng EMPTY

# Dự án này hiện thực một lớp CVector trong ngôn ngữ C++ để mô hình hóa các vector toán học trong không gian đa chiều.
Lớp hỗ trợ các phép toán cơ bản như cộng, trừ, tích vô hướng (dot product), chuẩn hóa (norm), truy cập phần tử, và nhập/xuất dữ liệu.

# Tính năng
Hỗ trợ vector có kích thước động (số chiều tùy ý)

Kiểm tra giới hạn chỉ số an toàn, có thông báo lỗi rõ ràng

Thực hiện phép cộng và trừ giữa hai vector

Tính tích vô hướng và độ dài (chuẩn) của vector

Hỗ trợ sao chép sâu và phép gán

Hỗ trợ toán tử nhập/xuất dòng (<<, >>)
