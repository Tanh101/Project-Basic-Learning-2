#include<iostream>
#include <fstream>
using namespace std;
class Motorbike
{
private:
    string Company;
    string LicensePlates;
    int TypeOfCar;
    int isRented;
    string Color;
    long Price;
public:
    Motorbike(string = "", string = "", int = 0, int = 0, string = "", long = 0);
    Motorbike(const Motorbike&);
    ~Motorbike();
    void Show();
    void Show(ofstream&);
    friend ostream& operator<<(ostream& , const Motorbike&);
    friend istream& operator>>(istream&, Motorbike&);
    string getCompany();
    string getLicensePlates();
    int getTypeOfCar();
    int getIsRented();
    string getColor();
    void setIsRented(int );
    long getPrice();
    void setPrice(int);
    
};

