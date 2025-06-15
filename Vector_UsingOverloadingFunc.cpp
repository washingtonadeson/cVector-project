// 6. Định nghĩa lớp CVector biểu diễn khái niệm vector trong không gian có số chiều bất 
// kỳ với các hàm thành phần và các phép toán cần thiết.

#include <bits/stdc++.h>

class cVector {
private:
    int dimension;
    float* data;

public:
    cVector(int = 0, float* = nullptr); // Vector được tạo mặc định 0 chiều, dữ liệu rỗng do chưa được xác định.
    ~cVector();
    cVector(const cVector&);
    cVector& operator=(const cVector&);
    cVector operator+(const cVector&) const;
    cVector operator-(const cVector&) const;
    bool operator==(const cVector&) const;
    float dotProduct(const cVector&) const;
    float norm() const;
    friend std::istream& operator>>(std::istream&, cVector&);
    friend std::ostream& operator<<(std::ostream&, const cVector&);
    float& operator[](int);
    float operator[](int) const;
};

cVector::cVector(int d, float* arr) {
    this->dimension = d;

    if(arr) {
        if(d <= 0) {
            std::cout << "\nCOMPILER ERROR : Vector khong hop le. Huy vector\n";
            this->dimension = 0;  // đã reset, làm flag hủy
            this->data = nullptr;   // đã reset, làm flag hủy

            return;
        }

        else {
            this->data = new float[d];

            memset(this->data, 0, d * sizeof(float));
            memcpy(this->data, arr, d * sizeof(float));
        }
    }

    else {
        this->data = nullptr;
    }
}

cVector::~cVector() {
    delete[] this->data;
}

cVector::cVector(const cVector& vec) {
    this->dimension = vec.dimension;
    this->data = new float[this->dimension];
    memcpy(this->data, vec.data, this->dimension * sizeof(float));
}

cVector& cVector::operator=(const cVector& vec) {
    if(this != &vec) {
        this->dimension = vec.dimension;
        delete[] this->data;
        this->data = new float[this->dimension];
        memcpy(this->data, vec.data, this->dimension * sizeof(float));
    }

    return *this;
}

cVector cVector::operator+(const cVector& vec) const {
    if(this->data && vec.data) {
        if(this->dimension != vec.dimension) {
            std::cerr << "Loi!! Khong the cong hai vector khac chieu\n";
            exit(1);
        }

        float* sumVec = new float[this->dimension];

        for(int i = 0 ; i < this->dimension; i++) {
            sumVec[i] = this->data[i] + vec.data[i];
        }

        return cVector(this->dimension, sumVec);
    }

    std::cerr << "\nCOMPILER ERROR : Khong the tinh duoc do co it nhat 1 vector chua nhap\n";
    exit(1);
}

cVector cVector::operator-(const cVector& vec) const {
    if(this->data && vec.data) {
        if(this->dimension != vec.dimension) {
            std::cerr << "Loi!! Khong the tru hai vector khac chieu\n";
            exit(1);
        }

        float* subtrVec = new float[this->dimension];

        for(int i = 0 ; i < this->dimension; i++) {
            subtrVec[i] = this->data[i] - vec.data[i];
        }

        return cVector(this->dimension, subtrVec);
    }

    std::cerr << "\nCOMPILER ERROR : Khong the tinh duoc do co it nhat 1 vector chua nhap\n";
    exit(1);
}

bool cVector::operator==(const cVector& vec) const {
    if(this->data && vec.data)
        if(this->dimension == vec.dimension) {
            for(int i = 0; i < this->dimension; i++) {
                if(this->data[i] != vec.data[i]) return false;
            }
            return true;
        }
        else return false;
    
    std::cerr << "\nCOMPILER ERROR : Khong the tinh duoc do co it nhat 1 vector chua nhap\n";
    exit(1);
}

float cVector::dotProduct(const cVector& vec) const {
    if(this->data && vec.data) {
        if(this->dimension != vec.dimension) {
            std::cerr << "Loi!! Khong the tinh tich vo huong hai vector khac chieu\n";
            exit(1);
        }

        float result = 0.0;

        for(int i = 0; i < this->dimension; i++) {
            result += this->data[i] * vec.data[i];
        }

        return result;
    }

    std::cerr << "\nCOMPILER ERROR : Khong the tinh duoc do co it nhat 1 vector chua nhap\n";
    exit(1);
}

