# cVector-project
Một lớp vector đa chiều bằng C++ (A C++ multidimensional vector class)



__Vector phải được xác định trước kích thuớc.__



1. Vector nếu chưa được xác định trước kích thước và data của vector

   _Chương trình sẽ tự động VÔ HIỆU HÓA VECTOR (không thể dùng được, EMPTY VECTOR)_

   

3. Vector có kích thuớc hợp lệ nhưng chưa xác định trước data của vector

   _KHÔNG THỂ truy xuất dữ liệu phần tử của vector_
  
   _Chương trình cho phép nhập vector (data) nhưng không thể xuất vector cho đến khi đã được nhập_

   - Nếu xuất vector chưa xác định
  
      _Chương trình sẽ báo lỗi chưa nhập_

     
    
3. Vector có kích thước không hợp lệ (kể cả khi chưa xác định kích thước)

   _Chương trình sẽ tự động HỦY vector bằng cách reset về dimension = 0, data = nullptr. Hậu quả vector bị VÔ HIỆU HÓA (không thể dùng được, EMPTY VECTOR)_

   _KHÔNG THỂ truy xuất dữ liệu phần tử của vector_

   _KHÔNG THỂ nhập vector (data)_

   _Xuất vector dưới dạng EMPTY_

   

# Dự án này hiện thực một lớp CVector trong ngôn ngữ C++ để mô hình hóa các vector toán học trong không gian đa chiều.
Lớp hỗ trợ các phép toán cơ bản như cộng, trừ, tích vô hướng (dot product), chuẩn hóa (norm), truy cập phần tử, và nhập/xuất dữ liệu.

# Tính năng
- Cộng và trừ vector

- Tích vô hướng (dot product)

- Tính chuẩn (độ dài) của vector

- Truy cập phần tử bằng toán tử []

- So sánh hai vector bằng ==

- Nhập/Xuất dữ liệu bằng toán tử >> và <<



# Dự án này bao gồm xử lý lỗi an toàn, cụ thể với các trường hợp:

- Sai lệch về số chiều giữa các vector

- Dữ liệu chưa được khởi tạo

- Truy cập chỉ số không hợp lệ, quy trình tự báo lỗi được xử lý rõ ràng, hợp lý và an toàn ở mức cơ bản.

   _Với mục đích học tập, đây là một thiết kế chặt chẽ, có kiểm tra lỗi cẩn thận và rất dễ hiểu._

- Con trỏ null (con trỏ rỗng)



# Tại sao mình thực hiện dự án này?
__Tôi viết chương trình này để thể hiện:__

- Kiến thức lập trình hướng đối tượng (OOP) vững chắc trong C++

- Phong cách lập trình phòng thủ (defensive programming)

- Quản lý bộ nhớ thủ công

- Nắm vững việc nạp chồng toán tử trong C++
