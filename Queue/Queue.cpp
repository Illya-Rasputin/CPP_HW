#include <iostream>
#include <string>
using namespace std;


class Document
{
public:
    string fileName;
    int priority;

    Document() : fileName(""), priority(0) {}

    Document(string name, int prio)
    {
        fileName = name;
        priority = prio;
    }

    void Print()
    {
        cout << "Document is printed: " << fileName << " (Priority: " << priority << ")" << endl;
    }
};


template <typename T>
class PriorityQueue
{
    struct Node
    {
        T data;
        Node* next;
    };

    Node* front;

public:
    PriorityQueue() : front(nullptr) {}

    ~PriorityQueue()
    {
        while (!IsEmpty())
            Dequeue();
    }

    bool IsEmpty()
    {
        return front == nullptr;
    }

    void Enqueue(T value)
    {
        Node* newNode = new Node{ value, nullptr };

        
        if (IsEmpty() || value.priority > front->data.priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node* current = front;
            while (current->next != nullptr && current->next->data.priority >= value.priority)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    T Dequeue()
    {
        if (IsEmpty())
            throw runtime_error("Queue is empty!");

        Node* temp = front;
        T result = temp->data;
        front = front->next;
        delete temp;
        return result;
    }

    void PrintAll()
    {
        Node* current = front;
        cout << "Document in queue:\n";
        while (current != nullptr)
        {
            cout << " - " << current->data.fileName << " (Priority: " << current->data.priority << ")\n";
            current = current->next;
        }
    }
};


int GetPriorityByRole(const string& role)
{
    if (role == "guest") return 1;
    if (role == "admin") return 2;
    if (role == "manager") return 3;
    if (role == "director") return 4;
    return 0; 
}

void ShowMenu()
{
    cout << "\n=== Menu ===\n";
    cout << "1. Add a document to queue\n";
    cout << "2. Print\n";
    cout << "3. Look at queue\n";
    cout << "0. Exit\n";
    cout << "Your choice: ";
}

int main()
{
    PriorityQueue<Document> printerQueue;
    int choice;

    do
    {
        ShowMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            string fileName, role;
            cout << "Files name: ";
            getline(cin, fileName);
            cout << "choose an occupation (guest, admin, manager, director): ";
            getline(cin, role);
            int priority = GetPriorityByRole(role);
            if (priority == 0)
            {
                cout << "Unknown occupation. Document not added.\n";
            }
            else
            {
                printerQueue.Enqueue(Document(fileName, priority));
                cout << "Document added to queue.\n";
            }
            break;
        }
        case 2:
        {
            if (printerQueue.IsEmpty())
            {
                cout << "Empty queue. No documents to print.\n";
            }
            else
            {
                Document doc = printerQueue.Dequeue();
                doc.Print();
            }
            break;
        }
        case 3:
            printerQueue.PrintAll();
            break;

        case 0:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Error. Unknown choice!\n";
        }

    } while (choice != 0);

}


