/*7. Định nghĩa lớp CMatrix biểu diễn khái niệm ma trận có kích thước bất kỳ với các
hàm thành phần và các phép toán cần thiết. Viết hàm tính tích của một ma trận và
một vector. Tích của hai ma trận.*/
#include <iostream>

using namespace std;

class CVector
{
private:
    int n;
    double toado[100];

public:
    CVector();
    friend istream &operator>>(istream &is, CVector &v);
    friend ostream &operator<<(ostream &os, CVector v);
    int getSize();
    void setSize(int size);
    double getElement(int index);
    void setElement(int index, double val);
};

class CMatrix
{
private:
    int rows;
    int cols;
    double data[100][100];

public:
    CMatrix();
    friend istream &operator>>(istream &is, CMatrix &m);
    friend ostream &operator<<(ostream &os, CMatrix m);
    CMatrix operator+(CMatrix other);
    CMatrix operator-(CMatrix other);
    CMatrix operator*(CMatrix other);
    CVector operator*(CVector v);
};

CVector::CVector()
{
    n = 0;
    for (int i = 0; i < 100; i++)
    {
        toado[i] = 0;
    }
}

istream &operator>>(istream &is, CVector &v)
{
    cout << "Nhap so chieu vector n = ";
    is >> v.n;
    for (int i = 0; i < v.n; i++)
    {
        cout << "Toa do thu " << i + 1 << " : ";
        is >> v.toado[i];
    }
    return is;
}

ostream &operator<<(ostream &os, CVector v)
{
    os << "(";
    for (int i = 0; i < v.n; i++)
    {
        os << v.toado[i];
        if (i < v.n - 1)
        {
            os << ", ";
        }
    }
    os << ")";
    return os;
}

int CVector::getSize()
{
    return n;
}

void CVector::setSize(int size)
{
    n = size;
}

double CVector::getElement(int index)
{
    return toado[index];
}

void CVector::setElement(int index, double val)
{
    toado[index] = val;
}

CMatrix::CMatrix()
{
    rows = 0;
    cols = 0;
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            data[i][j] = 0;
        }
    }
}

istream &operator>>(istream &is, CMatrix &m)
{
    cout << "Nhap so dong: ";
    is >> m.rows;
    cout << "Nhap so cot: ";
    is >> m.cols;
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            cout << "Phan tu [" << i << "][" << j << "] : ";
            is >> m.data[i][j];
        }
    }
    return is;
}

ostream &operator<<(ostream &os, CMatrix m)
{
    for (int i = 0; i < m.rows; i++)
    {
        for (int j = 0; j < m.cols; j++)
        {
            os << m.data[i][j] << "\t";
        }
        os << "\n";
    }
    return os;
}

CMatrix CMatrix::operator+(CMatrix other)
{
    CMatrix kq;
    kq.rows = this->rows;
    kq.cols = this->cols;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            kq.data[i][j] = this->data[i][j] + other.data[i][j];
        }
    }
    return kq;
}

CMatrix CMatrix::operator-(CMatrix other)
{
    CMatrix kq;
    kq.rows = this->rows;
    kq.cols = this->cols;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            kq.data[i][j] = this->data[i][j] - other.data[i][j];
        }
    }
    return kq;
}

CMatrix CMatrix::operator*(CMatrix other)
{
    CMatrix kq;
    kq.rows = this->rows;
    kq.cols = other.cols;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < other.cols; j++)
        {
            for (int k = 0; k < this->cols; k++)
            {
                kq.data[i][j] += this->data[i][k] * other.data[k][j];
            }
        }
    }
    return kq;
}

CVector CMatrix::operator*(CVector v)
{
    CVector kq;
    kq.setSize(this->rows);
    for (int i = 0; i < this->rows; i++)
    {
        double sum = 0;
        for (int j = 0; j < this->cols; j++)
        {
            sum += this->data[i][j] * v.getElement(j);
        }
        kq.setElement(i, sum);
    }
    return kq;
}

int main()
{
    CMatrix A, B;
    cout << "--- NHAP MA TRAN A ---\n";
    cin >> A;
    
    cout << "\n--- NHAP MA TRAN B ---\n";
    cin >> B;

    CVector V;
    cout << "\n--- NHAP VECTOR V ---\n";
    cin >> V;

    cout << "\nMa tran A:\n" << A;
    cout << "\nMa tran B:\n" << B;
    cout << "\nVector V: " << V << "\n";

    CMatrix tichAB = A * B;
    cout << "\nTich ma tran A * B:\n" << tichAB;

    CVector tichAV = A * V;
    cout << "\nTich ma tran A * Vector V: " << tichAV << "\n";

    return 0;
}
