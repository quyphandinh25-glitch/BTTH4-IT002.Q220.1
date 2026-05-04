/*Định nghĩa lớp CTime biểu diễn khái niệm thời điểm có các thành phần giờ phút
giây. Định nghĩa các phép toán +, - (cộng, trừ thêm một số nguyên giây, ++, -- (thêm
bớt một giây). Phép toán <<, >> để xuất, nhập dữ liệu loại CTime. Áp dụng lớp
CTime để tạo đồng hồ in ở góc trên bên phải màn hình.*/
#include <bits/stdc++.h>
using namespace std;
class cTime
{
private:
    int gio, phut, giay;

public:
    cTime(int gio = 0, int phut = 0, int giay = 0)
    {
        this->gio = gio;
        this->phut = phut;
        this->giay = giay;
    };
    friend istream &operator>>(istream &is, cTime &other);
    friend ostream &operator<<(ostream &os, cTime other);
    cTime operator+(int s);
    cTime operator-(int s);
};
istream &operator>>(istream &is, cTime &other)
{
    is >> other.gio >> other.phut >> other.giay;
    return is;
};
ostream &operator<<(ostream &os, cTime other)
{
    if (other.gio < 10) os << "0";
    os << other.gio << ":";
    if (other.phut < 10) os << "0";
    os << other.phut << ":";
    if (other.giay < 10) os << "0";
    os << other.giay;
    return os;
};
cTime cTime::operator+(int s)
{
    long long tongGiay = gio * 3600 + phut * 60 + giay + s;
    tongGiay = (tongGiay % 86400 + 86400) % 86400;
    return cTime(tongGiay / 3600, (tongGiay % 3600) / 60, tongGiay % 60);
}
cTime cTime::operator-(int s)
{
    return *this + (-s);
}
int main()
{
    cTime time;
    cin >> time;
    int addTime;
    cout<<"Nhap so giay muon them: "; cin>>addTime;
    cTime a = time + addTime;
    cout << a <<endl;
    int subTime;
    cout<<"Nhap so giay muon tru: "; cin>>subTime;
    cTime b = time - subTime;
    cout << b;
    return 0;
}
