#include "Date.h"

Date::Date(int d, int moth, int year)
: day(d), month(moth), year(year){

}
Date::Date(const Date& d)
{
    Date(d.day, d.month, d.year);
}
Date::~Date()
{

}
void Date::ShowRental()
{
    if(this->year != 0){
        cout << "\t\t\t\t\t\t\t\t\t\tNgay Thue: " << this->day << " / "
            << this->month <<" / " << this->year << endl;
    }
}
void Date::ShowRental(ofstream& o)
{
    if(this->year != 0){
        o << "\t\t\t\t\t\t\t\t\t\tNgay Thue: " << this->day << " / "
            << this->month <<" / " << this->year << endl;
    }
}
void Date::ShowReturn(ofstream& o)
{
    if(this->year != 0)
    {
        o << "\t\t\t\t\t\t\t\t\t\tNgay Tra: " << this->day << " / "
            << this->month <<" / " << this->year << endl;
    }
}
void Date::ShowReturn()
{
    if(this->year != 0)
    {
        cout << "\t\t\t\t\t\t\t\t\t\tNgay Tra: " << this->day << " / "
            << this->month <<" / " << this->year << endl;
    }
}
ostream& operator<<(ostream& o, const Date& d)
{
    o << "\t\t\t\tNgay: " << d.day << " / "
        <<d.month <<" / " << d.year << endl;
    return o;
}
istream& operator>>(istream& i, Date& d)
{
    cout << "\t\t\t\t\t\tNhap lan luot ngay, thang, nam: ";
    i >> d.day >> d.month >> d.year;
    return i;
}
int Date::getDay()
{
    return this->day;
}
int Date::getMonth()
{
    return this->month;
}
int Date::getYear()
{
    return this->year;
}