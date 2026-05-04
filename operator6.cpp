/*6. Định nghĩa lớp CVector biểu diễn khái niệm vector trong không gian có số 
chiều bất kỳ với các hàm thành phần và các phép toán cần thiết.*/
#include <iostream>
#include <cmath>
using namespace std;

class CVector
{
private:
    int n;
    double *toado;

public:
    CVector();
    CVector(int soChieu);
    friend istream &operator>>(istream &is, CVector &other);
    friend ostream &operator<<(ostream &os, CVector other);
    CVector operator+(const CVector &other);
    CVector operator-(const CVector &other);
    double operator*(const CVector &other);
};

CVector::CVector()
{
    n = 0;
    toado = NULL;
}

CVector::CVector(int soChieu)
{
    n = soChieu;
    toado = new double[n];
    for (int i = 0; i < n; i++)
    {
        toado[i] = 0;
    }
}

istream &operator>>(istream &is, CVector &other)
{
    cout << "Nhap so chieu cua vector n = ";
    is >> other.n;
    other.toado = new double[other.n];
    for (int i = 0; i < other.n; i++)
    {
        cout << "Nhap toa do thu " << i + 1 << " : ";
        is >> other.toado[i];
    }
    return is;
}

ostream &operator<<(ostream &os, CVector other)
{
    if (other.n == 0)
    {
        os << "(Rong)";
        return os;
    }
    os << "(";
    for (int i = 0; i < other.n; i++)
    {
        os << other.toado[i];
        if (i < other.n - 1)
        {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

CVector CVector::operator+(const CVector &other)
{
    int chieuMax = max(this->n, other.n);
    CVector kq(chieuMax);
    for (int i = 0; i < chieuMax; i++)
    {
        double val1 = (i < this->n) ? this->toado[i] : 0;
        double val2 = (i < other.n) ? other.toado[i] : 0;
        kq.toado[i] = val1 + val2;
    }
    return kq;
}

CVector CVector::operator-(const CVector &other)
{
    int chieuMax = max(this->n, other.n);
    CVector kq(chieuMax);
    for (int i = 0; i < chieuMax; i++)
    {
        double val1 = (i < this->n) ? this->toado[i] : 0;
        double val2 = (i < other.n) ? other.toado[i] : 0;
        kq.toado[i] = val1 - val2;
    }
    return kq;
}

double CVector::operator*(const CVector &other)
{
    double kq = 0;
    int chieuMin = min(this->n, other.n);
    for (int i = 0; i < chieuMin; i++)
    {
        kq += this->toado[i] * other.toado[i];
    }
    return kq;
}

int main()
{
    CVector a, b;
    cin >> a >> b;

    cout << "\nVector a = " << a << "\n";
    cout << "Vector b = " << b << "\n";

    CVector tong = a + b;
    cout << "a + b = " << tong << "\n";

    CVector hieu = a - b;
    cout << "a - b = " << hieu << "\n";

    double tich = a * b;
    cout << "a * b = " << tich << "\n";

    return 0;
}
