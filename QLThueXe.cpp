#include "List.h"
#include <iostream>
#include <windows.h>
#include <conio.h>

void set_color(int code)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, code);
}
bool ASC(int a, int b)
{
    return a < b;
}
bool DESC(int a, int b)
{
    return a > b;
}
void PriceTable()
{
    system("cls");
    cout << "\n\n\t\t\t\t\t\t\t\t\tBANG GIA THUE XE MAY CUA CONG TY HOMESTAY THEO SO PHAN KHOI" << endl;
    cout << "\n\n";
    cout << "\t------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------";
    cout << "\t\t\t\t\t   So Phan Khoi\t|\t\t\t   50 (CC)"
         << "\t\t\t|\t\t   50 < X <= 125 (CC)";
    cout << "\t\t\t|\t125 < X <= 175 (CC)\n";
    cout << "\t------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------";
    cout << "\t\t\t\t\t   Gia thue\t|\t\t     60000 (VND/Ngay)"
         << "\t\t\t|\t\t  80000 - 100000 (VND/Ngay)";
    cout << "\t\t|\t100000 - 130000 (VND/Ngay)\n";
    cout << "\t------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------\n\n\n\n";
    cout << endl;
}
void QuyDinh()
{
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tHOMESTAY Kinh chao quy khach" << endl;
    cout << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\tDUOI DAY LA QUY DINH THUE XE MAY O HOMESTAY" << endl;
    cout << endl;
    cout << "\t------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------"
         << endl;
    cout << "\n\t\t\t\t\t1. Cong ty HOMETAY cho thue xe may theo ngay, va quy khach vui long lua chon truoc so ngay muon thue"
         << "\n\n\t\t\t\t\t2. Khi tien hanh thue xe, quy khach vui long thanh toan truoc hoa don thue xe" << endl;
    cout << "\n\t\t\t\t\t3. Xem ki bien so, mau son co trung voi hoa don thue xe hay khong"
         << "\n\n\t\t\t\t\t4. Kiem tra chat luong xe truoc khi thue" << endl;
    cout << "\n\t\t\t\t\t5. Khach hang phai mang theo giay to tuy than va ban Photo giay phep lai xe"
         << "\n\n\t\t\t\t\t6. Moi khach hang chi duoc phep thue 1 xe, va thue toi da trong 30 ngay" << endl;
    cout << endl;
    cout << "\t------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------"
         << endl;
    cout << endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t   Cam on quy khach!" << endl;
}
void MenuUser()
{
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tDICH VU CUNG CAP XE MAY DU LICH HOMESTAY" << endl;
    cout << endl;
    cout << "\t------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------"
         << endl;
    cout << "\t\t1. Gia thue xe may o HOMESTAY"
         << "\t\t\t\t\t\t\t|\t\t\t\t2. Hien Thi tat ca xe chua thue trong he thong" << endl;
    cout << endl;
    cout << "\t\t3. Thue Xe"
         << "\t\t\t\t\t\t\t\t\t|\t\t\t\t4. Tim kiem xe theo bien so" << endl;
    cout << endl;
    cout << "\t\t5. Tim kiem xe may theo so phan khoi"
         << "\t\t\t\t\t\t|\t\t\t\t6. Sap xep gia xe tang dan" << endl;
    cout << endl;
    cout << "\t\t7. Sap xep xe theo gia xe giam dan"
         << "\t\t\t\t\t\t|\t\t\t\t0. Thoat che do User" << endl;
    cout << "\t------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------";
    cout << endl;
}
/*
g++ -std=c++14 List.cpp Person.cpp Date.cpp ThueXe.cpp Motorbike.cpp QLThueXe.cpp -o a
*/
void MenuAdmin()
{
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tTrang quan li danh cho ADMIN" << endl;
    cout << endl;
    cout << "\t------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------"
         << endl;
    cout << "\t\t1. Nhap danh sach xe may co the cung cap cho khach hang"
         << "\t\t\t\t|\t\t2. Hien Thi tat ca thong tin khach hang da thue xe" << endl;
    cout << endl;
    cout << "\t\t3. Them xe may moi vao danh sach"
         << "\t\t\t\t\t\t|\t\t4. Hien thi tat ca thong tin ve xe may trong he thong" << endl;
    cout << endl;
    cout << "\t\t5. Tim kiem xe may va xuat thong tin xe may"
         << "\t\t\t\t\t|\t\t6. Sap xep tang dan theo tien thue xe cua khach hang" << endl;
    cout << endl;
    cout << "\t\t7. Hien thi danh sach cac xe chua duoc thue"
         << "\t\t\t\t\t|\t\t8. Sap xep giam dan theo tien thue xe cua khach hang" << endl;
    cout << endl;
    cout << "\t\t9. Tong doanh thu cua cua hang"
         << "\t\t\t\t\t\t\t|\t\t10. Hien Thi Danh Sach Xe May" << endl;
    cout << endl;
    cout << "\t\t11. Cap nhat danh sach sau khi khach hang tra xe"
         << "\t\t\t\t|\t\t12. Cap nhat gia thue xe" << endl;
    cout << endl;
    cout << "\t\t13. Xoa 1 xe khoi he thong"
         << "\t\t\t\t\t\t\t|\t\t14. Chinh sua ngay thue xe cua khach hang" << endl;
    cout << endl;
    cout << "\t\t15. Hien Thi danh sach khach hang qua han tra xe"
         << "\t\t\t\t|\t\t0. Thoat che do Admin" << endl;
    cout << endl;
    cout << "\t------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------";
    cout << endl;
}
/*
g++ -std=c++14 List.cpp Person.cpp Date.cpp ThueXe.cpp Motorbike.cpp QLThueXe.cpp -o a
*/

