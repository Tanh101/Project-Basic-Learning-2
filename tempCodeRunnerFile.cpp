#include <iostream>
#include <fstream>

using namespace std;

class HINHTHANG
{
     double a, b, h;

public:
     HINHTHANG();
     HINHTHANG(double, double, double);
     friend istream &operator>>(istream &x, HINHTHANG &y);
     friend ostream &operator<<(ostream &x, HINHTHANG y);
     HINHTHANG operator+(HINHTHANG y);
     double operator++();
     bool operator==(HINHTHANG &);
};
HINHTHANG::HINHTHANG()
{
     a = 0;
     b = 0;
     h = 0;
}
HINHTHANG::HINHTHANG(double a1, double b1, double h1) : a(a1), b(b1), h(h1)
{
}
istream &operator>>(istream &x, HINHTHANG &y)
{
     cout << "Nhap day lon: ";
     x >> y.a;
     cout << "Nhap day be: ";
     x >> y.b;
     cout << "Nhap chieu cao: ";
     x >> y.h;
     return x;
}
ostream &operator<<(ostream &x, HINHTHANG y)
{
     x << "Day lon: " << y.a << endl;
     x << "Day be: : " << y.b << endl;
     x << "Chieu cao: " << y.h << endl;
     return x;
}
HINHTHANG HINHTHANG::operator+(HINHTHANG y)
{
     HINHTHANG tmp;
     tmp.a = this->a + y.a;
     tmp.b = this->b + y.b;
     tmp.h = this->h + y.h;
     return tmp;
}
double HINHTHANG::operator++()
{
     return (a + b) * h / 2.0;
}
bool HINHTHANG::operator==(HINHTHANG &h1)
{
     double d1 = ++(*(this));
     double d2 = ++h1;
     if (d1 == d2)
          return true;
     return false;
}
int main()
{
     HINHTHANG h1, h2;
     cout << "-----Nhap hinh thang thu 1 -----" << endl;
     cin >> h1;
     cout << "-----Nhap hinh thang thu 2-----" << endl;
     cin >> h2;
     ofstream f("D:/HINHTHANG15.txt", ios::out);
     f << h1;
     f << "Dien tich hinh thang thu nhat la: " << ++h1 << endl;
     f << h2;
     f << "Dien tich hinh thang thu hai la: " << ++h2 << endl;
     f << "Tong hai hinh thang: " << h1 + h2 << endl;
     if (h1 == h2)
          cout << "Hai hinh thang co dien tich bang nhau!" << endl;
     else
          cout << "Hai hinh thang co dien tich khong bang nhau!" << endl;
     f.close();
     return 0;
}