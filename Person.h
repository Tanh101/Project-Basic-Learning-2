#include<iostream>
using namespace std;
class Person
{
private:
    string CMND;
    string Name;
    int Age;
    string Address;
    string PhoneNumber;
public:
    Person(string = "", string = "", int = 0, string = "", string = "");
    Person(const Person&);
    ~Person();
    void Show();
    void Show(ofstream &);
    int getAge();
    string getName();
    string getCmnd();
    void setName(string );
    void setAge(int);
    void setCmnd(string);
    friend ostream& operator<<(ostream&, const Person&);
    friend istream& operator>>(istream&, Person&);
};


