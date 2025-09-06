#include <iostream>
#include <string>
using namespace std;

class Student {
    int age;
    string name;
    string lastname;
    string bdate;
    string course;
    string stream;
public:
    
    Student() : age(0), name("no name"), lastname("no last name"), bdate("no birth date"), course("no course"), stream("no stream") {};
    Student(int a, string n, string ln, string b, string c, string s): age(a), name(n), lastname(ln), bdate(b), course(c), stream(s) {};
    ~Student() {};

    void Show() {
        cout << "Name: " << name << " " << lastname << endl;
        cout << "Age: " << age << endl;
        cout << "Birthdate: " << bdate << endl;
        cout << "Course: " << course << ", Stream: " << stream << endl;
    };
};

class Aspirant : public Student {
    string work;
public:
    Aspirant() : Student(), work("") {};

    Aspirant(int a, string n, string ln, string b, string c, string s, string w): Student(a, n, ln, b, c, s), work(w) {};

    void Show() {
        Student::Show();
        cout << "Research Work: " << work << endl;
    };
};

class Passport {
    string name;
    string lastname;
    string middlename;
    string gender;
    string bdate;
    string exp_date;
    string nationality;
    int ID;
    string issue_date;
    int authority;
public:
    Passport() : ID(0), authority(0) {};

    Passport(string n, string ln, string mn, string g, string bd, string exp, string nat, int id, string issue, int auth)
        : name(n), lastname(ln), middlename(mn), gender(g), bdate(bd),
        exp_date(exp), nationality(nat), ID(id), issue_date(issue), authority(auth) {};

    void display()
    {
        cout << "Passport Holder: " << name << " " << middlename << " " << lastname << endl;
        cout << "Gender: " << gender << ", DOB: " << bdate << endl;
        cout << "Nationality: " << nationality << ", Passport ID: " << ID << endl;
        cout << "Issued: " << issue_date << ", Expires: " << exp_date << endl;
        cout << "Authority Code: " << authority << endl;
    };
};

class InterPassport : public Passport {
    int visa;
public:
    InterPassport() : Passport(), visa(0) {};

    InterPassport(string n, string ln, string mn, string g, string bd, string exp, string nat, int id, string issue, int auth, int v)
        : Passport(n, ln, mn, g, bd, exp, nat, id, issue, auth), visa(v) {};

    void display()
    {
        Passport::display();
        cout << "Visa Status Code: " << visa << endl;
    };
};
int main()
{
    Student s;
    Aspirant a;
    Passport p;
    InterPassport ip;
}

