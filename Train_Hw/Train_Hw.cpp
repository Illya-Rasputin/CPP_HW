#include <iostream>
#include <string>
using namespace std;
template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& d) : data(d), next(nullptr), prev(nullptr) {}
    };

    Node* head;
    Node* tail;
    int size;

    void CopyFrom(const List<T>& other) {
        Node* current = other.head;
        while (current != nullptr) {
            AddToTail(current->data);
            current = current->next;
        }
    }

public:
    List() : head(nullptr), tail(nullptr), size(0) {}

    List(const List<T>& other) : head(nullptr), tail(nullptr), size(0) {
        CopyFrom(other);
    }

    ~List() {
        while (head != nullptr) {
            DeleteFromHead();
        }
    }

    void AddToHead(const T& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        head = newNode;
        if (tail == nullptr)
            tail = head;
        ++size;
    }

    void AddToTail(const T& value) {
        Node* newNode = new Node(value);
        newNode->prev = tail;
        if (tail != nullptr)
            tail->next = newNode;
        tail = newNode;
        if (head == nullptr)
            head = tail;
        ++size;
    }

    void DeleteFromHead() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
        --size;
    }

    void DeleteFromTail() {
        if (tail == nullptr) return;
        Node* temp = tail;
        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
        --size;
    }

    void AddAtPosition(int pos, const T& value) {
        if (pos <= 0) {
            AddToHead(value);
        }
        else if (pos >= size) {
            AddToTail(value);
        }
        else {
            Node* current = head;
            for (int i = 0; i < pos; ++i)
                current = current->next;

            Node* newNode = new Node(value);
            newNode->next = current;
            newNode->prev = current->prev;
            current->prev->next = newNode;
            current->prev = newNode;
            ++size;
        }
    }

    void DeleteAtPosition(int pos) {
        if (pos < 0 || pos >= size) return;
        if (pos == 0) {
            DeleteFromHead();
        }
        else if (pos == size - 1) {
            DeleteFromTail();
        }
        else {
            Node* current = head;
            for (int i = 0; i < pos; ++i)
                current = current->next;

            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
            --size;
        }
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

struct Vagon {
    int num;
    int pass;
    int cap;

    void Print() const {
        cout << "Vagon #" << num << " | Passengers: " << pass << " | Capacity: " << cap << endl;
    }
};
class Train {
private:
    string model;
    int countVagons;
    List<Vagon> vagons;

public:
    Train() : model(""), countVagons(0) {}

    Train(const string& m, const List<Vagon>& v) : model(m), vagons(v), countVagons(v.GetSize()) {}

    Train(const Train& other) : model(other.model), vagons(other.vagons), countVagons(other.countVagons) {}

    void AddVagonToHead(const Vagon& v) {
        vagons.AddToHead(v);
        ++countVagons;
    }

    void AddVagonToTail(const Vagon& v) {
        vagons.AddToTail(v);
        ++countVagons;
    }

    void DeleteVagonFromHead() {
        if (countVagons > 0) {
            vagons.DeleteFromHead();
            --countVagons;
        }
    }

    void DeleteVagonFromTail() {
        if (countVagons > 0) {
            vagons.DeleteFromTail();
            --countVagons;
        }
    }

    void AddVagonAt(int pos, const Vagon& v) {
        vagons.AddAtPosition(pos, v);
        ++countVagons;
    }

    void DeleteVagonAt(int pos) {
        vagons.DeleteAtPosition(pos);
        --countVagons;
    }

    void Show() const {
        cout << "Train model: " << model << " | Vagon count: " << countVagons << endl;
        vagons.Print();
    }
};


int main()
{
    
    Train t1;
    Vagon v1 = { 1, 30, 50 };
    Vagon v2 = { 2, 20, 50 };
    Vagon v3 = { 3, 25, 60 };

    t1.AddVagonToHead(v1);
    t1.AddVagonToTail(v2);
    t1.AddVagonAt(1, v3);

    t1.Show();

    t1.DeleteVagonAt(1); 
    t1.DeleteVagonFromTail();

    cout << "After delete: " << endl;
    t1.Show();
}



