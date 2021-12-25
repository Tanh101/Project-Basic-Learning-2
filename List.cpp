#include "List.h"
#include <iomanip>
#include <iostream>
using namespace std;

List::List()
{
    this->p = nullptr;
    this->length = 0;
}
List::List(ThueXe *m, int len)
{
    this->length = len;
    this->p = new ThueXe[this->length];
    for (int i = 0; i < this->length; i++)
    {
        *(this->p + i) = *(m + i);
    }
}
List::List(const List &l)
{
    this->length = l.length;
    this->p = new ThueXe[this->length];
    for (int i = 0; i < this->length; i++)
    {
        *(this->p + i) = *(l.p + i);
    }
}
List List::operator=(const List &l)
{
    this->length = l.length;
    this->p = new ThueXe[this->length];
    for (int i = 0; i < this->length; i++)
    {
        *(this->p + i) = *(l.p + i);
    }
    return *this;
}
List::~List()
{
    delete[] this->p;
}

int List::getLength()
{
    return this->length;
}
bool List::checkCmnd(Person &p)
{
    int count = 0;
    for (int i = 0; i < this->length; i++)
    {
        if ((p.getCmnd()).compare((this->p + i)->Per.getCmnd()) == 0)
            count++;
    }
    if (count == 1)
        return true;
    return false;
}
Date getTimeNow()
{
    time_t now = time(0);
    tm *time = localtime(&now);
    Date d(time->tm_mday, time->tm_mon + 1, time->tm_year + 1900);
    return d;
}

void List::Add(Motorbike &m)
{
    if (this->length == 0)
    {
        this->p = new ThueXe[this->length + 1];
        (*(this->p)).Motor = m;
    }
    else
    {
        ThueXe *tmp = new ThueXe[this->length];
        for (int i = 0; i < this->length; i++)
        {
            *(tmp + i) = *(this->p + i);
        }
        delete[] this->p;
        this->p = new ThueXe[this->length + 1];
        for (int i = 0; i < this->length; i++)
        {
            *(this->p + i) = *(tmp + i);
        }
        (*(this->p + this->length)).Motor = m;
        (*(this->p + this->length)).NumberOfDayRental = 0;
        delete[] tmp;
    }
    this->length++;
}

void List::Display()
{
    if (this->length == 0)
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t---------------- KHONG CO XE MAY TRONG DANH SACH -----------------" << endl;
    else
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\tDANH SACH XE VA TINH TRANG TRONG HE THONG" << endl;
        cout << endl;
        for (int i = 0; i < this->length; i++)
        {
            cout << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------" << endl;
            cout << "\t\t\t\t\t\t\t\t\tMotorbike " << i + 1 << endl;
            (*(this->p + i)).Show();
        }
        cout << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------" << endl;
    }
}

void List::EnterList()
{
    ifstream in;
    in.open("ListMotorbike.txt");
    int n;
    in >> n;
    this->length = n;
    this->p = new ThueXe[this->length];
    in.ignore();
    for (int i = 0; i < this->length; i++)
    {
        Motorbike m;
        in >> m;
        (*(this->p + i)).Motor = m;
        (*(this->p + i)).NumberOfDayRental = 0;
    }
    in.close();
    system("cls");
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t------------ Upload from file successful -----------" << endl;
}

void List::ShowListMotor()
{
    if (this->length == 0)
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t---------------- KHONG CO XE MAY TRONG DANH SACH -----------------" << endl;
    else
    {
        cout << endl;
        cout << setw(30) << "\n\n\t\t\t\t\t\t\t\t\t\tDanh sach Motorbike trong he thong: " << endl;
        cout << "\t------------------------------------------------------------------------"
                "----------------------------------------------------------------------------"
                "-----------------------------"
             << endl;
        for (int i = 0; i < this->length; i++)
        {
            cout << "\t\t\t\t\t\t\t\tMotorbike " << i + 1 << endl;
            (this->p + i)->Motor.Show();
            cout << "\t------------------------------------------------------------------------"
                    "----------------------------------------------------------------------------"
                    "-----------------------------"
                 << endl;
        }
    }
}

