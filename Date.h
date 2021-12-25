#include<iostream>
#include<ctime>
#include<fstream>
using namespace std;
class Date
{
    private:
        int day, month, year;
    public:
        Date(int = 0, int = 0, int = 0);
        Date(const Date&);
        ~Date();
        void ShowRental();
        void ShowReturn();
        void ShowRental(ofstream&);
        void ShowReturn(ofstream&);
        int getDay();
        int getMonth();
        int getYear();
        friend ostream& operator<<(ostream& , const Date&);
        friend istream& operator>>(istream&, Date&);
};


