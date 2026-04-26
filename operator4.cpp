/*4. Định nghĩa lớp CDate biểu diễn khái niệm ngày, tháng, năm với các phép toán +, -
(cộng, trừ thêm một số ngày), ++, -- (thêm bớt một ngày), - (khoảng cách giữa hai
CDate tính bằng ngày). Phép toán <<, >> để xuất, nhập dữ liệu loại CDate. Áp dụng
lớp CDate để giải bài toán tính lãi suất tiền gởi ngân hàng.*/
#include <bits/stdc++.h>
using namespace std;

class cDate
{
private:
    int ngay, thang, nam;

public:

    cDate(int ngay = 1, int thang = 1, int nam = 1)
    {
        this->ngay = ngay;
        this->thang = thang;
        this->nam = nam;
    }
    cDate operator+(int addDay);
    cDate operator-(int subDay);
    cDate& operator++(); 
    cDate& operator--(); 
    int operator-(const cDate &other);
    bool namNhuan();
    bool namNhuan(int n) const;
    int ngaytrongThang();
    int ngaytrongThang(int t, int n) const;
    friend istream &operator>>(istream &is, cDate &other);
    friend ostream &operator<<(ostream &os, cDate other);
};

bool cDate::namNhuan()
{
    return (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0));
}

bool cDate::namNhuan(int n) const
{
    return (n % 400 == 0 || (n % 4 == 0 && n % 100 != 0));
}

int cDate::ngaytrongThang()
{
    if (thang == 4 || thang == 6 || thang == 9 || thang == 11) return 30;
    if (thang == 2) return namNhuan() ? 29 : 28;
    return 31;
}

int cDate::ngaytrongThang(int t, int n) const
{
    if (t == 4 || t == 6 || t == 9 || t == 11) return 30;
    if (t == 2) return namNhuan(n) ? 29 : 28;
    return 31;
}

cDate cDate::operator+(int addDay)
{
    cDate res = *this;
    res.ngay += addDay;
    
    while (res.ngay > res.ngaytrongThang(res.thang, res.nam))
    {
        res.ngay -= res.ngaytrongThang(res.thang, res.nam);
        res.thang++;
        if (res.thang > 12)
        {
            res.thang = 1;
            res.nam++;
        }
    }
    return res;
}

cDate cDate::operator-(int subDay)
{
    cDate res = *this;
    res.ngay -= subDay;
    
    while (res.ngay <= 0)
    {
        res.thang--;
        if (res.thang == 0)
        {
            res.thang = 12; 
            res.nam--;
        }
        res.ngay += res.ngaytrongThang(res.thang, res.nam);
    }
    return res;
}

cDate& cDate::operator++()
{
    ngay++;
    if (ngay > ngaytrongThang(thang, nam))
    {
        ngay = 1;
        thang++;
        if (thang > 12)
        {
            thang = 1; 
            nam++;
        }
    }
    return *this; 
}

cDate& cDate::operator--()
{
    ngay--;
    if (ngay == 0)
    {
        thang--;
        if (thang == 0)
        {
            thang = 12; 
            nam--;
        }
        ngay = ngaytrongThang(thang, nam); 
    }
    return *this;
}

int cDate::operator-(const cDate &other)
{
    int days1 = this->ngay;
    for (int i = 1; i < this->nam; i++)
        days1 += (this->namNhuan(i) ? 366 : 365);
    for (int i = 1; i < this->thang; i++)
        days1 += this->ngaytrongThang(i, this->nam);
    int days2 = other.ngay;
    for (int i = 1; i < other.nam; i++)
        days2 += (other.namNhuan(i) ? 366 : 365);
    for (int i = 1; i < other.thang; i++)
        days2 += other.ngaytrongThang(i, other.nam);
    return abs(days1 - days2); 
}

istream &operator>>(istream &is, cDate &other)
{
    cout << "Nhap ngay: ";
    is >> other.ngay;
    cout << "Nhap thang: ";
    is >> other.thang;
    cout << "Nhap nam: ";
    is >> other.nam;
    return is;
}

ostream &operator<<(ostream &os, cDate other)
{
    string x = to_string(other.ngay);
    if (x.size() == 1)
        os << "0" << x << "/";
    else
        os << x << "/";
    string y = to_string(other.thang);
    if (y.size() == 1)
        os << "0" << y << "/";
    else
        os << y << "/";
    os << other.nam; 
    return os;
}
int main()
{
    cDate Day, x, y, nextDay;
    
    cout << "--- NHAP NGAY BAN DAU ---" << endl;
    cin >> Day;
    
    int addDay;
    cout << "\nNhap so ngay muon them: ";
    cin >> addDay;
    x = Day + addDay;
    cout << "=> " << Day << " cong them " << addDay << " ngay = " << x << endl;

    int subDay;
    cout << "\nNhap so ngay muon tru: ";
    cin >> subDay;
    y = Day - subDay;
    cout << "=> " << Day << " tru di " << subDay << " ngay = " << y << endl;

    cout << "\n--- TEST TOAN TU ++ VA -- ---" << endl;
    cDate tempDay = Day;
    cout << "Ngay tiep theo cua " << tempDay << " la " << ++tempDay << endl;
    cout << "Ngay truoc cua " << tempDay << " la " << --tempDay << endl;

    cout << "\n--- KHOANG CACH GIUA 2 NGAY ---" << endl;
    cout << "Nhap ngay thu hai de tinh khoang cach: " << endl;
    cin >> nextDay;
    cout << "=> Khoang cach giua hai ngay " << Day << " va " << nextDay << " la: " << Day - nextDay << " ngay" << endl;
    return 0;
}