int List::indexOf(string BienSo)
{
    for (int i = 0; i < this->length; i++)
    {
        if (BienSo.compare((this->p + i)->Motor.getLicensePlates()) == 0)
        {
            return i;
        }
    }
    return -1;
}

int List::indexOf(int TypeOfCar)
{
    for (int i = 0; i < this->length; i++)
    {
        if (TypeOfCar == (this->p + i)->Motor.getTypeOfCar())
        {
            return i;
        }
    }
    return -1;
}

int List::indexOfCarReturn(string BienSo)
{
    for (int i = 0; i < this->length; i++)
    {
        if (BienSo.compare((this->p + i)->Motor.getLicensePlates()) == 0 && (this->p + i)->Motor.getIsRented() == 1)
        {
            return i;
        }
    }
    return -1;
}

void List::UpdateRental(int n)
{
    if (n > this->length)
    {
        cout << "\t\t\t\t\t\t\t\t\tSo luong xe muon thue khong hop le! Vui long kiem tra lai!" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {

            cout << "\t\t\t\t\t\t\t\tMotorbike " << i + 1 << ": " << endl;
            string bs;
            cout << "\t\t\t\t\t\t\t\t\tNhap Bien so xe muon thue: ";
            cin >> bs;
            int k = indexOf(bs);
            if ((this->p + k)->Motor.getIsRented() != 1 && k >= 0 && k < this->length)
            {
                cin.ignore();
                cin >> (this->p + k)->Per;
                if (checkCmnd((this->p + k)->Per))
                {
                    Date d2;
                    d2 = getTimeNow();
                    (*(this->p + k)).DateRental = d2;
                    do
                    {
                        cout << "\t\t\t\t\t\t\t\t\tNhap so ngay muon thue: ";
                        cin >> (this->p + k)->NumberOfDayRental;
                    } while ((this->p + k)->NumberOfDayRental > 30);
                    
                    
                    (*(this->p + k)).Motor.setIsRented(1);
                    system("cls");
                    (this->p + k)->ShowBill();
                }
                else
                {
                    Person p;
                    (this->p + k)->Per = p;
                    cout << "\t\t\t\t\t\t\t\t\t\tBan dang thue mot xe khac trong he thong! Vui long tra xe truoc khi thue!" << endl;
                }
            }
            else
            {
                cout << "\t\t\t\t\t\t\t\t\t\tXe da duoc nguoi khac thue! Vui long chon xe khac" << endl;
            }
        }
    }
}

