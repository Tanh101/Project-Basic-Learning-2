#include "Motorbike.h"
#include"Person.h"
#include "Date.h"
#include <fstream>
class ThueXe
{
private:
    Person Per;
    Motorbike Motor;
    Date DateRental;
    Date DateReturn;
    int NumberOfDayRental;
public:
    ThueXe();
    ThueXe(const Person&,const  Motorbike& ,const Date&,const Date&, int = 0);
    ~ThueXe();
    void Show();
    void Show(ofstream &);
    // int getNumberOfDayRental;
    long long GetMoney();   //Tinh tien thue xe cua khach
    void ShowBill();    //show tat car thong tin ngay thue, ngay tra neu co cua khach hang
    ThueXe& operator=(const ThueXe&);
    friend class List;
};
