#ifndef CVECTOR_H
#define CVECTOR_H
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

#endif
