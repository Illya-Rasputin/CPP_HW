#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Student 
{
private:
    string fullName;
    string birthDate;
    string phone;
    string city;
    string country;
    string uniName;
    string uniCity;
    string uniCountry;
    string groupNumber;
public:
    void inputData() {
        cout << "Full Name: ";
        getline(cin, fullName);
        cout << "Birth Date (dd.mm.yyyy): ";
        getline(cin, birthDate);
        cout << "Contact Phone: ";
        getline(cin, phone);
        cout << "City of Residence: ";
        getline(cin, city);
        cout << "Country of Residence: ";
        getline(cin, country);
        cout << "University Name: ";
        getline(cin, uniName);
        cout << "University City: ";
        getline(cin, uniCity);
        cout << "University Country: ";
        getline(cin, uniCountry);
        cout << "Group Number: ";
        getline(cin, groupNumber);
    }

    void showData() const {
        cout << "\nStudent Information:\n";
        cout << "Full Name: " << fullName << "\n";
        cout << "Birth Date: " << birthDate << "\n";
        cout << "Phone: " << phone << "\n";
        cout << "City: " << city << "\n";
        cout << "Country: " << country << "\n";
        cout << "University Name: " << uniName << "\n";
        cout << "University City: " << uniCity << "\n";
        cout << "University Country: " << uniCountry << "\n";
        cout << "Group Number: " << groupNumber << "\n";
    }

    string getFullName() const { return fullName; }
    string getBirthDate() const { return birthDate; }
    string getPhone() const { return phone; }
    string getCity() const { return city; }
    string getCountry() const { return country; }
    string getUniName() const { return uniName; }
    string getUniCity() const { return uniCity; }
    string getUniCountry() const { return uniCountry; }
    string getGroupNumber() const { return groupNumber; }

    void setFullName(string name) 
    {
        fullName = name;
    }
    void setBirthDate(string date) 
    {
        birthDate = date;
    }
    void setPhone(string ph) 
    {
        phone = ph;
    }
    void setCity(string c) 
    {
        city = c;
    }
    void setCountry(string c)
    {
        country = c; 
    }
    void setUniName(string name)
    {
        uniName = name; 
    }
    void setUniCity(string c)
    { 
        uniCity = c;
    }
    void setUniCountry(string c)
    {
        uniCountry = c; 
    }
    void setGroupNumber(string num)
    { 
        groupNumber = num; 
    }
};

class Point
{
private:
    int x;
    int y;
    int z;
public:
    void Input()
    {
        cout << "Enter X : "; cin >> x;
        cout << "Enter Y : "; cin >> y;
        cout << "Enter Z : "; cin >> z;
    }
    void Show()
    {
        cout << "X = " << x << endl;
        cout << "Y = " << y << endl;
        cout << "Z = " << z << endl;
    }

    int getX() { return x; }
    int getY() { return y; }
    int getZ() { return z; }

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setZ(int z) { this->z = z; }

    void saveToFile(string filename)
    {
        ofstream fout(filename);
        if (!fout.is_open()) {
            cout << "Error: cannot open file " << filename << " for writing." << endl;
            return;
        }
        fout << x << "\n" << y << "\n" << z;
        fout.close();
        cout << "Saved" << endl;
    }
    void loadFromFile(string filename)
    {
        ifstream fin(filename);
        if (!fin.is_open()) {
            cerr << "Error: cannot open file " << filename << endl;
            return;
        }
        fin >> x;
        fin >> y;
        fin >> z;
        fin.close();
        cout << "Loaded" << endl;
    }
};

int main()
{
    /*Student student;
    student.inputData();
    student.showData();

    cout << "\nStudent's name is: " << student.getFullName() << endl;
    student.setGroupNumber("NPD411");
    student.showData();*/
    Point p;
    p.Input();
    p.Show();
    cout << "Points x = " << p.getX() << endl;
    p.saveToFile("Point.txt");
    p.setY(5);
    p.Show();
    p.loadFromFile("Point.txt");
    p.Show();
}

