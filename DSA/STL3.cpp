#include <bits/stdc++.h>
using namespace std;
#define cin(a) int n; cin>>n; int a[n]; for(int i = 0; i < n; ++i) {cin>>a[i];}
#define cinv(v) int n; cin>>n; vector<int> v; for(int i=0; i<n; ++i){int xx; cin>>xx; v.push_back(xx);}
#define lcou(v) {for(auto &x : v) cout<<x<<' '; cout<<"\n";}
#define ll long long

// **** Lower bound and upper bound ****
// lower_bound(x) returns element >= x
// upper_bound(x) returns element > x

void lowerAndUpperBound() {
    // Array
    cin(a)
    sort(a, a + n);
    auto ptr1 = lower_bound(a, a + n, 5);
    auto ptr2 = upper_bound(a, a + n, 5);
    if(ptr1 == a + n){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Lowerbound is: "<<*ptr1<<endl;
    }
    if(ptr2 == a + n){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Upperbound is: "<<*ptr2<<endl;
    }

    // Vector
    vector<int> nums;
    for (int i = 0; i < n; i++)
    {
        nums.push_back(a[i]);
    }
    sort(nums.begin(), nums.end());
    auto ptr3 = lower_bound(nums.begin(), nums.end(), 5);
    auto ptr4 = upper_bound(nums.begin(), nums.end(), 5);
    if(ptr3 == nums.end()){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Lowerbound is: "<<*ptr3<<endl;
    }
    if(ptr4 == nums.end()){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Upperbound is: "<<*ptr4<<endl;
    }
    
    // Set
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    auto ptr5 = st.lower_bound(4);
    auto ptr6 = st.upper_bound(5);
    if(ptr5 == st.end()){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Lowerbound is: "<<*ptr5<<endl;
    }
    if(ptr6 == st.end()){
        cout<<"Not found"<<endl;
    }
    else{
        cout<<"Upperbound is: "<<*ptr6<<endl;
    }
}


// Set operations
void setOperations() {
    multiset<int> st;
    st.insert(2);
    st.insert(1);
    st.insert(2);
    st.insert(4);
    st.insert(4);
    st.insert(3);
    st.insert(3);
    st.insert(2);
    lcou(st)
    st.erase(st.find(2)); // removes iterator and 2 should be present
    // st.erase(3); // removes all 3's
    // st.erase(st.begin()); // set shouldn't be empty
    // st.erase(--st.end()); // set shouldn't be empty
    lcou(st)
}

int main() {
    // lowerAndUpperBound();

    setOperations();
    
    return 0;
}