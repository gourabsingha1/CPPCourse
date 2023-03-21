#include <bits/stdc++.h>
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

// Selection Sort
void selectionSort(int n, int arr[])
{
    for (int i = 0; i < n - 1; i++)
    {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
        if (arr[j] < arr[min_idx]){
            min_idx = j;
        }
        if(min_idx != i){
            swap(arr[min_idx], arr[i]);
        }
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
void quickSort(int arr[], int start, int end)
{
    if (start >= end) return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void print(int n, int a[]){
    for (int i = 0; i < n; i++) cout<<a[i]<<' ';
    cout<<'\n';
}

void time(int n, int a[], string s){
    struct timeval start, end;
    mingw_gettimeofday(&start, NULL);

    if(s == "bubble"){
        bubbleSort(n, a);
    }
    else if(s == "selection"){
        selectionSort(n, a);
    }
    else if(s == "quick"){
        quickSort(a, 0, n);
    }
    else{
        cout<<"Invalid input"<<endl;
        return;
    }
    print(n, a);

    mingw_gettimeofday(&end, NULL);
    double time_taken;
    time_taken = (end.tv_sec - start.tv_sec) * 1e6;
    time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
    cout<<"After sort: "<<fixed<<time_taken<<setprecision(5)<<"s\n\n";
}

void readFile(string s, int n, int a[]){
    string line;
    ifstream myfile;
    myfile.open(s);
    if(myfile.is_open()) {
        while(getline(myfile, line)){
            for (int i = 0, j = 0; i < line.length() && j < n; i++)
            {
                string st;
                while(i < line.length() && line[i] != ' '){
                    st += line[i++];
                }
                a[j++] = stoi(st);
            }
        }
        myfile.close();
    }
    else{
        cout<<"Couldn't open file\n";
    }
}

int main(){
    while(1){
        string s;
        cin>>s;
        if(s == "exit"){
            break;
        }
        int n = 4000;
        int best[n], avg[n], worst[n];
        readFile("best_case.txt", n, best);
        readFile("avg_case.txt", n, avg);
        readFile("worst_case.txt", n, worst);
        cout<<"---- Best case ----"<<endl;
        time(n, best, s);
        cout<<"---- Average case ----"<<endl;
        time(n, avg, s);
        cout<<"---- Worst case ----"<<endl;
        time(n, worst, s);
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