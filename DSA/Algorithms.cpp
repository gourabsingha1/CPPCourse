#include <bits/stdc++.h>
using namespace std;
#define cin(a) int n; cin>>n; int a[n]; for(int i = 0; i < n; ++i) {cin>>a[i];}
#define cinv(v) int n; cin>>n; vector<int> v; for(int i=0; i<n; ++i){int xx; cin>>xx; v.push_back(xx);}
#define lcou(v) {for(auto &x : v) cout<<x<<' '; cout<<"\n";}
#define ll long long


// **** Floyds Cycle Detection - O(N), O(1) ****
int findDuplicate(vector<int>& nums) {
    int fast = 0, slow = 0;
    while(1){
        fast = nums[nums[fast]]; // slow * 2 = fast
        slow = nums[slow];
        if(fast == slow){ // since its a cycle, they will always meet
            break;
        }
    }
    // start slow from the beginning to find the meeting point
    slow = 0;
    while(fast != slow){
        // shifting both pointers by one until they meet
        fast = nums[fast];
        slow = nums[slow];
    }
    return slow;
}


// **** Longest Prefix Suffix (LPS) - O(N), O(N) ****
string longestPrefix(string& s) {
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


// **** KMP | String matching. Returns index of the first occurance - O(N + M), O(M) ****
class KMP {
public:
    vector<int> lps(string& s) {
        int n = s.size(), i = 1, prevLPS = 0;
        vector<int> LPS(n, 0);
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
        return LPS;
    }
    
    int strStr(string& haystack, string& needle) {
        vector<int> LPS = lps(needle);
        int i = 0, j = 0;
        while(i < haystack.size()){
            if(haystack[i] == needle[j]){
                i++, j++;
            }
            else if(j == 0){
                i++;
            }
            else{
                j = LPS[j - 1];
            }
            if(j == needle.size()){
                return i - needle.size();
            }
        }
        return -1;
    }
};


// **** Z-Algorithm - O(N + M), O(N + M) ****
class ZAlgo {
public:
    vector<int> zAlgo(string& s) {
        int n = s.size(), l = 0, r = 0;
        vector<int> z(n);
        for (int i = 1; i < n; i++)
        {
            if(i > r) {
                l = r = i;
                while(r < n && s[r - l] == s[r]) {
                    r++;
                }
                z[i] = r - l;
                r--;
            }
            else {
                int ind = i - l;
                if(i + z[ind] <= r) {
                    z[i] = z[ind];
                }
                else {
                    l = i;
                    while(r < n && s[r - l] == s[r]) {
                        r++;
                    }
                    z[i] = r - l;
                    r--;
                }
            }
        }
        return z;
    }

    int strStr(string& haystack, string& needle) {
        string tot = needle + "$" + haystack;
        vector<int> z = zAlgo(tot);
        for (int i = 0; i < z.size(); i++)
        {
            if(z[i] == needle.size()) {
                return i - needle.size() - 1;
            }
        }
        return -1;
    }
};


// **** LIS - O(N^2), O(N) ****
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size(), res = 0;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i]){
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

// **** Printing LIS - O(N^2), O(N) ****
vector<int> longestIncreasingSubsequence(vector<int>& nums) {
    int n = nums.size(), lis = 0, maxInd = 0;
    vector<int> dp(n, 1), prev(n), res;
    for (int i = 0; i < n; i++)
    {
        prev[i] = i;
        for (int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i] && dp[i] < 1 + dp[j]){
                dp[i] = 1 + dp[j];
                prev[i] = j;
            }
        }
        if(lis < dp[i]) {
            lis = dp[i];
            maxInd = i;
        }
    }
    while(res.size() < lis) {
        res.push_back(nums[maxInd]);
        maxInd = prev[maxInd];
    }
    reverse(res.begin(), res.end());
    return res;
}

// **** LIS - O(NlogN), O(N) ****
int lengthOfLis(vector<int>& nums) {
    vector<int> LIS = {nums[0]};
    for (int i = 1; i < nums.size(); i++)
    {
        int lb = lower_bound(LIS.begin(), LIS.end(), nums[i]) - LIS.begin();
        if(lb == LIS.size()) {
            LIS.push_back(nums[i]);
        }
        else {
            LIS[lb] = nums[i];
        }
    }
    return LIS.size();
}

// **** No. of LIS - O(N^2), O(N) ****
int findNumberOfLIS(vector<int>& nums) {
    int n = nums.size(), res = 0, lengthOfLIS = 1;
    vector<int> dp(n, 1), cnt(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i]){
                if(dp[i] == 1 + dp[j]) {
                    cnt[i] += cnt[j];
                }
                else if(dp[i] < 1 + dp[j]) {
                    cnt[i] = cnt[j];
                }
                dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        lengthOfLIS = max(lengthOfLIS, dp[i]);
    }
    
    for (int i = 0; i < n; i++)
    {
        if(dp[i] == lengthOfLIS) {
            res += cnt[i];
        }
    }
    return res;
}



