#include <iostream>
using namespace std;
template <typename T>
void Swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T findMin(const T* arr, int size) {
    if (size <= 0) return T(); 
    T min = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] < min)
            min = arr[i];
    return min;
}

template <typename T>
T findMax(const T* arr, int size) {
    if (size <= 0) return T(); 
    T max = arr[0];
    for (int i = 1; i < size; ++i)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

template <typename T>
void bubbleSort(T* arr, int size) {
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                Swap(arr[j], arr[j + 1]);
}

template <typename T>
int binarySearch(const T* arr, int size, const T& target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; 
}

template <typename T>
void replaceAt(T* arr, int size, int index, const T& newValue) {
    if (index < 0 || index >= size) return; 
    arr[index] = newValue;
}


template<class T_arr>
class Array {
private:
   T_arr* arr;
   int size;

public:
   // Provide public accessors for `arr` and `size`
   T_arr* getArr() const {
       return arr;
   }

   int getSize() const {
       return size;
   }

   Array() {
       arr = nullptr;
       size = 0;
   }

   Array(int size) {
       this->size = size;
       arr = new T_arr[size] {};
   }

   ~Array() {
       if (arr != nullptr) {
           delete[] arr;
       }
   }

   Array(const initializer_list<T_arr> list) {
       this->size = list.size();
       arr = new int[size];
       int i = 0;
       for (int elem : list) {
           arr[i++] = elem;
       }
   }

   void Fill(const initializer_list<T_arr> list) {
       if (arr != nullptr)
           delete[] arr;
       this->size = list.size();
       arr = new int[size];
       int i = 0;
       for (int elem : list) {
           arr[i++] = elem;
       }
   }

   void Print() const {
       for (int i = 0; i < size; i++) {
           cout << arr[i] << " ";
       }
       cout << endl;
   }
};

int main() {
   Array<int> arr(5);
   arr.Fill({ 5, 2, 8, 1, 3 });
   arr.Print();

   cout << "Min: " << findMin(arr.getArr(), arr.getSize()) << endl;

   cout << "Max: " << findMax(arr.getArr(), arr.getSize()) << endl;

   bubbleSort(arr.getArr(), arr.getSize());
   cout << "Sorted: ";
   arr.Print();

   
   int idx = binarySearch(arr.getArr(), arr.getSize(), 3);
   cout << "Index of 3: " << idx << endl;

   
   replaceAt(arr.getArr(), arr.getSize(), 2, 99);
   cout << "replaced: ";
   arr.Print();

   Swap(arr.getArr()[0], arr.getArr()[1]);
   cout << "swaped: ";
   arr.Print();
}


