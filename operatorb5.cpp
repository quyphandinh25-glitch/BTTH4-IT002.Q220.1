/*5. Định nghĩa lớp biểu diễn khái niệm đa thức có bậc bất kỳ với các hàm thành phần
và phép toán cần thiết.*/
#include <bits/stdc++.h>
using namespace std;

class cDaThuc
{
private:
    int heso[100];
    int n;

public:
    cDaThuc();
    friend istream &operator>>(istream &is, cDaThuc &other);
    friend ostream &operator<<(ostream &os, cDaThuc other);
    cDaThuc operator+(const cDaThuc &other);
    cDaThuc operator-(const cDaThuc &other);
};
cDaThuc::cDaThuc()
{
    n = 0;
    for (int i = 0; i < 100; i++)
    {
        heso[i] = 0;
    }
}
istream &operator>>(istream &is, cDaThuc &other)
{
    cout << "Nhap bac cua da thuc n= ";
    is >> other.n;
    for (int i = other.n; i >= 0; i--)
    {
        cout << "Nhap he so cua bac " << i << " : ";
        is >> other.heso[i];
    }
    return is;
}
ostream &operator<<(ostream &os, cDaThuc other)
{
    bool check = true;
    for (int i = other.n; i >= 0; i--)
    {
        if (other.heso[i] == 0)
            continue;
            
        if (check == true)
        {
            os << other.heso[i] << "x^" << i;
            check = false;
        }
        else
        {
            if (other.heso[i] > 0)
            {
                os << " + " << other.heso[i] << "x^" << i;
            }
            else
            {
                os << " - " << abs(other.heso[i]) << "x^" << i;
            }
        }
    }
    if (check)
        os << "0";
    return os;
}

cDaThuc cDaThuc::operator+(const cDaThuc &other)
{
    cDaThuc kq;
    kq.n = max(this->n, other.n);
    for (int i = kq.n; i >= 0; i--)
    {
        kq.heso[i] = this->heso[i] + other.heso[i];
    }
    while (kq.n > 0 && kq.heso[kq.n] == 0) {
        kq.n--;
    }
    return kq;
}
cDaThuc cDaThuc::operator-(const cDaThuc &other)
{
    cDaThuc kq;
    kq.n = max(this->n, other.n);
    for (int i = kq.n; i >= 0; i--)
    {
        kq.heso[i] = this->heso[i] - other.heso[i];
    }
    while (kq.n > 0 && kq.heso[kq.n] == 0) {
        kq.n--;
    }
    return kq;
}


int main()
{
    cDaThuc a, b;
    
    cout << "\n--- Nhap da thuc A ---\n";
    cin >> a;
    
    cout << "\n--- Nhap da thuc B ---\n";
    cin >> b;
    
    cout << "\nDa thuc a(x): " << a << "\n";
    cout << "Da thuc b(x): " << b << "\n";
    
    cout << "Ket qua cong a(x) + b(x): ";
    cDaThuc x = a + b;
    cout << x << "\n";
    
    cout << "Ket qua tru a(x) - b(x): ";
    cDaThuc y = a - b;
    cout << y << "\n";
    
    return 0;
}