void List::Find(string Bienso)
{
    int k = indexOf(Bienso);
    if (k != -1)
    {
        cout << "\n\t\t\t\t\t\t Thong tin xe: " << endl;
        (this->p + k)->Show();
    }
    else
        cout << "\n\t\t\tKhong tim thay xe trong he thong! Vui long kiem tra lai" << endl;
}
void List::FindUser(string BienSo, int &c)
{
    system("cls");
    c = 0;
    int k = indexOf(BienSo);
    // cout << k << endl;
    if (k != -1)
    {

        if ((this->p + k)->NumberOfDayRental == 0)
        {
            c = 1;
            cout << "\n\t\t\t\t\t\t Thong tin Motorbike " << k + 1 << ": " << endl;
            (this->p + k)->Show();
        }
        if (c == 0)
        {
            cout << "\n\t\t\t\t\t\t Xe Da Duoc Thue, Quy Khach Vui Long Chon Xe Khac !" << endl;
        }
    }
    else
        cout << "\n\t\t\tKhong tim thay xe trong he thong! Vui long kiem tra lai" << endl;
}
void List::FindUser(int TypeOfCar, int &t)
{
    system("cls");
    t = 0;
    int k = 0;
    for (int i = 0; i < this->length; i++)
    {
        if ((this->p + i)->Motor.getIsRented() == 0)
        {
            k = 1;
            if (TypeOfCar == (this->p + i)->Motor.getTypeOfCar())
            {
                t = 1;
                cout << "\n\t\t\t\t\t\t Thong tin Motorbike " << i + 1 << ": " << endl;
                (this->p + i)->Show();
            }
        }
    }
    if (k == 0)
    {
        cout << "\n\t\t\tXe Da Duoc Thue! Vui long kiem tra lai" << endl;
        return;
    }
    if (t == 0)
        cout << "\n\t\t\tKhong tim thay xe trong he thong! Vui long kiem tra lai" << endl;
}
void List::FindCompany(string Company)
{
    int k = indexOf(Company);
    if (k != -1)
        (this->p + k)->Show();
    else
        cout << "\n\t\t\tKhong tim thay xe trong he thong! Vui long kiem tra lai" << endl;
}
void List::Clear(ThueXe &t)
{
    Person a;
    t.Per = a;
    t.NumberOfDayRental = 0;
    Date d;
    t.DateRental = t.DateReturn = d;
}
void List::Delete(string LicensePlates)
{
    int k;
    k = indexOf(LicensePlates);
    if (k == -1)
        cout << "\n\t\t\tKhong tim thay xe trong he thong! Vui long kiem tra lai" << endl;
    else
    {
        if ((this->p + k)->Motor.getIsRented() == 0)
        {
            ThueXe *tmp = new ThueXe[this->length];
            for (int i = 0; i < this->length; i++)
            {
                *(tmp + i) = *(this->p + i);
            }
            delete[] this->p;
            this->p = new ThueXe[this->length - 1];
            for (int i = 0; i < k; i++)
            {
                *(this->p + i) = *(tmp + i);
            }
            for (int i = k; i < this->length - 1; i++)
            {
                *(this->p + i) = *(tmp + i + 1);
            }
            this->length--;
            system("cls");
            cout << endl;
            cout << "\n\n\t\t\t\t\t\t\t\t\t\t------------ Xoa xe thanh cong -----------" << endl;
        }
        else
        {
            cout << "\n\t\t\tXe hien tai dang duoc thue!" << endl;
        }
    }
}
void List::UpdateAfterReturn(int n)
{
    if (n <= 0)
        cout << "\n\t\t\tSo Luong xe nhap vao khong hop le!" << endl;
    else
    {
        for (int i = 0; i < n; i++)
        {
            string BienSo;
            cout << "\n\t\tNhap Bien so xe cua xe muon tra: ";
            cin >> BienSo;
            int k = indexOfCarReturn(BienSo);
            if (k == -1)
                cout << "\n\t\t\tKhong tim thay xe co bien so: " << BienSo << " trong danh sach xe da thue!" << endl;
            else
            {
                Date d = getTimeNow();
                (*(this->p + k)).DateReturn = d;
                (*(this->p + k)).ShowBill();
                Clear(*(this->p + k));
                (this->p + k)->Motor.setIsRented(0);
            }
        }
    }
}
void List::ShowRented()
{
    if (this->length == 0)
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t---------------- KHONG CO XE MAY TRONG DANH SACH -----------------" << endl;
    else
    {

        cout << setw(20) << "\n\n\t\t\t\t\t\t\t\t\t\tDANH SACH XE VA TINH TRANG TRONG HE THONG" << endl;
        int j = 1;
        for (int i = 0; i < this->length; i++)
        {
            if ((*(this->p + i)).Motor.getIsRented())
            {
                cout << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t\tCustomer " << j << endl;
                (*(this->p + i)).Show();
                j++;
            }
        }
        cout << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------" << endl;
    }
}
void List::ShowRented(ofstream &o) //
{
    o.open("OUT.txt");
    if (this->length == 0)
        o << "\n\n\n\n\t\t\t\t\t\t\t\t\t---------------- KHONG CO XE MAY TRONG DANH SACH -----------------" << endl;
    else
    {

        o << setw(20) << "\n\n\t\t\t\t\t\t\t\t\t\tDANH SACH XE VA TINH TRANG TRONG HE THONG" << endl;
        int j = 1;
        for (int i = 0; i < this->length; i++)
        {
            if ((*(this->p + i)).Motor.getIsRented())
            {
                o << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------" << endl;
                o << "\t\t\t\t\t\t\t\tCustomer " << j << endl;
                (*(this->p + i)).Show(o);
                j++;
            }
        }
        o << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------" << endl;
    }
}
void List::ShowMotorNotRental()
{
    if (this->length == 0)
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t---------------- KHONG CO XE MAY TRONG DANH SACH -----------------" << endl;
    else
    {

        cout << setw(20) << "\n\n\t\t\t\t\t\t\t\t\t\tDANH SACH XE VA TINH TRANG TRONG HE THONG" << endl;
        int j = 1;
        for (int i = 0; i < this->length; i++)
        {
            if (!(*(this->p + i)).Motor.getIsRented())
            {
                cout << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t\tMotorbike " << j << endl;
                (*(this->p + i)).Show();
                ++j;
            }
        }
        cout << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------" << endl;
    }
}
int List::checkLicensePlates(Motorbike m)
{
    for (int i = 0; i < this->length; i++)
    {
        if ((this->p + i)->Motor.getLicensePlates().compare(m.getLicensePlates()) != 0)
        {
            continue;
        }
        else
            cout << "\n\n\t\t\t\t\t\t\t\t\tXe da co trong he thong! Vui long nhap lai!" << endl;
        return 0;
    }
    cout << "\n\n\t\t\t\t\t\t\t\t\tThem xe thanh cong!" << endl;
    return 1;
}
long long List::SumOfMoney()
{
    long long sum = 0;
    for (int i = 0; i < this->length; i++)
    {
        if ((this->p + i)->NumberOfDayRental > 0)
        {
            sum += (*(this->p + i)).GetMoney();
        }
    }
    return sum;
}
void List::ShowMotorUser()
{
    if (this->length == 0)
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t---------------- KHONG CO XE MAY TRONG DANH SACH -----------------" << endl;
    else
    {
        cout << setw(20) << "\n\n\t\t\t\t\t\t\t\t\t\tDANH SACH XE TRONG HE THONG" << endl;
        int j = 1;
        for (int i = 0; i < this->length; i++)
        {
            if (!(*(this->p + i)).Motor.getIsRented())
            {
                cout << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------" << endl;
                cout << "\t\t\t\t\t\t\t\tMotorbike " << j << endl;
                (*(this->p + i)).Motor.Show();
                ++j;
            }
        }
        cout << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------" << endl;
    }
}
void List::UpdatePrice(string LicensePlates)
{
    int n;
    int k = indexOf(LicensePlates);
    cout << "\n\t\tNhap gia xe muon cap nhat: ";
    cin >> n;
    (this->p + k)->Motor.setPrice(n);
    cout << "\n\n\t\t\t\t\t\t\t\t--------- Cap Nhat Thanh Cong ---------" << endl;
}
void List::UpdateDateRental(string LicensePlates)
{
    Date n;
    int k = indexOf(LicensePlates);
    if ((this->p + k)->Motor.getIsRented() == 0)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\tKhong co xe nao trong danh sach" << endl;
        return;
    }
    if (k == -1)
    {
        cout << "\n\n\t\t\t\t\t\t\t\t\t\tBien so khong dung!" << endl;
        return;
    }
    cout << "\n\t\tNhap ngay thue muon cap nhat: ";
    cin >> n;
    (this->p + k)->DateRental = n;
}
void List::Merge(List &t, int l, int m, int r, bool (*TypeOfSort)(int, int))
{
    int n1 = m - l + 1;
    int n2 = r - m;
    ThueXe *t1 = new ThueXe[n1];
    ThueXe *t2 = new ThueXe[n2];
    for (int i = 0; i < n1; i++)
    {
        *(t1 + i) = *(t.p + l + i);
    }
    for (int j = 0; j < n2; j++)
    {
        *(t2 + j) = *(t.p + m + 1 + j);
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (TypeOfSort((t1 + i)->Motor.getPrice(), (t2 + j)->Motor.getPrice()))
        {
            *(t.p + k) = *(t1 + i);
            i++;
        }
        else
        {
            *(t.p + k) = *(t2 + j);
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        *(t.p + k) = *(t1 + i);
        i++;
        k++;
    }
    while (j < n2)
    {
        *(t.p + k) = *(t2 + j);
        k++;
        j++;
    }
}
void List::MergeSort(List &t, int l, int r, bool (*Type)(int, int))
{
    if (l < r)
    {
        int m = (l + r) / 2;
        MergeSort(t, l, m, Type);
        MergeSort(t, m + 1, r, Type);
        Merge(t, l, m, r, Type);
    }
}
void List::MergeAdm(List &t, int l, int m, int r, bool (*TypeOfSort)(int, int))
{
    int n1 = m - l + 1;
    int n2 = r - m;
    ThueXe *t1 = new ThueXe[n1];
    ThueXe *t2 = new ThueXe[n2];
    for (int i = 0; i < n1; i++)
    {
        *(t1 + i) = *(t.p + l + i);
    }
    for (int j = 0; j < n2; j++)
    {
        *(t2 + j) = *(t.p + m + 1 + j);
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (TypeOfSort((t1 + i)->GetMoney(), (t2 + j)->GetMoney()))
        {
            *(t.p + k) = *(t1 + i);
            i++;
        }
        else
        {
            *(t.p + k) = *(t2 + j);
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        *(t.p + k) = *(t1 + i);
        i++;
        k++;
    }
    while (j < n2)
    {
        *(t.p + k) = *(t2 + j);
        k++;
        j++;
    }
}
void List::MergeSortAdm(List &t, int l, int r, bool (*Type)(int, int))
{
    if (l < r)
    {
        int m = (l + r) / 2;
        MergeSortAdm(t, l, m, Type);
        MergeSortAdm(t, m + 1, r, Type);
        MergeAdm(t, l, m, r, Type);
    }
}
bool checkYear(int year)
{
    if (year % 400 == 0)
        return true;
    if (year % 4 == 0 && year % 100 != 0)
        return true;
    return false;
}

void List::ShowOutOfDay()
{
    Date d = getTimeNow();
    int j = 1;
    cout << setw(20) << "\n\n\t\t\t\t\t\t\t\t\t\tDANH SACH KHACH HANG QUA HAN TRA XE" << endl;
    cout << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < this->length; i++)
    {
        int c = 1;
        if ((this->p + i)->Motor.getIsRented())
        {
            int day = (this->p + i)->DateRental.getDay();
            int month = (this->p + i)->DateRental.getMonth();
            int year = (this->p + i)->DateRental.getYear();
            day += (this->p + i)->NumberOfDayRental;
            if (checkYear(year))
            {
                if (day <= 29)
                {
                    if (day >= d.getDay())
                        c = 0;
                }
                else if (month == 2)
                {
                    month++;
                    day -= 29;
                }
            }
            else
            {

                if (month == 2)
                {
                    if (day > 28)
                    {
                        month++;
                        day -= 28;
                    }
                }
                if (day > 31)
                {

                    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                    {
                        month++;
                        day -= 31;
                    }
                }
                if (day > 30)
                {
                    if (month == 4 || month == 6 || month == 9 || month == 11)
                    {
                        month++;
                        day -= 30;
                    }
                }
            }
            if (month == 13)
            {
                month = 1;
                year += 1;
            }
            // cout << day << "/" << month << "/" << year << endl;
            if (year > d.getYear())
                continue;
            if (year < d.getYear())
            {
                cout << "\t\t\t\t\t\t\t\tCustomer " << j << endl;
                (*(this->p + i)).Show();
                j++;
                continue;
            }
            if (month < d.getMonth())
            {
                cout << "\t\t\t\t\t\t\t\tCustomer " << j << endl;
                (*(this->p + i)).Show();
                j++;
                continue;
            }
            if (day < d.getDay())
            {
                cout << "\t\t\t\t\t\t\t\tCustomer " << j << endl;
                (*(this->p + i)).Show();
                j++;
                continue;
            }
        }
    }
    cout << "\t\t\t\t\t\t\t------------------------------------------------------------------------------------" << endl;
}