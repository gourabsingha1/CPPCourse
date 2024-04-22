#include <iostream>
#include <algorithm>
using namespace std;

// **** Fractional Knapsack ****

struct Item {
    int value, weight;
};

bool compare(Item a, Item b) {
    double r1 = (double) a.value / a.weight;
    double r2 = (double) b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    sort(arr, arr + n, compare);
    double finalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalValue += arr[i].value;
        }
        else {
            finalValue += arr[i].value * ((double) W / arr[i].weight);
            break;
        }
    }
    return finalValue;
}


// **** 0/1 Knapsack ****

int helper(int W, Item arr[], int n) {
    if(n < 0 || W <= 0) {
        return 0;
    }
    int take = 0;
    if(arr[n].weight <= W) {
        take = arr[n].value + helper(W - arr[n].weight, arr, n - 1); 
    }
    int notTake = helper(W, arr, n - 1);
    return max(take, notTake);
}
int binaryKnapsack(int W, Item arr[], int n) {
    return helper(W, arr, n - 1);
}

int main() {
    int W = 50;
    Item arr[] = {{61, 14}, {105, 24}, {125, 39}};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum value we can obtain = " << fractionalKnapsack(W, arr, n)<<endl;
    cout << "Maximum value we can obtain = " << binaryKnapsack(W, arr, n)<<endl;
    return 0;
}

/*
syllabus-
5 sortings with time
prims, krushkal, bfs, dfs, dijkstra, floyd, binary, fractional, 
exp no: 4, 5, 6, 7, 9, 10, 11, 12, 13, 15, 16, 17, 18, 19
*/