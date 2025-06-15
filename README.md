# cVector-project
Một lớp vector đa chiều bằng C++ (A C++ multidimensional vector class)

Vector phải được xác định trước kích thuớc. Nếu chưa xác định trước khi run, chương trình sẽ mặc định là vector RỖNG => VÔ HIỆU HÓA VECTOR

Vector có kích thuớc hợp lệ nhưng chưa xác định trước data
=> KHÔNG THỂ truy xuất dữ liệu, vẫn có thể nhập data nhưng không thể xuất data cho đến khi đã nhập
    
Vector có kích thước không hợp lệ, chương trinh sẽ tự động hủy vector (vector RỖNG, dimension = 0, data = nullptr)
=> KHÔNG THỂ truy xuất dữ liệu, không thể nhập data, và không thể xuất data kể cả khi đã nhập (vector đã bị vô hiệu hóa)

# Dự án này hiện thực một lớp CVector trong ngôn ngữ C++ để mô hình hóa các vector toán học trong không gian nhiều chiều. Lớp hỗ trợ các phép toán cơ bản như cộng, trừ, tích vô hướng (dot product), chuẩn hóa (norm), truy cập phần tử, và nhập/xuất dữ liệu.

# Tính năng
Hỗ trợ vector có kích thước động (số chiều tùy ý)

Kiểm tra giới hạn chỉ số an toàn, có thông báo lỗi rõ ràng

Thực hiện phép cộng và trừ giữa hai vector

Tính tích vô hướng và độ dài (chuẩn) của vector

Hỗ trợ sao chép sâu và phép gán

Hỗ trợ toán tử nhập/xuất dòng (<<, >>)
