#include"ThueXe.h"
#include <fstream>
class List
{
private:
    ThueXe *p;
    int length;
public:
    List();
    List(ThueXe*, int);
    List(const List&);
    ~List();
    List operator=(const List&);
    bool checkCmnd( Person&);
    void Add(Motorbike&);
    void UpdateRental(int ); //n la so luong xe muon thue;
    void Display();
    void EnterList();
    void ShowListMotor();
    int indexOf(string);
    int indexOf(int);
    int indexOfCarReturn(string);
    void Find(string);
    void FindCompany(string);
    void UpdateAfterReturn(int);
    void Clear(ThueXe&);
    void Delete(string);
    void ShowRented();
    void ShowRented(ofstream&); //
    void ShowMotorNotRental();
    int checkLicensePlates(Motorbike);
    Motorbike EnterMotor(Motorbike m);
    long long SumOfMoney();
    void Sort();
    void ShowMotorUser();
    void FindUser(string, int&);
    void FindUser(int, int &);
    void UpdatePrice(string );
    void UpdateDateRental(string);
    void Merge(List&, int, int, int, bool (*) (int, int));
    void MergeSort(List&, int, int, bool (*)(int, int));
    void MergeAdm(List&, int, int, int, bool (*) (int, int));
    void MergeSortAdm(List&, int, int, bool (*)(int, int));
    int getLength();
    friend bool checkDateRental(Date, Date);
    void ShowOutOfDay();
};

