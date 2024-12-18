#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
template <typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// using omultiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define cin(a) int n; cin>>n; int a[n]; for(int i = 0; i < n; ++i) {cin>>a[i];}
#define cinv(v) int n; cin>>n; vector<int> v; for(int i=0; i<n; ++i){int xx; cin>>xx; v.push_back(xx);}
#define lcou(v) {for(auto &x : v) cout<<x<<' '; cout<<"\n";}
#define ll long long


// **** Ordered Set - O(NlogN), O(N) ****
class OrderedSet {
public:
    oset<int> st;
    
    void G() {
        st.insert(1);
        st.insert(10);
        st.insert(2);
        st.insert(7);
        st.insert(2);

        lcou(st)

        // Find kth element
        cout<<"0th element: "<<*st.find_by_order(0)<<endl;
        cout<<"3th element: "<<*st.find_by_order(3)<<endl;

        // Find no of elements strictly smaller than x
        cout<<"No of elements strictly smaller than 7: "<<st.order_of_key(7)<<endl;
    }
};



// **** Trie - O(N * S), O(N * 26) ****
struct TrieNode {
    TrieNode* links[26];
    bool isEnd; // 1 if word exists, 0 if doesn't exist
    int cntEndWith; // Count no. of words equal to word
    int cntPrefix; // Count no. of prefixes equal to word

    TrieNode() {
        memset(links, 0, sizeof(links));
        isEnd = 0;
        cntEndWith = 0;
        cntPrefix = 0;
    }

    // Checks if a node contains a character
    bool containsKey(char ch) {
        return links[ch - 'a'];
    }

    // Puts a node
    void putKey(TrieNode* newNode, char ch) {
        links[ch - 'a'] = newNode;
    }

    // Next node
    TrieNode* next(char ch) {
        return links[ch - 'a'];
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }
    
    void insert(string& word) {
        TrieNode* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                node->putKey(new TrieNode(), ch);
            }
            // Go to its reference node
            node = node->next(ch);
            node->cntPrefix++;
        }
        node->isEnd = 1;
        node->cntEndWith++;
    }
    
    bool search(string& word) {
        TrieNode* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            node = node->next(ch);
        }
        return node->isEnd;
    }

    int countWordsEqualTo(string& word) {
        TrieNode* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            node = node->next(ch);
        }
        return node->cntEndWith;
    }
    
    bool startsWith(string& prefix) {
        TrieNode* node = root;
        for(auto& ch : prefix) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            node = node->next(ch);
        }
        return 1;
    }

    int countWordsStartingWith(string& word) {
        TrieNode* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            node = node->next(ch);
        }
        return node->cntPrefix;
    }

    void erase(string& word) { // Assuming word exists
        TrieNode* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                return;
            }
            node = node->next(ch);
            node->cntPrefix--;
        }
        node->cntEndWith--;
    }
};



// **** Flexible Trie - O(N * S), O(N * S) ****
class TrieNode2 {
public:
    unordered_map<int, TrieNode2*> links;
    int cntEndWith; // Count no. of words equal to word
    int cntPrefix; // Count no. of prefixes equal to word

    TrieNode2() {
        cntEndWith = 0;
        cntPrefix = 0;
    }

    // Checks if a node contains a character
    bool containsKey(char ch) {
        return links[ch - 'a'];
    }

    // Puts a node
    void putKey(TrieNode2* newNode, char ch) {
        links[ch - 'a'] = newNode;
    }

    // Next node
    TrieNode2* next(char ch) {
        return links[ch - 'a'];
    }
};

class Trie2 {
public:
    TrieNode2* root;

    Trie2() {
        root = new TrieNode2();
    }

    void insert(string& word) {
        TrieNode2* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                node->putKey(new TrieNode2(), ch);
            }
            node = node->next(ch);
            node->cntPrefix++;
        }
        node->cntEndWith++;
    }

    bool search(string& word) {
        TrieNode2* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                return 0;
            }
            node = node->next(ch);
        }
        return node->cntEndWith;
    }

    void erase(string& word) { // Assuming word exists
        TrieNode2* node = root;
        for(auto& ch : word) {
            if(!node->containsKey(ch)) {
                return;
            }
            node = node->next(ch);
            node->cntPrefix--;
        }
        node->cntEndWith--;
    }
};



// **** Sparse Table - O(NlogN), O(NlogN) ****
class SparseTable {
public:
    vector<vector<int>> mat;

