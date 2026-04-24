#include <bits/stdc++.h>
/*1. Làm lại bài số phức với một phương thức thiết lập duy nhất cho phép quan điểm một
số thực như một số phức đặc biệt (phần ảo bằng 0). Định nghĩa các phép toán +, -,
*, /, ==, != trên số phức. Định nghĩa phép toán << và >> để xuất và nhập dữ liệu cho
số phức.*/
using namespace std;
class cSoPhuc
{
private:
    int thuc, ao;

public:
    cSoPhuc() {};
    cSoPhuc(int thuc, int ao)
    {
        this->thuc = thuc;
        this->ao = ao;
    };
    cSoPhuc operator+(const cSoPhuc &other) {}
    cSoPhuc operator-(const cSoPhuc &other) {}
    cSoPhuc operator*(const cSoPhuc &other) {}
    cSoPhuc operator/(const cSoPhuc &other) {}
    bool operator==(const cSoPhuc &other) {}
    bool operator!=(const cSoPhuc &other) {}
    friend ostream &operator<<(ostream &os, cSoPhuc other) {}
    friend istream &operator>>(istream &is, cSoPhuc &other) {}
};
cSoPhuc::cSoPhuc() {};
cSoPhuc::cSoPhuc(int thuc, int ao)
{
    this->thuc = thuc;
    this->ao = ao;
};
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
    res.thuc = (thuc * other.thuc + ao * other.ao) / (other.ao * other.ao + other.thuc * other.thuc);
    res.ao = (ao * other.thuc - thuc * other.ao) / (other.ao * other.ao + other.thuc * other.thuc);
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
    os << "So phuc: " << other.thuc;
    if (other.ao < 0)
    {
        cout << " - " << -other.ao << "i";
    }
    else
        cout << " + " << other.ao << "i";
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
    cout << "Ket qua cong 2 so phuc " << a << " " << b << endl;
    cSoPhuc x = a + b;
    cout << x << endl;
    cout << "Ket qua tru 2 so phuc " << a << " " << b << endl;
    cSoPhuc y = a - b;
    cout << y << endl;
    cout << "Ket qua nhan 2 so phuc " << a << " " << b << endl;
    cSoPhuc z = a * b;
    cout << z << endl;
    cout << "Ket qua chi 2 so phuc " << a << " " << b << endl;
    cSoPhuc t = a / b;
    cout << t << endl;
    if (a == b)
    {
        cout << "Hai so phuc " << a << " va " << b << " bang nhau\n";
    }
    if (a != b)
    {
        cout << "Hai so phuc " << a << " va " << b << " khong bang nhau\n";
    }
    return 0;
}
