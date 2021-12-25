#include"ThueXe.h"

ThueXe::ThueXe()
{
    
}
ThueXe::ThueXe(const Person &p, const Motorbike &m, const Date &d1,  const Date &d2, int day)
{
    this->Per = p;
    this->Motor = m;
    this->DateRental = d1;
    this->DateReturn = d2;
    this->NumberOfDayRental = day;
}
ThueXe::~ThueXe()
{

}
void ThueXe::Show()
{
    this->Per.Show();
    this->Motor.Show();
    this->DateRental.ShowRental();
    this->DateReturn.ShowReturn();
    if(this->GetMoney() > 0)
    {
        cout << "\t\t\t\t\t\t\t\t\t\tSo ngay thue: " << this->NumberOfDayRental << endl;
        cout << "\t\t\t\t\t\t\t\t\t\tSo tien thanh toan: " << this->GetMoney() << endl;
    }
}
void ThueXe::Show(ofstream& o)
{
    this->Per.Show(o);
    this->Motor.Show(o);
    this->DateRental.ShowRental(o);
    this->DateReturn.ShowReturn(o);
    if(this->GetMoney() > 0)
    {
        o << "\t\t\t\t\t\t\t\t\t\tSo ngay thue: " << this->NumberOfDayRental << endl;
        o << "\t\t\t\t\t\t\t\t\t\tSo tien thanh toan: " << this->GetMoney() << endl;
    }
}
long long ThueXe::GetMoney()
{
    return this->Motor.getPrice() * this->NumberOfDayRental;
}
void ThueXe::ShowBill()
{
    cout << "\n\n\t\t\t\t\t\t\t\t-----------------HOA DON CUA BAN------------------\n" << endl;
    this->Per.Show();
    cout << this->Motor;
    this->DateRental.ShowRental();
    this->DateReturn.ShowReturn();
    cout << "\t\t\t\t\t\t\t\t\t\tSo ngay thue: " << this->NumberOfDayRental << endl;
    cout << "\t\t\t\t\t\t\t\t\t\tTong so tien thanh toan: " << GetMoney() << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t--------------------------------------------------" << endl;
}
ThueXe& ThueXe::operator=(const ThueXe& m)
{
    this->Per = m.Per;
    this->Motor = m.Motor;
    this->DateRental = m.DateRental;
    this->DateReturn = m.DateReturn;
    this->NumberOfDayRental = m.NumberOfDayRental;
}