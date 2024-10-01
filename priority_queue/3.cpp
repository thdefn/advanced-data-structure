#include <iostream>
using namespace std;


bool isHeapRecur(int a[], int size);
bool isMinHeapRecur(int a[], int size, int index);
bool isMaxHeapRecur(int a[], int size, int index);

int main()
{

    int size = 7;

    int minHeap[] = {0, 2, 5, 6, 8, 9, 10};
    int nonMinHeap[] = {0, 2, 9, 6, 8, 5, 10};

    int maxHeap[] = {0, 10, 9, 6, 5, 8, 2};
    int nonMaxHeap[] = {0, 10, 2, 6, 5, 8, 9};

    cout << boolalpha;
    cout << "isMinHeap: " << isHeapRecur(nonMinHeap, size) << endl;
    cout << "isMaxHeap: " << isHeapRecur(nonMaxHeap, size) << endl;

    return 0;
}



bool isHeapRecur(int a[], int size) {
     if(a[1] < a[2])
        return isMinHeapRecur(a, size, 2);
    else return isMaxHeapRecur(a, size, 2);
}

bool isMinHeapRecur(int a[], int size, int index) {
    if(index >= size) return true;
    int parent = index / 2;
    if(a[parent] >= a[index]){
        return false;
    }
    return isMinHeapRecur(a, size, index + 1);
}

bool isMaxHeapRecur(int a[], int size, int index) {
    if(index >= size) return true;
    int parent = index / 2;
    if(a[parent] <= a[index]){
        return false;
    }
    return isMaxHeapRecur(a, size, index + 1);
}