#include <iostream>
#include <windows.h>
using namespace std;
void gotoxy(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

class Point  
{  
private:  
   int x;  
   int y;  
public:  
   Point(): x(0), y(0){}  
   Point(int X, int Y)  
   {  
       x = X;  
       y = Y;  
   }  
   void Show()  
   {  
       cout << "X : " << x << endl;  
       cout << "Y : " << y << endl;  
   }  
   Point operator ++()  
   {  
      x += 1;  
      y += 1;  
      return *this; 
   }
   Point operator --()  
   {  
       x -= 1;  
       y -= 1;  
       return *this;
   }  
   Point operator !()  
   {  
       x *= -1;  
       y *= -1;  
       return *this;
   }  
   bool operator >(Point o)  
   {  
       int dist1 = x * x + y * y;  
       int dist2 = o.x * o.x + o.y * o.y;  
       return dist1 > dist2;  
   }  
   bool operator <(Point o)  
   {  
       int dist1 = x * x + y * y;  
       int dist2 = o.x * o.x + o.y * o.y;  
       return dist1 < dist2;  
   }  

   // Add public getter methods for x and y  
   int getX() const { return x; }  
   int getY() const { return y; }  
};  

class Vector {  
private:  
   Point* points;  
   int count;  
public:  
   Vector() : points(nullptr), count(0) {}  
  
   void Print() const {  
       for (int i = 0; i < count; ++i) {  
           gotoxy(points[i].getX(), points[i].getY());  
           cout << "*";  
       }  
   }  
   void Add(const Point& p) {
       Point* newPoints = new Point[count + 1];
       for (int i = 0; i < count; ++i) {
           newPoints[i] = points[i];
       }
       newPoints[count] = p;
       delete[] points;
       points = newPoints;
       ++count;
   }
   Vector& operator=(const Vector& other) {
       if (this == &other) return *this;
       delete[] points;
       count = other.count;
       points = nullptr;
       if (count > 0) {
           points = new Point[count];
           for (int i = 0; i < count; ++i)
               points[i] = other.points[i];
       }
       return *this;
   }
   ~Vector() {
       delete[] points;
   }
};

int main()
{
    Point p1(5, 5);
    Point p2(2, 1);
    !p1;
    p1.Show();
    int test = p1 > p2;
    cout << test;
    Vector v;
    Vector v1;
    v.Add(Point(5, 5));
    v.Add(Point(10, 10));
    v.Add(Point(20, 3));
    v1 = v;
    v1.Print();
}