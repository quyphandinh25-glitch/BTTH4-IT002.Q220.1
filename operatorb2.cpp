
/*2. Làm lại bài phân số với các phương thức thiết lập cho phép sử dụng một số nguyên
như một phân số đặc biệt (mẫu số bằng 1). Định nghĩa các phép toán +, -, *, /, ==,
>, < trên phân số. Định nghĩa phép toán << và >> để xuất và nhập dữ liệu cho phân
số.*/
#include <bits/stdc++.h>
using namespace std;
int ucln(int a, int b)
{
    a = abs(a);
    b = abs(b);
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}
class cPhanSo
{
private:
    int tu, mau;

public:
    cPhanSo(int tu = 0, int mau = 1)
    {
        this->tu = tu;
        this->mau = mau;
    };
    cPhanSo operator+(const cPhanSo &other);
    cPhanSo operator-(const cPhanSo &other);
    cPhanSo operator*(const cPhanSo &other);
    cPhanSo operator/(const cPhanSo &other);
    void RutGon();
    bool operator==(const cPhanSo &other);
    bool operator!=(const cPhanSo &other);
    bool operator>(const cPhanSo &other);
    bool operator<(const cPhanSo &other);
    friend ostream &operator<<(ostream &os, cPhanSo other);
    friend istream &operator>>(istream &is, cPhanSo &other);
};
cPhanSo cPhanSo::operator+(const cPhanSo &other)
{
    cPhanSo res;
    res.tu = tu * other.mau + other.tu * mau;
    res.mau = mau * other.mau;
    return res;
}
cPhanSo cPhanSo::operator-(const cPhanSo &other)
{
    cPhanSo res;
    res.tu = tu * other.mau - other.tu * mau;
    res.mau = mau * other.mau;
    return res;
}
cPhanSo cPhanSo::operator*(const cPhanSo &other)
{
    cPhanSo res;
    res.tu = tu * other.tu;
    res.mau = mau * other.mau;
    return res;
}
cPhanSo cPhanSo::operator/(const cPhanSo &other)
{
    cPhanSo res;
    res.tu = tu * other.mau;
    res.mau = mau * other.tu;
    return res;
}
void cPhanSo::RutGon()
{
    int k = ucln(tu, mau);
    tu = tu / k;
    mau = mau / k;
}
bool cPhanSo::operator==(const cPhanSo &other)
{
    return mau * other.tu == tu * other.mau;
}
bool cPhanSo::operator!=(const cPhanSo &other)
{
    return mau * other.tu != tu * other.mau;
}
bool cPhanSo::operator<(const cPhanSo &other)
{
    return tu * other.mau < mau * other.tu;
}
bool cPhanSo::operator>(const cPhanSo &other)
{
    return tu * other.mau > mau * other.tu;
}
ostream &operator<<(ostream &os, cPhanSo other)
{
    if (other.mau == 0)
    {
        cout << "Phan so khong hop le !";
        return os;
    }
    if (other.mau < 0)
    {
        other.tu = -other.tu;
        other.mau = -other.mau;
    }
    if (other.tu == 0)
    {
        os << 0;
    }
    else if (other.mau == 1)
    {
        os << other.tu << endl;
    }
    else
    {
        other.RutGon();
        os << other.tu << "/" << other.mau;
    }
    return os;
}

istream &operator>>(istream &is, cPhanSo &other)
{
    string input;
    getline(is, input); 
    stringstream ss(input);
    
    ss >> other.tu; 
    
    if (!(ss >> other.mau)) 
    {
        other.mau = 1;
    }
    return is;
}
int main()
{
    cPhanSo a, b;
    cin >> a >> b;
    cout << "Ket qua cong 2 phan so " << a << "; " << b;
    cPhanSo x = a + b;
    cout << x << endl;
    cout << "Ket qua tru 2 phan so " << a << "; " << b;
    cPhanSo y = a - b;
    cout << y << endl;
    cout << "Ket qua nhan 2 phan so " << a << "; " << b;
    cPhanSo z = a * b;
    cout << z << endl;
    cout << "Ket qua chi 2 phan so " << a << "; " << b;
    cPhanSo t = a / b;
    cout << t << endl;
    if (a == b)
    {
        cout << "Hai phan so " << a << " va " << b << " bang nhau\n";
    }
    if (a != b)
    {
        cout << "Hai phan so " << a << " va " << b << " khong bang nhau\n";
    }
    if (a > b)
    {
        cout << "Phan so a " << a << " lon hon phan so b " << b << endl;
    }
    if (a < b)
    {
        cout << "Phan so a " << a << " nho hon phan so b " << b << endl;
    }
    return 0;
}