void Page()
{
    system("cls");
    set_color(2);
    cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t-------------- PBL2: DU AN CO SO LAP TRINH --------------";
    cout << "\n\n\n\n\t\t\t\t\t\t\t\tDE TAI : \tQUAN LI CHO THUE XE MAY DU LICH CUA CONG TY HOMESTAY\n\n"
         << endl;
    set_color(3);
    cout << "\n\n\n\n\t\t\t\t\t|---------------------------------------------------------------------------------------------------------------------|";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\tGiang Vien Huong Dan:\t\t\t\tThS. Phanh Thanh Tao\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\tNhom SV Thuc Hien:\t\t\t\tLy Van Tanh\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\tNguyen Khac Thai\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t\t\t\t\t      |";
    cout << "\n\t\t\t\t\t|---------------------------------------------------------------------------------------------------------------------|\n\n\n";
    cout << endl;
    system("pause");
    system("cls");
}
string PassWord()
{
    string pw;
    for (char c; (c = getch());)
    {
        if (c == '\n' || c == '\r')
        { // phím enter
            cout << "\n";
            break;
        }
        else if (c == '\b')
        { // phím backspace
            cout << "\b \b";
            if (pw.length() != 0)
                pw.erase(pw.size() - 1);
        }
        else if (c == -32)
        {             // phím mũi tên
            _getch(); // bỏ qua kí tự tiếp theo (hướng mũi tên)
        }
        else
        {
            cout << '*';
            pw += c;
        }
    }
    return pw;
}
int Login()
{
    set_color(13);
    system("cls");
    cout << "\n\n\n\t\t\t\t\t\t\t\t\tCHAO MUNG BAN DEN VOI DICH VU CUNG CAP XE MAY DU LICH HOMESTAY" << endl;
    cout << "\n\n";
    cout << "\t|------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------|"
         << endl;
    cout << "\t|\t\t\t1. Nguoi Dung"
         << "\t\t\t|\t\t\t2. Quan Tri Vien";
    cout << "\t\t\t|\t\t\t 0. Thoat";
    cout << "\t\t\t  |";
    cout << endl;
    cout << "\t|------------------------------------------------------------------------"
            "----------------------------------------------------------------------------"
            "-----------------------------|";
    cout << endl;
    int lc;
    do
    {
        cout << "\n\n\n\t\t\t\t\tNhap lua chon cua ban: ";
        cin >> lc;
    } while (lc < 0 || lc > 2);
    string acc = "admin";
    string pwd = "admin12";
    string accInput, pass;
    int check;
    switch (lc)
    {
    case 0:
        return 3;
        break;
    case 1:
        return 1;
        break;
    case 2:
        do
        {
            set_color(2);
            cout << "\n\t\t\t\t\t\t\t\tTai khoan: ";
            cin >> accInput;
            cout << "\n\t\t\t\t\t\t\t\tMat Khau: ";
            pass = PassWord();
            if (pass.compare(pwd) == 0 && accInput.compare(acc) == 0)
            {
                check = 1;
                return 2;
            }
            else
            {
                check = 0;
                system("cls");
                set_color(12);
                cout << "\n\n\n\t\t\t\t\tSai Tai Khoan Hoac Mat Khau! Vui long nhap lai" << endl;
            }
        } while (!check);
        break;
    }
}
void ShowAdmin(List &t)
{
    int n;
    ofstream o;//
    o.open("OUT.txt");//
    string bienSo1;
    List tmp;
    char ch;
    int choice;
    do
    {
        set_color(10);
        system("cls");
        MenuAdmin();
        cout << "\n\t\t\tNhap lua chon cua ban: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            try
            {
                t.EnterList();
            }
            catch (exception &e)
            {
                cout << "\n\n\n\n\t\t\t\t\t------------LOI XAY RA KHI DOC DU LIEU TU FILE!----------" << endl;
            }
            system("pause");
            break;
        case 2:
            system("cls");
            t.ShowRented();
            system("pause");
            break;
        case 3:
            int NumberOfRental;
            cout << "\n\t\tNhap so xe muon them: ";
            cin >> NumberOfRental;
            if (NumberOfRental < 1)
                break;
            cin.ignore();

            do
            {
                cout << "\n\t\tNhap thong tin xe: " << endl;
                Motorbike motor;
                do
                {

                    cin >> motor;
                } while (!t.checkLicensePlates(motor));
                t.Add(motor);
                NumberOfRental--;
            } while (NumberOfRental);
            break;
        case 4:
            set_color(15);
            t.Display();
            system("pause");
            break;
        case 5:
            cout << "\n\t\tNhap vao bien so xe can tim kiem: ";
            cin >> bienSo1;
            t.Find(bienSo1);
            system("pause");
            break;
        case 6:
            tmp = t;
            t.MergeSortAdm(tmp, 0, tmp.getLength() -1, ASC);//tang dan
            tmp.ShowRented();
            system("pause");
            break;
        case 7:
            t.ShowMotorUser();//danh sach chua dc thue
            system("Pause");
            break;
        case 8:
            tmp = t;
            t.MergeSortAdm(tmp, 0, tmp.getLength() -1, DESC);//giam dan
            tmp.ShowRented();
            system("pause");
            break;
        case 9:
            set_color(14);
            cout << "\n\n\t\t\t\t\t\t\t\t\t\tTong doanh thu: " << t.SumOfMoney() << endl;
            system("pause");
            break;
        case 10:
            set_color(7);
            t.ShowListMotor();
            system("pause");
            break;
        case 11:
            set_color(11);
            cout << "\n\t\tNhap so xe can cap nhat la da tra trong he thong: ";
            cin >> n;
            t.UpdateAfterReturn(n);
            system("pause");
            break;
        case 12:
            set_color(3);
            t.ShowMotorNotRental();
            cout << "\n\t\tNhap bien so xe: ";
            cin >> bienSo1;
            t.UpdatePrice(bienSo1);
            system("pause");
            break;
        case 13:
            set_color(7);
            t.ShowMotorNotRental();
            cout << "\n\t\tNhap bien so xe: ";
            cin >> bienSo1;
            t.Delete(bienSo1);
            system("pause");
            break;
        case 14:
            set_color(10);
            t.ShowRented();
            cout << "\n\t\tNhap vao bien so xe: ";
            cin >> bienSo1;
            t.UpdateDateRental(bienSo1);
            system("pause");
            break;
        case 15:
            set_color(10);
            t.ShowOutOfDay();
            system("pause");
            break;
        case 16:
            set_color(10);
            t.ShowRented(o);
            system("pause");
            break;
        case 0:
            break;
        default:
            break;
        }
    } while (choice != 0);
}
void ShowUser(List &t)
{
    int c;
    int typeOfCar;
    char rental;
    system("cls");
    set_color(11);
    QuyDinh();
    system("pause");
    string bienSo1;
    char ch;
    int choice;
    List tmp;
    do
    {
        set_color(3);
        system("cls");
        MenuUser();
        set_color(7);
        cout << "\n\t\t\tNhap lua chon cua ban: ";
        set_color(3);
        cin >> choice;
        switch (choice)
        {
        case 1:
            set_color(6);
            PriceTable();
            system("pause");
            break;
        case 2:

            set_color(7);
            system("cls");
            t.ShowMotorUser();
            system("pause");
            break;
        case 3:
            set_color(7);
            system("cls");
            int n;
            t.ShowMotorUser();
            t.UpdateRental(1);
            system("pause");
            break;
        case 4:
            cout << "\n\t\tNhap vao bien so xe can tim kiem: ";
            cin >> bienSo1;
            t.FindUser(bienSo1, c);
            if (c)
            {
                set_color(4);
                cout << "Ban co muon thue xe khong ? C/K : ";
                set_color(3);
                cin >> rental;
                if (rental == 'C' || rental == 'c')
                    t.UpdateRental(1);
            }
            system("pause");
            break;
        case 5:
            cout << "\n\t\tNhap vao so phan khoi can tim kiem: ";
            cin >> typeOfCar;
            t.FindUser(typeOfCar, c);
            if (c)
            {
                set_color(4);
                cout << "Ban co muon thue xe khong ? C/K : ";
                cin >> rental;
                set_color(3);
                if (rental == 'C' || rental == 'c')
                    t.UpdateRental(1);
            }
            system("pause");
            break;
        case 6:
            tmp = t;
            t.MergeSort(tmp, 0, tmp.getLength() - 1, ASC);
            set_color(7);
            tmp.ShowMotorUser();
            system("pause");
            break;
        case 7:
            tmp = t;
            t.MergeSort(tmp, 0, tmp.getLength() - 1, DESC);
            set_color(7);
            tmp.ShowMotorUser();
            system("pause");
            break;
        case 0:
            break;
        default:
            break;
        }
    } while (choice != 0);
}
int main()
{
    Page();
    List t;
    int key;
    do
    {
        key = Login();
        switch (key)
        {
        case 1:
            ShowUser(t);
            break;
        case 2:
            ShowAdmin(t);
            break;
        case 3:
            break;
        }
    } while (key != 3);
    return 0;
}
