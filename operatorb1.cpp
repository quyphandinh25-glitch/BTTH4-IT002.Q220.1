/*1. Làm lại bài số phức với một phương thức thiết lập duy nhất cho phép quan điểm một
số thực như một số phức đặc biệt (phần ảo bằng 0). Định nghĩa các phép toán +, -,
*, /, ==, != trên số phức. Định nghĩa phép toán << và >> để xuất và nhập dữ liệu cho
số phức.*/
#include <iostream>
using namespace std;

class cSoPhuc
{
private:
    double thuc, ao;

public:
    cSoPhuc(double thuc = 0, double ao = 0)
    {
        this->thuc = thuc;
        this->ao = ao;
    }
    cSoPhuc operator+(const cSoPhuc &other);
    cSoPhuc operator-(const cSoPhuc &other);
    cSoPhuc operator*(const cSoPhuc &other);
    cSoPhuc operator/(const cSoPhuc &other);
    bool operator==(const cSoPhuc &other);
    bool operator!=(const cSoPhuc &other);
    friend ostream &operator<<(ostream &os, cSoPhuc other);
    friend istream &operator>>(istream &is, cSoPhuc &other);
};

// Định nghĩa chi tiết bên ngoài
cSoPhuc cSoPhuc::operator+(const cSoPhuc &other)
{
    cSoPhuc res;
    res.thuc = thuc + other.thuc;
    res.ao = ao + other.ao;
    return res;
}

cSoPhuc cSoPhuc::operator-(const cSoPhuc &other)
{
    cSoPhuc res;
    res.thuc = thuc - other.thuc;
    res.ao = ao - other.ao;
    return res;
}

cSoPhuc cSoPhuc::operator*(const cSoPhuc &other)
{
    cSoPhuc res;
    res.thuc = thuc * other.thuc - ao * other.ao;
    res.ao = thuc * other.ao + ao * other.thuc;
    return res;
}

cSoPhuc cSoPhuc::operator/(const cSoPhuc &other)
{
    cSoPhuc res;
    double mau_chung = other.ao * other.ao + other.thuc * other.thuc;
    res.thuc = (thuc * other.thuc + ao * other.ao) / mau_chung;
    res.ao = (ao * other.thuc - thuc * other.ao) / mau_chung;
    return res;
}

bool cSoPhuc::operator==(const cSoPhuc &other)
{
    return ao == other.ao && thuc == other.thuc;
}

bool cSoPhuc::operator!=(const cSoPhuc &other)
{
    return (ao != other.ao) || (thuc != other.thuc);
}

ostream &operator<<(ostream &os, cSoPhuc other)
{
    os << other.thuc;
    if (other.ao < 0)
    {
        os << " - " << -other.ao << "i";
    }
    else if (other.ao > 0)
    {
        os << " + " << other.ao << "i";
    }
    return os;
}

istream &operator>>(istream &is, cSoPhuc &other)
{
    cout << "Nhap phan thuc: ";
    is >> other.thuc;
    cout << "Nhap phan ao: ";
    is >> other.ao;
    return is;
}

int main()
{
    cSoPhuc a, b;
    cin >> a >> b;
    
    cout << "Hai so phuc vua nhap la: (" << a << ") va (" << b << ")\n";
    
    cSoPhuc x = a + b;
    cout << "Ket qua cong: " << x << endl;
    
    cSoPhuc y = a - b;
    cout << "Ket qua tru: " << y << endl;
    
    cSoPhuc z = a * b;
    cout << "Ket qua nhan: " << z << endl;
    
    cSoPhuc t = a / b;
    cout << "Ket qua chia: " << t << endl;
    
    if (a == b)
    {
        cout << "Hai so phuc bang nhau\n";
    }
    else
    {
        cout << "Hai so phuc khong bang nhau\n";
    }
    
    return 0;
}
