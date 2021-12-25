#include "Motorbike.h"

Motorbike::Motorbike(string com ,string licen, int type, int c, string color, long Price)
    : Company(com), LicensePlates(licen), TypeOfCar(type), isRented(c), Color(color), Price(Price)
{

}
Motorbike::Motorbike(const Motorbike &m)
{
    this->Company = m.Company;
    this->LicensePlates = m.LicensePlates;
    this->TypeOfCar = m.TypeOfCar;
    this->isRented = m.isRented;
    this->Color = m.Color;
    this->Price = m.Price;
}
Motorbike::~Motorbike()
{

}
void Motorbike::Show()
{
    cout << "\t\t\t\t\t\t\t\t\t\tHang xe: " << this->Company << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tBien so: " << this->LicensePlates << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tLoai xe: " << this->TypeOfCar << "CC" << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tMau son: " << this->Color << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tGia Thue: " << this->Price << "/Ngay" << endl;
    if(this->isRented == 1)
    {
        cout << "\t\t\t\t\t\t\t\t\t\tTinh Trang Xe: Da Thue" << endl;
    }
    else cout << "\t\t\t\t\t\t\t\t\t\tTinh Trang Xe: Chua Thue" << endl;
}
void Motorbike::Show(ofstream& o)
{
    o << "\t\t\t\t\t\t\t\t\t\tHang xe: " << this->Company << endl;
    o << "\t\t\t\t\t\t\t\t\t\tBien so: " << this->LicensePlates << endl;
    o << "\t\t\t\t\t\t\t\t\t\tLoai xe: " << this->TypeOfCar << "CC" << endl;
    o << "\t\t\t\t\t\t\t\t\t\tMau son: " << this->Color << endl;
    o << "\t\t\t\t\t\t\t\t\t\tGia Thue: " << this->Price << "/Ngay" << endl;
    if(this->isRented == 1)
    {
        o << "\t\t\t\t\t\t\t\t\t\tTinh Trang Xe: Da Thue" << endl;
    }
    else o << "\t\t\t\t\t\t\t\t\t\tTinh Trang Xe: Chua Thue" << endl;
}
ostream &operator<<(ostream &o, const Motorbike &m)
{
    o << "\t\t\t\t\t\t\t\t\t\tHang xe: " << m.Company << endl;
    o << "\t\t\t\t\t\t\t\t\t\tBien so: " << m.LicensePlates << endl;
    o << "\t\t\t\t\t\t\t\t\t\tLoai xe: " << m.TypeOfCar << "CC" << endl;
    o << "\t\t\t\t\t\t\t\t\t\tMau son: " << m.Color << endl;
    o << "\t\t\t\t\t\t\t\t\t\tGia Thue: " << m.Price << "/Ngay" << endl;
    return o;
}
istream& operator>>(istream& i, Motorbike& m)
{
    cout << "\t\t\t\tNhap Ten Hang xe: ";
    getline(i, m.Company);
    cout << "\t\t\t\tNhap Bien so: ";
    i >> m.LicensePlates;
    cout << "\t\t\t\tNhap so Phan Khoi cua xe: " ;
    i >> m.TypeOfCar;
    cout << "\t\t\t\tNhap mau sac cua xe: ";
    i.ignore();
    getline(i, m.Color);
    cout << "\t\t\t\tNhap Gia Thue Xe: ";
    i >> m.Price;
    i.ignore();
    m.isRented = 0;
    return i;
}
string Motorbike::getCompany()
{
    return this->Company;
}
string Motorbike::getLicensePlates()
{
    return this->LicensePlates;
}
int Motorbike::getTypeOfCar()
{
    return this->TypeOfCar;
}
int Motorbike::getIsRented()
{
    return this->isRented;
}
void Motorbike::setIsRented(int check)
{
    this->isRented = check;
}
long Motorbike::getPrice()
{
    return this->Price;
}
void Motorbike::setPrice(int n)
{
    this->Price = n;
}