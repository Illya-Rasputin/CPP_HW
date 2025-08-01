#include <iostream>
using namespace std;
template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    ~List() {
        while (head != nullptr) {
            RemoveFromHead();
        }
    }

    void AddToHead(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        if (tail == nullptr) tail = head;
        ++size;
    }

    void AddToTail(const T& value) {
        Node* newNode = new Node(value);
        if (tail != nullptr)
            tail->next = newNode;
        tail = newNode;
        if (head == nullptr)
            head = tail;
        ++size;
    }

    void RemoveFromHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
        --size;
        if (head == nullptr) tail = nullptr;
    }

    void Print() const {
        Node* current = head;
        while (current != nullptr) {
            current->data.Print();
            current = current->next;
        }
    }

    int GetSize() const {
        return size;
    }
};

class Point {
private:
    int x;
    int y;
public:
    Point(int xVal = 0, int yVal = 0) : x(xVal), y(yVal) {}
    void Print() const {
        cout << "(" << x << ", " << y << ")\n";
    }
};

class Vector {
private:
    List<Point> points;

public:
    Vector() {}

    void AddPointToStart(const Point& p) {
        points.AddToHead(p);
    }

    void AddPointToEnd(const Point& p) {
        points.AddToTail(p);
    }

    void RemoveFirstPoint() {
        points.RemoveFromHead();
    }

    void Print() const {
        cout << "Points in Vector:\n";
        points.Print();
    }
};


int main()
{
    Vector v;

    v.AddPointToEnd(Point(3, 4));
    v.AddPointToStart(Point(1, 2));
    v.AddPointToEnd(Point(5, 6));

    v.Print();

    cout << "\nAfter removing the first point:\n";
    v.RemoveFirstPoint();
    v.Print();
}

