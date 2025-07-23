#include <iostream>  
#include <string>  
using namespace std;  

class Plane  
{  
private:  
   string model;  
   string type;  
   int pass;  
   int cap;  
public:  
   Plane()  
   {  
       model = "None";  
       type = "None";  
       pass = 0;  
       cap = 0;  
   }  
   Plane(string m, string t, int p, int c)  
   {  
       if (c < p)
       {
           cout << "Too little capacity";
           return;
       }
       model = m;  
       type = t;  
       pass = p;
       cap = c;  
   }  
   void input()
   {
       cout << "Enter the model: "; getline(cin, model);
       cout << "Enter the type: "; getline(cin, type);
       cout << "Enter amount of passangers: "; cin >> pass;
       cout << "Enter capacity: "; cin >> cap;
       if (cap < pass)
       {
           pass = cap;
       }
   }
   void show()
   {
       cout << "Model: " << model << endl;
       cout << "Type: " << type << endl;
       cout << "Amount of passangers: " << pass << endl;
       cout << "Capasity: " << cap << endl;
   }

   bool operator ==(Plane o)  
   {  
       return ((this->type) == (o.type));  
   }  
   bool operator <(Plane o)  
   {  
       return ((this->cap) < (o.cap));  
   }  
   bool operator >(Plane o)  
   {  
       return ((this->cap) > (o.cap));  
   }  
   Plane& operator ++()  
   {  
       if (pass == cap)  
       {  
           cout << "Overboarding!" << endl;  
       }  
       else { pass += 1; }  
       return *this;  
   }  
   Plane& operator --()  
   {  
       if (pass == 0)  
       {  
           cout << "There are 0 passengers" << endl;  
       }  
       else { pass -= 1; }  
       return *this;  
   }  
   Plane& operator +(int value)  
   {  
       int temp = pass;  
       if ((pass + value) > cap)  
       {  
           cout << "Overboarding! " << (pass + value) - cap << " left behind" << endl;
           pass += cap - temp; 
       }  
       else { pass += value; }  
       return *this;  
   }  

   Plane& operator -(int value)  
   {  
       int temp = pass;  
       if ((pass - value) < 0)  
       {  
           pass = 0;  
           cout << "Too few passengers! Only " << (pass - value) * -1 << " left the plane" << endl;  
       }  
       else { pass -= value; }  
       return *this;  
   }  

   void getPass() { cout << pass; }
};  

int main()  
{  
   Plane p1("eee", "cargo", 0, 40);
   Plane p2("eaew", "cargo", 20, 40);

   int test;
   test = p1 > p2;
   cout << test << endl;
   ++p1;
   p1.getPass();
}
