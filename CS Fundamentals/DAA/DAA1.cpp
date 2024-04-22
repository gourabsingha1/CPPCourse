#include <iostream>
#include <iomanip> // setprecision
using namespace std;

// Bubble Sort
void bubbleSort(int n, int a[])
{
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (a[j] > a[j + 1]){
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// Insertion Sort
void insertionSort(int n, int arr[])
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort
void selectionSort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        if(min_idx != i){
            swap(arr[min_idx], arr[i]);
        }
    }
}

// Merge Sort
void merge(int arr[], int p, int q, int r) {
    int n1 = q - p + 1, n2 = r - q, L[n1], M[n2];
    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }
    for (int j = 0; j < n2; j++) {
        M[j] = arr[q + 1 + j];
    }
    int i = 0, j = 0, k = p;
    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i++];
        }
        else {
            arr[k] = M[j++];
        }
        k++;
    }
    while (i < n1) {
        arr[k++] = L[i++];
    }
    while (j < n2) {
        arr[k++] = M[j++];
    }
}
void mergeSort(int l, int r, int arr[]) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(l, m, arr);
        mergeSort(m + 1, r, arr);
        merge(arr, l, m, r);
    }
}

// Quick Sort
int partition(int arr[], int start, int end)
{
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) count++;
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}
void quickSort(int start, int end, int arr[])
{
    if (start >= end) return;
    int p = partition(arr, start, end);
    quickSort(start, p - 1, arr);
    quickSort(p + 1, end, arr);
}

// Heap Sort
void heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root Since we are using 0 based indexing
	int l = 2 * i + 1; // left = 2*i + 1
	int r = 2 * i + 2; // right = 2*i + 2
	if (l < n && arr[l] > arr[largest]) {
		largest = l;
    }
	if (r < n && arr[r] > arr[largest]) {
		largest = r;
    }
	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(int n, int arr[])
{
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(arr, n, i);
    }
	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void time(int i, int j, int n, int best[], int avg[], int worst[]){
    if(i == 0) {
        if(j == 0) bubbleSort(n, best);
        else if(j == 1) bubbleSort(n, avg);
        else bubbleSort(n, worst);
    }
    else if(i == 1) {
        if(j == 0) selectionSort(n, best);
        else if(j == 1) selectionSort(n, avg);
        else selectionSort(n, worst);
    }
    else if(i == 2) {
        if(j == 0) insertionSort(n, best);
        else if(j == 1) insertionSort(n, avg);
        else insertionSort(n, worst);
    }
    else if(i == 3) {
        if(j == 0) mergeSort(0, n, best);
        else if(j == 1) mergeSort(0, n, avg);
        else mergeSort(0, n, worst);
    }
    else if(i == 4) {
        if(j == 0) quickSort(0, n, best);
        else if(j == 1) quickSort(0, n, avg);
        else quickSort(0, n, worst);
    }
    else {
        if(j == 0) heapSort(n, best);
        else if(j == 1) heapSort(n, avg);
        else heapSort(n, worst);
    }
}

int main(){
    int n = 20000, side = 1;
    int best[n], avg[n], worst[n];
    for (int i = 0; i < n; i++, side *= -1)
    {
        best[i] = i;
        avg[i] = i * side;
        worst[i] = n - 1 - i;
    }

    for (int i = 0; i < 6; i++)
    {
        if(i == 0) cout<<"---- Bubble Sort ----\n";
        if(i == 1) cout<<"---- Insertion Sort ----\n";
        if(i == 2) cout<<"---- Selection Sort ----\n";
        if(i == 3) cout<<"---- Merge Sort ----\n";
        if(i == 4) cout<<"---- Quick Sort ----\n";
        if(i == 5) cout<<"---- Heap Sort ----\n";

        cout<<"Best case = ";
        struct timeval st1, en1;
        mingw_gettimeofday(&st1, NULL);
        time(i, 0, n, best, avg, worst);
        mingw_gettimeofday(&en1, NULL);
        double timetaken1;
        timetaken1 = (en1.tv_sec - st1.tv_sec) * 1e6;
        timetaken1 = (timetaken1 + (en1.tv_usec - st1.tv_usec)) * 1e-6;
        cout<<fixed<<timetaken1<<setprecision(5)<<"s\n";
        
        cout<<"Average case = ";
        struct timeval st2, en2;
        mingw_gettimeofday(&st2, NULL);
        time(i, 1, n, best, avg, worst);
        mingw_gettimeofday(&en2, NULL);
        double timetaken2;
        timetaken2 = (en2.tv_sec - st2.tv_sec) * 1e6;
        timetaken2 = (timetaken2 + (en2.tv_usec - st2.tv_usec)) * 1e-6;
        cout<<fixed<<timetaken2<<setprecision(5)<<"s\n";

        cout<<"Worst case = ";
        struct timeval st3, en3;
        mingw_gettimeofday(&st3, NULL);
        time(i, 2, n, best, avg, worst);
        mingw_gettimeofday(&en3, NULL);
        double timetaken3;
        timetaken3 = (en3.tv_sec - st3.tv_sec) * 1e6;
        timetaken3 = (timetaken3 + (en3.tv_usec - st3.tv_usec)) * 1e-6;
        cout<<fixed<<timetaken3<<setprecision(5)<<"s\n\n";
    }
    
    return 0;
}


// ---- Class Tasks ----
/*
    9/01/23
    find the time consumption and comparison chart of following algorithms using best, avg and worst case scenarios
    1. Bubble
    2. Selection
    3. Merge 
    4. Quick 
    5. Heap
*/

/*
    16/01/23
    wap to create and read 3 files named best_case.txt, avg_case.txt, worst_case.txt of datatype Int
*/