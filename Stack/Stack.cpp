#include <iostream>
using namespace std;

class Stack
{
    enum { EMPTY = -1 };

    char* arr;
    int maxSize;
    int topIndex;

    

public:

    Stack() = delete;

    Stack(int size) : maxSize(size)
    {
        arr = new char[size];
        topIndex = EMPTY;
    }

    ~Stack()
    {
        delete[] arr;
    }

    void Resize()
    {
        int newSize = maxSize * 2;
        char* newArr = new char[newSize];

        for (int i = 0; i <= topIndex; i++)
            newArr[i] = arr[i];

        delete[] arr;
        arr = newArr;
        maxSize = newSize;
    }

    bool IsFull()
    {
        return topIndex == maxSize - 1;
    }

    bool Push(char value)
    {
        if (IsFull())
            Resize();

        arr[++topIndex] = value;
        return true;
    }

    bool IsEmpty()
    {
        return topIndex == EMPTY;
    }

    char Pop()
    {
        if (!IsEmpty())
            return arr[topIndex--];
        return '\0'; 
    }

    void Clear()
    {
        topIndex = EMPTY;
    }

    char Peek()
    {
        if (!IsEmpty())
            return arr[topIndex];
        return '\0'; 
    }

    int GetSize()
    {
        return topIndex + 1;
    }

    void Print()
    {
        for (int i = 0; i <= topIndex; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};


int main()
{
    Stack stack(3);

    stack.Push('A');
    stack.Push('B');
    stack.Push('C');
    stack.Push('D'); 

    stack.Print();   
    cout << "Size: " << stack.GetSize() << endl;
    cout << "Top: " << stack.Peek() << endl;
    cout << "Popped: " << stack.Pop() << endl;
    stack.Print();

    return 0;
}