    SparseTable(vector<int>& nums) {
        int n = nums.size();
        mat.resize((n + 1), vector<int> (log2(n) + 1));
        for (int i = 0; i < n; i++)
        {
            mat[i][0] = nums[i];
        }
        for (int j = 1; (1 << j) <= n; j++)
        {
            for (int i = 0; i + (1 << j) - 1 < n; i++)
            {
                mat[i][j] = min(mat[i][j - 1], mat[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int query(int l, int r) {
        int j = log2(r - l + 1);
        return min(mat[l][j], mat[r - (1 << j) + 1][j]);
    }
};


// **** Segment Tree - O(NlogN), O(N) ****
class SegmentTree {
public:
    SegmentTree(vector<int>& a) {
        this->a = a;
        n = a.size();
        seg.resize(4 * n);
        lazy.resize(4 * n);
        build(0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, n - 1);
    }

    void pointUpdate(int index, int val) {
        pointUpdate(index, val, 0, 0, n - 1);
    }

    void rangeUpdate(int l, int r, int val) {
        rangeUpdate(l, r, val, 0, 0, n - 1);
    }

    int querySumLazy(int l, int r, int val) {
        return querySumLazy(l, r, val, 0, 0, n - 1);
    }

private:
    vector<int> a, seg, lazy;
    int n;

    // Build the segment tree - O(N)
    void build(int ind, int low, int high) {
        if(low == high) {
            seg[ind] = a[low];
            return;
        }

        int mid = (low + high) / 2;
        int left = 2 * ind + 1, right = 2 * ind + 2;
        build(left, low, mid);
        build(right, mid + 1, high);
        // Find maximum
        // seg[ind] = max(seg[left], seg[right]);
        // Find minimum
        // seg[ind] = min(seg[left], seg[right]);
        // Find sum
        seg[ind] = seg[left] + seg[right];
    }

    // query to find min/max/sum in range (l, r) - O(logN)
    int query(int l, int r, int ind, int low, int high) {
        // Completely lies
        if(l <= low && r >= high) {
            return seg[ind];
        }
        // Doesn't lie
        if(l > high || r < low) {
            // Find maximum
            // return INT_MIN;
            // Find minimum
            // return INT_MAX;
            // Find sum
            return 0;
        }

        // overlaps
        int mid = (low + high) / 2;
        int leftQuery = query(l, r, 2 * ind + 1, low, mid);
        int rightQuery = query(l, r, 2 * ind + 2, mid + 1, high);
        // Find maximum
        // return max(leftQuery, rightQuery);
        // Find minimum
        // return min(leftQuery, rightQuery);
        // Find sum
        return leftQuery + rightQuery;
    }

    // Single element update with val - O(logN)
    void pointUpdate(int index, int val, int ind, int low, int high) {
        if(low == high) {
            seg[ind] = val;
        }
        else {
            int mid = (low + high) / 2;
            int left = 2 * ind + 1, right = 2 * ind + 2;
            if(low <= index && index <= mid) {
                pointUpdate(index, val, left, low, mid);
            }
            else {
                pointUpdate(index, val, right, mid + 1, high);
            }
            seg[ind] = seg[left] + seg[right];
        }
    }

    // Update all values in range (l, r) with val - O(logN)
    void rangeUpdate(int l, int r, int val, int ind, int low, int high) {
        int left = 2 * ind + 1, right = 2 * ind + 2;
        if(lazy[ind]) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if(low != high) {
                lazy[left] += lazy[ind];
                lazy[right] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if(l > high || r < low || low > high) {
            return;
        }
        if(l <= low && r >= high) {
            seg[ind] += (high - low + 1) * val;
            if(low != high) {
                lazy[left] += lazy[ind];
                lazy[right] += lazy[ind];
            }
            return;
        }

        int mid = (low + high) / 2;
        rangeUpdate(l, r, val, left, low, mid);
        rangeUpdate(l, r, val, right, mid + 1, high);
        seg[ind] = seg[left] + seg[right];
    }

    // Query to find sum in lazy in range (l, r) - O(logN)
    int querySumLazy(int l, int r, int val, int ind, int low, int high) {
        int left = 2 * ind + 1, right = 2 * ind + 2;
        if(lazy[ind]) {
            seg[ind] += (high - low + 1) * lazy[ind];
            if(low != high) {
                lazy[left] += lazy[ind];
                lazy[right] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if(l > high || r < low || low > high) {
            return 0;
        }
        if(l <= low && r >= high) {
            return seg[ind];
        }

        int mid = (low + high) / 2;
        return querySumLazy(l, r, val, left, low, mid) + querySumLazy(l, r, val, right, mid + 1, high);
    }
};


int main() {
    vector<int> v = {1,2,3,4,5};
    // SegmentTrees st(v);
    // st.build(0, 0, 4);
    // st.pointUpdate(0, 0, 4, 1, 4);
    // cout<<st.query(0, 0, 4, 0, 0);
    // SparseTable st(v);
    // cout<<st.query(1, 3);

    OrderedSet os;
    os.G();

    return 0;
}