float cVector::norm() const {
    if(this->data) {
        float result = 0.0;

        for(int i = 0; i < this->dimension; i++) {
            result += this->data[i] * this->data[i];
        }

        return sqrt(result);
    }

    std::cerr << "\nCOMPILER ERROR : Khong the tinh duoc do co it nhat 1 vector chua nhap\n";
    exit(1);
}

std::istream& operator>>(std::istream& is, cVector& vec) {
    if(vec.dimension == 0) {
        std::cerr << "\nCOMPILER ERROR : Dimension chua xac dinh hoac vector da bi huy!! Huy nhap data\n";
    }

    else {
        if(vec.data) delete[] vec.data;

        vec.data = new float[vec.dimension];

        std::cout << "Nhap data: ";
        for(int i = 0; i < vec.dimension; i++) {
            is >> vec.data[i];
        }
    }

    return is;
}

std::ostream& operator<<(std::ostream& os, const cVector& vec) {
    if(vec.dimension == 0) os << " = Empty\n";
    else if(vec.data != nullptr){
        os << " = (";
        for(int i = 0; i < vec.dimension - 1; i++)
            os << vec.data[i] << ", ";
        os << vec.data[vec.dimension - 1] << ")\n";
    }
    else {
        std::cerr << "\nCOMPILER ERROR : Chua nhap data cua vector!! Huy xuat vector\n";
    }

    return os;
}

float& cVector::operator[](int index) {
    if (this->data && index >= 0 && index < this->dimension)
        return this->data[index];

    std::cerr << "\nCOMPILER ERROR : Loi truy xuat phan tu voi index " << index << '\n';
    exit(1);
}

float cVector::operator[](int index) const {
    if (this->data && index >= 0 && index < this->dimension)
        return this->data[index];

    std::cerr << "\nCOMPILER ERROR : Loi truy xuat phan tu voi index " << index << '\n';
    exit(1);
}

int main() {
    // Vector phải được xác định trước kích thuớc. Nếu chưa xác định trước khi run, chương trình sẽ mặc định là vector RỖNG => VÔ HIỆU HÓA VECTOR
    
    // Vector có kích thuớc hợp lệ nhưng chưa xác định trước data
    // => KHÔNG THỂ truy xuất dữ liệu, vẫn có thể nhập data nhưng không thể xuất data khi chưa nhập
    
    // Vector có kích thước không hợp lệ, chương trinh sẽ tự động hủy vector (vector RỖNG, dimension = 0, data = nullptr)
    // => KHÔNG THỂ truy xuất dữ liệu, không thể nhập data, và không thể xuất data kể cả khi đã nhập (vector bị vô hiệu hóa)
    

// -------------------------------------------------------------------------------------------------------------------------------------
    // Vector có số chiều hợp lệ nhưng chưa có dữ liệu (data = nullptr)
    // => Không thể xuất, nhưng có thể nhập dữ liệu (sau khi nhập mới có thể dùng được)
    cVector v1(5), v2(5);

    // Vector có số chiều nhỏ hơn hoặc bằng 0 => bị vô hiệu hóa (dimension = 0, data = nullptr)
    // => Không thể nhập, xuất, hay thực hiện phép toán
    cVector result;

    // Vector khác chiều v2 để thử phép cộng không hợp lệ
    cVector v6(2);

    // Xuất v1: chưa có data nên sẽ không hiển thị gì (hoặc cảnh báo)
    std::cout << "v1" << v1;

    // Nhập dữ liệu cho v2
    std::cin >> v2;
    std::cout << "v2" << v2;

    // Nhập dữ liệu cho v6
    std::cin >> v6;
    std::cout << "v6" << v6;

    // Xuất result: chưa khởi tạo dimension => sẽ là vector rỗng
    std::cout << "result" << result;

    // Cộng 2 vector khác chiều (v6 + v2) => sẽ báo lỗi và thoát
    result = v6 + v2;

    // Nếu trên không thoát, thực hiện thêm phép toán phức hợp
    cVector result1 = v1 - v2 + result;
    std::cout << "result1 = v1 - v2 + result" << result1;

    // Tính tích vô hướng
    std::cout << "dot(result, result1) = " << result.dotProduct(result1) << '\n';

    return 0;
}