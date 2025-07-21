#include <iostream>
#include <string>
using namespace std;

class Abonent
{
private:
    string name;
    string homenumber;
    string worknumber;
    string phonenumber;
public:
    Abonent()
    {
		name = "Unknown";
		homenumber = "Unknown";
		worknumber = "Unknown";
		phonenumber = "Unknown";
    }
	Abonent(string n, string h, string w, string p)
	{
		name = n;
		homenumber = h;
		worknumber = w;
		phonenumber = p;
	}
	void input()
	{
		cout << "Enter name: ";
		getline(cin, name);
		cout << "Enter home number: ";
		getline(cin, homenumber);
		cout << "Enter work number: ";
		getline(cin, worknumber);
		cout << "Enter phone number: ";
		getline(cin, phonenumber);
	}
	void show() const
	{
		cout << "Name: " << name << endl;
		cout << "Home Number: " << homenumber << endl;
		cout << "Work Number: " << worknumber << endl;
		cout << "Phone Number: " << phonenumber << endl;
	}
	string getName() const { return name; }
	string getHomeNumber() const { return homenumber; }
	string getWorkNumber() const { return worknumber; }
	string getPhoneNumber() const { return phonenumber; }
	void setName(const string& n) { name = n; }
	void setHomeNumber(const string& h) { homenumber = h; }
	void setWorkNumber(const string& w) { worknumber = w; }
	void setPhoneNumber(const string& p) { phonenumber = p; }

};

class PhoneBook  
{  
private:  
Abonent* abonents;  
int countAbonent;  
const int limit = 100;

public:  
PhoneBook()  : abonents(nullptr), countAbonent(0) 
{
}  

void Add(const Abonent& a) 
{  
	if (countAbonent >= limit) 
	{  
		cout << "PhoneBook is full. Cannot add more abonents.\n";  
		return;  
	}  
	Abonent* newAbonents = new Abonent[countAbonent + 1];  
	for (int i = 0; i < countAbonent; ++i)  
		newAbonents[i] = abonents[i];  
	newAbonents[countAbonent] = a;  
	delete[] abonents;  
	abonents = newAbonents;  
	countAbonent++;  
}  

void Delete(const string& phone)   
{  
	if (countAbonent <= 0) 
	{  
		cout << "PhoneBook is empty. Cannot delete abonents.\n";  
		return;  
	}  
	int index = -1;  
	for (int i = 0; i < countAbonent; ++i) {  
		if (abonents[i].getPhoneNumber() == phone) {  
			index = i;  
			break;  
		}  
	}  
	if (index == -1) {  
		cout << "Abonent not found.\n";  
		return;  
	}  
	Abonent* newAbonents = new Abonent[countAbonent - 1];  
	for (int i = 0, j = 0; i < countAbonent; ++i) {  
		if (i != index) {  
			newAbonents[j++] = abonents[i];  
		}  
	}  
	delete[] abonents;  
	abonents = newAbonents;  
	countAbonent--;  
}  

void SearchByName(const string& name) const   
{  
	for (int i = 0; i < countAbonent; ++i) {  
		if (abonents[i].getName() == name) {  
			abonents[i].show();  
			return;  
		}  
	}  
	cout << "Abonent not found.\n";  
}  

void SearchByPhone(const string& phone) const  
{  
	for (int i = 0; i < countAbonent; ++i) {  
		if (abonents[i].getPhoneNumber() == phone) {  
			abonents[i].show();  
			return;  
		}  
	}  
	cout << "Abonent not found.\n";  
}  

void ShowAll() const 
{  
	if (countAbonent == 0) {  
		cout << "No abonents in the phone book.\n";  
		return;  
	}  
	for (int i = 0; i < countAbonent; ++i) {  
		abonents[i].show();  
		cout << "-------------------\n";  
	}  
}  

~PhoneBook()  
{  
	delete[] abonents;  
}  
};


int main()
{
	Abonent abonent;
	abonent.input();
	cout << "\nAbonent Details:\n";
	abonent.show();
	abonent.setName("John Doe");
	abonent.setHomeNumber("123-456-7890");
	abonent.setWorkNumber("098-765-4321");
	abonent.setPhoneNumber("555-555-5555");
	cout << "\nUpdated Abonent Details:\n";
	abonent.show();
	PhoneBook phoneBook;
	phoneBook.Add(abonent);
	Abonent abonent2("Alice", "111-222-3333", "444-555-6666", "777-888-9999");
	phoneBook.Add(abonent2);
	phoneBook.ShowAll();
	phoneBook.SearchByName("John Doe");
	phoneBook.SearchByPhone("555-555-5555");
	phoneBook.Delete("555-555-5555");
	phoneBook.ShowAll();
}