// **** LCS - O(N * M), O(N * M) ****
int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int res = 0;
            if(text1[i - 1] == text2[j - 1]) {
                res = 1 + dp[i - 1][j - 1];
            }
            else {
                int first = dp[i - 1][j];
                int second = dp[i][j - 1];
                res = max(first, second);
            }
            dp[i][j] = res;
        }
    }
    return dp[n][m];
}


// **** Matrix Chain Multiplication - O(N^3), O(N^2) ****
int MCM(int n, int arr[]) {
    vector<vector<int>> dp(n, vector<int> (n, 0));
    for (int i = n - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(i == j) continue;
            
            int res = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int cost = arr[i - 1] * arr[k] * arr[j];
                int left = dp[i][k];
                int right = dp[k + 1][j];
                res = min(res, cost + left + right);
            }
            dp[i][j] = res;
        }
    }
    return dp[1][n - 1];
}


// **** Monotonic Stack (Strictly) - O(N), O(N) ****
vector<int> nextGreaterElementIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> decStack;
    for (int i = 0; i < n; i++)
    {
        while(decStack.size() && nums[decStack.top()] < nums[i]) {
            res[decStack.top()] = i;
            decStack.pop();
        }
        decStack.push(i);
    }
    return res;
}

vector<int> prevGreaterElementIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> decStack;
    for (int i = 0; i < n; i++)
    {
        while(decStack.size() && nums[decStack.top()] <= nums[i]) {
            decStack.pop();
        }
        if(decStack.size()) {
            res[i] = decStack.top();
        }
        decStack.push(i);
    }
    return res;
}

vector<int> nextSmallerElementIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> incStack;
    for (int i = 0; i < n; i++)
    {
        while(incStack.size() && nums[incStack.top()] > nums[i]) {
            res[incStack.top()] = i;
            incStack.pop();
        }
        incStack.push(i);
    }
    return res;
}

vector<int> prevSmallerElementIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> res(n, -1);
    stack<int> incStack;
    for (int i = 0; i < n; i++)
    {
        while(incStack.size() && nums[incStack.top()] >= nums[i]) {
            incStack.pop();
        }
        if(incStack.size()) {
            res[i] = incStack.top();
        }
        incStack.push(i);
    }
    return res;
}

pair<vector<int>, vector<int>> numberOfElementsGreaterThanCur(vector<int>& arr) {
    int n = arr.size(), res = 0, M = 1e9 + 7;
    stack<int> decStackPrev, decStackNext;
    vector<int> left(n), right(n); // number of elements which are >= current element
    for (int i = 0; i < n; i++)
    {
        while(decStackPrev.size() && arr[decStackPrev.top()] > arr[i]) {
            decStackPrev.pop();
        }
        if(decStackPrev.size()) {
            left[i] = i - decStackPrev.top();
        }
        else {
            left[i] = i + 1;
        }
        decStackPrev.push(i);

        int j = n - 1 - i;
        while(decStackNext.size() && arr[decStackNext.top()] >= arr[j]) {
            decStackNext.pop();
        }
        if(decStackNext.size()) {
            right[j] = decStackNext.top() - j;
        }
        else {
            right[j] = i + 1;
        }
        decStackNext.push(j);
    }
    return {left, right};
}

pair<vector<int>, vector<int>> numberOfElementsSmallerThanCur(vector<int>& arr) {
    int n = arr.size(), res = 0, M = 1e9 + 7;
    stack<int> incStackPrev, incStackNext;
    vector<int> left(n), right(n); // number of elements which are <= current element
    for (int i = 0; i < n; i++)
    {
        while(incStackPrev.size() && arr[incStackPrev.top()] < arr[i]) {
            incStackPrev.pop();
        }
        if(incStackPrev.size()) {
            left[i] = i - incStackPrev.top();
        }
        else {
            left[i] = i + 1;
        }
        incStackPrev.push(i);

        int j = n - 1 - i;
        while(incStackNext.size() && arr[incStackNext.top()] <= arr[j]) {
            incStackNext.pop();
        }
        if(incStackNext.size()) {
            right[j] = incStackNext.top() - j;
        }
        else {
            right[j] = i + 1;
        }
        incStackNext.push(j);
    }
    return {left, right};
}

int main() {
    vector<int> v = {1,4,7,6,1,2,0,3,6,3,4,4,56};
    lcou(nextGreaterElementIndex(v))
    lcou(prevGreaterElementIndex(v))
}