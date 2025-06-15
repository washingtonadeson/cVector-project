#include "cVector.h"

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
