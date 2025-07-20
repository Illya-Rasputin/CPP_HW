#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Array {
private:
    long* arr;
    int size;

public:
    // ����������� �� �������������
    Array() : arr(0), size(0) {}

    // ����������� �� ������� ������� (�� �������� = 0)
    Array(int n) : size(n) {
        arr = new long[size];
        for (int i = 0; i < size; ++i)
            arr[i] = 0;
    }

    // ����������� ���������
    Array(const Array& other) : size(other.size) {
        arr = new long[size];
        for (int i = 0; i < size; ++i)
            arr[i] = other.arr[i];
    }

    // ����������
    ~Array() {
        delete[] arr;
    }

    // ���������� � ���������
    void fillFromInput() {
        for (int i = 0; i < size; ++i) {
            cout << "������� [" << i << "]: ";
            cin >> arr[i];
        }
    }
    void fillRandom() {
        for (int i = 0; i < size; ++i) {
			arr[i] = rand() % 100;
        }
    }

    // ��������� ��������
    void show() const {
        if (size == 0) {
            cout << "����� �������.\n";
            return;
        }
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }

    // ��������� ��������
    void add(long value) {
        long* newArr = new long[size + 1];
        for (int i = 0; i < size; ++i)
            newArr[i] = arr[i];
        newArr[size] = value;
        delete[] arr;
        arr = newArr;
        size++;
    }

    // ��������� �� ��������
    void removeByIndex(int index) {
        if (index < 0 || index >= size) {
            cout << "Error: invalid index\n";
            return;
        }
        long* newArr = new long[size - 1];
        for (int i = 0, j = 0; i < size; ++i) {
            if (i != index) {
                newArr[j] = arr[i];
                j++;
            }
        }
        delete[] arr;
        arr = newArr;
        size--;
    }

    // ��������� �� ��������� (������ ���������)
    void removeByValue(long value) {
        int index = -1;
        for (int i = 0; i < size; ++i) {
            if (arr[i] == value) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Element not found.\n";
            return;
        }
        removeByIndex(index);
    }

    // ���������� �� ����������
    void sortAscending() {
        for (int i = 0; i < size - 1; ++i)
            for (int j = i + 1; j < size; ++j)
                if (arr[i] > arr[j]) {
                    long temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
    }

    // ���������� �� ���������
    void sortDescending() {
        for (int i = 0; i < size - 1; ++i)
            for (int j = i + 1; j < size; ++j)
                if (arr[i] < arr[j]) {
                    long temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
    }

    // ̳������� ��������
    long getMin() const {
        if (size == 0) 
        {
            cout << "Empty massive.\n";
            return 0;
        }
        long min = arr[0];
        for (int i = 1; i < size; ++i)
            if (arr[i] < min)
                min = arr[i];
        return min;
    }

    // ����������� ��������
    long getMax() const {
        if (size == 0) 
        {
            cout << "Empty massive.\n";
            return 0;
        }
        long max = arr[0];
        for (int i = 1; i < size; ++i)
            if (arr[i] > max)
                max = arr[i];
        return max;
    }

    // ������ �����������
    double getAverage() const {
        if (size == 0) {
            cout << "����� �������.\n";
            return 0;
        }
        long sum = 0;
        for (int i = 0; i < size; ++i)
            sum += arr[i];
        return (double)sum / size;
    }

    // ����� ������
    int getSize() const {
        return size;
    }
};

int main()
{
    Array a(3);
    a.fillRandom();
    a.show();

    a.add(99);
    a.show();

    a.removeByValue(99);
    a.show();

    a.sortAscending();
    a.show();

    cout << "Min: " << a.getMin() << endl;
    cout << "Max: " << a.getMax() << endl;
    cout << "Avg: " << a.getAverage() << endl;

}

