#include  <iostream>
using namespace std;
//insertion sort
template <typename T>
void sort(T * arr, int n){
    for(int i = 1; i < n; i++){
        T temp = arr[i];
        int j = i - 1;
        for(j; j >= 0 && temp < arr[j]; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    } 
}
//selection sort
template <typename T>
void sortSelect(T* arr, int n){
    for(int i = 0; i < n - 1; i++){
        int lowidx = i;
        for(int j = i + 1; j < n; j ++){
            if(arr[j] < arr[lowidx])
                lowidx = j;
        }
        swap<T>(arr[i], arr[lowidx]);
    }
}
//bubble sort
template <typename T>
void bubbleSort(T*arr, int n ){
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++)
            if(arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    }
}
//shell sort
template <typename T>
void segmentSort(T* arr, int n, int segment, int k){
    for(int curr = segment + k; curr < n; curr += k){
        T temp = arr[curr];
        int walk = curr - k;
        for(walk; walk >= 0 && temp < arr[walk]; walk -= k)
            arr[walk + k] = arr[walk];
        arr[walk + k] = temp;
    }
}
template <typename T>
void shellsort(T* arr, int n){
    for(int k = n/2; k >= 1; k--){
        for(int segment = 0; segment < k; segment++)
            segmentSort<T>(arr, n, segment, k);
    }
}
//heap sort
template <typename T>
void swap(T* heap, int i, int j){
    T temp = heap[i];
    heap[i] = heap[j];
    heap[j] = temp;
}
template <typename T>
void reHeapUp(T* heap, int child){ //build max heap : move element at index child to move up to the root to make heap
    int parent = (child - 1)/2;
    while(child > 0 && heap[child] > heap[parent]){
        swap(heap, child, parent);
        child = parent;
        parent = (child - 1)/2;
    }
}
template <typename T>
void reHeapDown(T heap[], int size){ //move down the element at the root to remake the heap
    int parent = 0;
    int leftChild = parent*2 + 1;
    int rightChild = parent*2 + 2;

    while(leftChild < size){
        int maxChild = leftChild;
        //find maxchild
        if(rightChild < size && heap[rightChild] > heap[leftChild])
            maxChild = rightChild;
        if(heap[parent] >= heap[maxChild])
            break;
        swap(heap,parent, maxChild);
        parent = maxChild;
        leftChild = parent*2 + 1;
        rightChild = parent*2 + 2;
    }
}
template <typename T>
void heapSort(T* arr, int n){
    for(int i = 1; i < n; i++)
        reHeapUp<T>(arr, i);
    for(int i = n - 1; i >= 0; i--){
        swap<T>(arr, 0, i);
        reHeapDown<T>(arr, i);
    }
}
//merge sort
template <typename T>
void merge(T* arr, T* left, int leftsize, T* right, int rightsize){
    int i = 0, l = 0, r = 0;
    while(l < leftsize && r < rightsize){
        if(left[l] < right[r])
            arr[i++] = left[l++];
        else    
            arr[i++] = right[r++];
    }
    while(l < leftsize)
        arr[i++] = left[l++];
    while(r < rightsize)
        arr[i++] = right[r++];
}
template <typename T>
void mergeSort(T* arr, int n){
    if(n <= 1)
        return;
    int mid = n /2;
    T* left = new T[mid];
    T* right = new T[n - mid];
    int i = 0, j = 0;
    for(i; i < n; i++){
        if(i < mid)
            left[i] = arr[i];
        else{
            right[j] = arr[i];
            j++;
        }
    }
    mergeSort(left, mid);
    mergeSort(right, n - mid);
    merge(arr, left, mid, right, n - mid);
    delete[] left;
    delete[] right;
}
//quicksort
template <typename T>
int partition(T* arr, int left, int right){
    int piindx = (left + right)/2;
    T pivot = arr[piindx];
    swap(arr, piindx, right);
    
    int i = left - 1;
    for(int j = left; j < right; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr, j, i);
        }
    }
    swap(arr, i + 1, right);
    return (i + 1);
}
template <typename T>
void quicksort(T* arr, int i, int j){ // i and j 
    //check if the array have less than 1 element
    if(j <= i)
        return;
    int pivotIndex = partition(arr, i , j);
    quicksort(arr, i, pivotIndex);
    quicksort(arr, pivotIndex + 1, j);
}
//radix change sort
void radixSort(int *arr, int left, int right, int mask){
    int i = left, j = right;
    if((right <= left) || (mask == 0))
        return;
    while(j != i) {
        while(((arr[i] & mask) == 0) && (i < j)) {
            i++;}

        while(((arr[j] & mask) == mask) && (i < j)){
            j--;}
        if(i < j)
            swap(arr, i, j);
    }
    radixSort(arr,left, j - 1, mask >> 1);
    radixSort(arr, j, right, mask >> 1);
}
int main(){
    int array[] = {4,2,9,1};
    // int array[] = {1,4,5,2,3,6,7,8,9};
    // int part = partition(array, 0, 8);
    // cout << part << endl;
    // int mask = 1 << 3;
    heapSort(array,4); 
    for(int i = 0;i < 4; i++)
        cout << array[i] << " ";
    return 0; 
}