#include <bits/stdc++.h>
using namespace std;


// **** Merge Sort - outplace ****
void mergeSort(int low, int high, vector<int>& nums) {
    if(low >= high) {
        return;
    }
    // divide
    int mid = (low + high) / 2;
    mergeSort(low, mid, nums);
    mergeSort(mid + 1, high, nums);
    // merge
    merge(low, mid, high, nums);
}

void merge(int low, int mid, int high, vector<int>& nums) {
    int left = low, right = mid + 1;
    vector<int> temp;
    while (left <= mid && right <= high) {
        if (nums[left] < nums[right]){
            temp.push_back(nums[left++]);
        }
        else {
            temp.push_back(nums[right++]);
        }
    }
    while (left <= mid) {
        temp.push_back(nums[left++]);
    }
    while(right <= high) {
        temp.push_back(nums[right++]);
    }
    for (int i = 0; i < temp.size(); i++)
    {
        nums[low + i] = temp[i];
    }
}