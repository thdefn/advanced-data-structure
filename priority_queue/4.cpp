#include <iostream>
using namespace std;


bool isHeapIter(int a[], int size);
bool isMinHeapIter(int a[], int size);
bool isMaxHeapIter(int a[], int size);

int main()
{

    int size = 7;

    int minHeap[] = {0, 2, 5, 6, 8, 9, 10};
    int nonMinHeap[] = {0, 2, 9, 6, 8, 5, 10};

    int maxHeap[] = {0, 10, 9, 6, 5, 8, 2};
    int nonMaxHeap[] = {0, 10, 2, 6, 5, 8, 9};

    cout << boolalpha;
    cout << "isMinHeap: " << isHeapIter(nonMinHeap, size) << endl;
    cout << "isMaxHeap: " << isHeapIter(nonMaxHeap, size) << endl;

    return 0;
}



bool isHeapIter(int a[], int size) {
    if(a[1] < a[2])
        return isMinHeapIter(a, size);
    else return isMaxHeapIter(a, size);
}

bool isMinHeapIter(int a[], int size) {
    for(int i = 2; i < size ; i++) {
        int parent = i / 2;
        if(a[parent] >= a[i]){
            return false;
        }
    }
    return true;
}

bool isMaxHeapIter(int a[], int size) {
    for(int i = 2; i < size ; i++) {
        int parent = i / 2;
        if(a[parent] <= a[i]){
            return false;
        }
    }
    return true;
}
