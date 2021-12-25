#include "Person.h"
#include<iostream>
#include <fstream>//
using namespace std;
Person::Person(string cmnd, string name, int age, string address, string phoneNumber) 
    : CMND(cmnd), Name(name), Age(age), Address(address), PhoneNumber(phoneNumber)
{
}

Person::Person(const Person &p)
{
    Person(p.CMND, p.Name, p.Age, p.Address, p.PhoneNumber);
}

Person::~Person()
{
}
void Person::Show()
{
    if(this->getAge() != 0)
    {
        cout << "\t\t\t\t\t\t\t\t\t\tTen nguoi thue: " << this->Name << endl;
        cout << "\t\t\t\t\t\t\t\t\t\tCMND: " << this->CMND << endl;
        cout << "\t\t\t\t\t\t\t\t\t\tTuoi: " << this->Age << endl;
        cout << "\t\t\t\t\t\t\t\t\t\tDia Chi: " << this->Address << endl;
        cout << "\t\t\t\t\t\t\t\t\t\tSo dien thoai: " << this->PhoneNumber << endl;
    }
}
void Person::Show(ofstream& o) //
{
    if(this->getAge() != 0)
    {
        o << "\t\t\t\t\t\t\t\t\t\tTen nguoi thue: " << this->Name << endl;
        o << "\t\t\t\t\t\t\t\t\t\tCMND: " << this->CMND << endl;
        o << "\t\t\t\t\t\t\t\t\t\tTuoi: " << this->Age << endl;
        o << "\t\t\t\t\t\t\t\t\t\tDia Chi: " << this->Address << endl;
        o << "\t\t\t\t\t\t\t\t\t\tSo dien thoai: " << this->PhoneNumber << endl;
    }
}
string Person::getName()
{
    return this->Name;
}
string Person::getCmnd()
{
    return this->CMND;
}
int Person::getAge()
{
    return this->Age;
}
void Person::setName(string name)
{
    this->Name = name;
}
void Person::setCmnd(string cmnd)
{
    this->CMND = cmnd;
}
void Person::setAge(int age)
{
    this->Age = age;
}
ostream& operator<<(ostream& o, const Person& p)
{
    o << "\t\t\t\t\t\t\t\t\tCMND: " << p.CMND << endl;
    o << "\t\t\t\t\t\t\t\t\tTen nguoi thue: " << p.Name << endl;
    o << "\t\t\t\t\t\t\t\t\tTuoi: " << p.Age << endl;
    o << "\t\t\t\t\t\t\t\t\tDia Chi: " << p.Address << endl;
    o << "\t\t\t\t\t\t\t\t\tSo dien thoai: " << p.PhoneNumber << endl;
    return o;
}
istream& operator>>(istream& i, Person& p)
{
    cout << "\t\t\t\t\t\t\t\t\tNhap ten khach hang: ";
    getline(i, p.Name);
    cout << "\t\t\t\t\t\t\t\t\tNhap CMND: " ;
    i >> p.CMND;
    cout << "\t\t\t\t\t\t\t\t\tNhap tuoi: ";
    i >> p.Age;
    cout << "\t\t\t\t\t\t\t\t\tNhap Dia Chi: ";
    i.ignore();
    getline(i, p.Address);
    cout << "\t\t\t\t\t\t\t\t\tNhap so dien thoai:" ;
    i >> p.PhoneNumber;
    return i;
}
