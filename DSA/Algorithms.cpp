#include <bits/stdc++.h>
using namespace std;

// Floyds Cycle Detection
int findDuplicate(vector<int>& nums) {
    int fast = 0, slow = 0;
    while(1){
        // slow*2 = fast
        fast = nums[nums[fast]];
        slow = nums[slow];
        if(fast==slow){ // since its a cycle, they will always meet
            break;
        }
    }
    // start slow from the beginning to find the meeting point
    slow = 0;
    while(fast!=slow){
        // shifting both pointers by one until they meet
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}


// Boyer Moore's Majority Voting
int majorityElementI(vector<int>& nums) {
    int count = 0, res = 0;
    for (int num : nums) {
        if (!count) { // new major
            res = num;
        }

        if(num == res){ // res could be major
            count++;
        }
        else{ // res could not be major
            count--;
        }
    }
    return res;
}


// Maximum number of majority elements = 2 (always)
vector<int> majorityElementII(vector<int>& nums) {
    vector<int> ans;
    int num1 = -1, num2 = -1, cnt1 = 0, cnt2 = 0;
    for (int &ele : nums) {
        if(num1 == ele){ // num1 could be one of the majors
            cnt1++;
        }
        else if(num2 == ele){ // num2 could be one of the majors
            cnt2++;
        }
        else if(cnt1==0){ // num1 could not be one of the majors
            num1 = ele;
            cnt1 = 1;
        }
        else if(cnt2==0){ // num2 could not be one of the majors
            num2 = ele;
            cnt2 = 1;
        }
        else{ // num1 and num2 could not be one of the majors
            cnt1--;
            cnt2--;
        }
    }

    // check if num1 and num2 appears more than n/3 times (according to question)
    cnt1 = 0, cnt2 = 0;
    for(int &ele : nums){
        if(ele == num1){
            cnt1++;
        }
        else if(ele == num2){
            cnt2++;
        }
    }
    if(cnt1>nums.size()/3){
        ans.push_back(num1);
    }
    if(cnt2>nums.size()/3){
        ans.push_back(num2);
    }
    return ans;
}


// Longest Prefix Suffix (LPS)
string longestPrefix(string s) {
    int n = s.size(), LPS[n], i = 1, prevLPS = 0;
    LPS[0] = 0;
    while(i < n){
        if(s[i] == s[prevLPS]){
            LPS[i] = prevLPS + 1;
            prevLPS++, i++;
        }
        else if(prevLPS == 0){
            LPS[i] = 0, i++;
        }
        else{
            prevLPS = LPS[prevLPS - 1];
        }
    }
    return s.substr(prevLPS);
}


// Subset sum
bool subsetSum(int n, int a[]){
    int res = INT_MAX;
    int sum = accumulate(a, a + n, 0);
    bool dp[n + 1][sum + 1];
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= sum; j++)
        {
            if (j == 0){
                dp[i][j] = 1;
            }
            else if (i == 0){
                dp[i][j] = 0;
            }
            else if (a[i - 1] > j){
                dp[i][j] = dp[i - 1][j];
            }
            else{
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i - 1]];
            }
        }
    }
    for (int i = 0; i <= sum / 2; i++)
    {
        int first = i;
        int second = sum - i;
        if (dp[n][i] == 1 and res > abs(first - second)){
            res = abs(first - second);
        }
    }
    return res;
}


// LIS
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), res = 0;
    vector<int> LIS(n);
    for (int i = n - 1; i >= 0; i--)
    {
        LIS[i] = 1;
        for (int j = i + 1; j < n; j++)
        {
            if(nums[i] < nums[j]){
                LIS[i] = max(LIS[i], 1 + LIS[j]);
            }
        }
        res = max(res, LIS[i]);
    }
    return res;
}


// LCS
int longestCommonSubsequence(string text1, string text2) {
    int res = 0;
    int n = text1.size(), m = text2.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i < n + 1; i++) dp[i][0] = 0;
    for (int i = 0; i < m + 1; i++) dp[0][i] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < m + 1; j++)
        {
            if(text1[i - 1] == text2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            res = max(res, dp[i][j]);
        }
    }
    return res;
}