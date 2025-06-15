#include <bits/stdc++.h>
#include "cVector.h"

int main() {
    // Vector có số chiều hợp lệ nhưng chưa có dữ liệu (data = nullptr)
    // => Không thể xuất, nhưng có thể nhập dữ liệu (sau khi nhập mới có thể dùng được)
    cVector v1(5), v2(5);
  
    // Vector có số chiều nhỏ hơn hoặc bằng 0 => bị vô hiệu hóa (dimension = 0, data = nullptr)
    // => Không thể nhập, hay thực hiện phép toán, nhưng có thể xuất ra EMPTY (RỖNG do vector có số chiều không hợp lệ hoặc chưa nhập)
    cVector result;
  
    // Vector khác chiều v2 để thử phép cộng không hợp lệ
    cVector v6(2);
  
    // Xuất v1: chưa có data nên sẽ không hiển thị gì (hoặc cảnh báo)
    std::cout << "v1" << v1;
  
    // Nhập dữ liệu cho v1, v2 (có tính năng phát hiện lỗi)
    std::cin >> v1 >> v2;
    std::cout << "v1" << v1;
    std::cout << "v2" << v2;
    
    // Truy xuất dữ liệu phần tử (có tính năng phát hiện lỗi)
    std::cout << "v1[3] = " << v1[3] << '\n';

    // Tính độ dài vector (có tính năng phát hiện lỗi)
    std::cout << "norm(v2) = " << v2.norm() << '\n';
  
    // Nhập dữ liệu cho v6 (có tính năng phát hiện lỗi)
    std::cin >> v6;
    std::cout << "v6" << v6;
  
    // Xuất result: chưa khởi tạo dimension => sẽ là vector rỗng
    std::cout << "result" << result;
  
    // Cộng 2 vector cùng chiều (v1 + v2) => không báo lỗi
    result = v1 + v2;
    std::cout << "result" << result;
  
    // Cộng 2 vector khác chiều (v6 + v2) => sẽ báo lỗi và thoát (có tính năng phát hiện lỗi)
    result = v6 + v2;
    std::cout << "result" << result;
  
    // Nếu trên không thoát, thực hiện thêm phép toán phức hợp (có tính năng phát hiện lỗi)
    cVector result1 = v1 - v2 + result;
    std::cout << "result1 = v1 - v2 + result" << result1;
  
    // Tính tích vô hướng (có tính năng phát hiện lỗi)
    std::cout << "dot(result, result1) = " << result.dotProduct(result1) << '\n';
  
    return 0;
}
