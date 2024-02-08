#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb(a) push_back(a);
#define vl vector<ll>
#define vvl vector<vl>
#define fo(i,j,n) for(ll i = j; i < n; ++i)
#define cin(a) ll n; cin>>n; ll a[n]; fo(i,0,n){cin>>a[i];}
#define nl cout<<endl;
#define co(a) {cout<<a<<" ";}
#define cou(a) {cout<<a<<" "; nl}
#define lcou(v) {afo(v) cout<<x<<" "; nl}


int main(){


    // **** Vectors ****
    cou("-Vectors")
    vector<ll> Vector{15,10,30,25};
    cou(Vector[3])
    sort(Vector.begin(),Vector.end()); // 10,15,25,30
    sort(Vector.begin(),Vector.end(),greater<ll>()); // 30,25,15,10
    Vector.push_back(40); // 30,25,15,10,40
    Vector.pop_back(); // 30,25,15,10
    nl



    // **** Pairs ****
    cou("-Pairs")
    pair<ll,string> Pair{3,"Yes"};
    co(Pair.first) // 3
    cou(Pair.second) // Yes
    nl



    // **** List ****
    cou("-List")
    list<ll> List{10,20};
    List.push_back(30); // 10,20,30
    List.push_front(0); // 0,10,20,30
    cou(List.front()) // 0
    cou(List.back()) // 30
    auto itL = List.begin(); // >0,10,20,30
    itL++; // 0,>10,20,30
    itL = List.erase(itL); // 0,>20,30
    itL = List.insert(itL,25); // 0,>25,20,30
    cou(*itL) // 25
    List.sort(); // 0,20,25,30
    for(auto it = List.rbegin(); it!=List.rend(); ++it){
        co(*it) // 30,25,20,0
    }nl
    nl



    // **** Deque ****
    cou("-Deque")
    deque<ll> Deque{4,5,6};
    Deque.push_front(3); // 3,4,5,6
    Deque.push_back(7); // 3,4,5,6,7
    cou(Deque[2]) // 5
    Deque.pop_front(); // 4,5,6,7
    cou(Deque[2]) // 6
    auto itD = Deque.begin(); // >4,5,6,7
    itD++; // 4,>5,6,7
    cou(*itD)
    nl



    // **** Stack (LIFO) ****
    cou("-Stack")
    stack<ll> Stack;
    Stack.push(10); // 10
    Stack.push(25); // 25,10
    Stack.push(15); // 15,25,10
    Stack.push(5); // 5,15,25,10
    Stack.pop(); // 15,25,10
    cou(Stack.top()) // 15
    while(!Stack.empty()){
        co(Stack.top()) // 15,25,10
        Stack.pop();
    }nl
    nl



    // **** Queue (FIFO) ****
    cou("-Queue")
    queue<ll> Queue;
    Queue.push(10); // 10
    Queue.push(25); // 10,25
    Queue.push(15); // 10,25,15
    Queue.push(5); // 10,25,15,5
    Queue.pop(); // 25,15,5
    cou(Queue.front()) // 25
    while(!Queue.empty()){
        co(Queue.front()) // 25,15,5
        Queue.pop();
    }nl
    nl



    // **** Priority queue **** // duplicate
    cou("-Priority queue")
    priority_queue<ll> PQueue; // sorts in descending
    priority_queue<ll,vector<ll>,greater<ll>> GPQueue; // sorts in ascending
    PQueue.push(10); // 10
    PQueue.push(5); // 10,5
    PQueue.push(25); // 25,10,5
    PQueue.push(15); // 25,15,10,5
    PQueue.push(5); // 25,15,10,5,5
    PQueue.pop(); // 15,10,5,5
    cou(PQueue.top()) // 15
    while(!PQueue.empty()){
        co(PQueue.top()) // // 15,10,5,5
        PQueue.pop();
    }nl
    nl



    // **** Nesting in Vectors ****
    cou("-Nesting in Vectors")
    vector<pair<ll,ll>> vp;
    fo(i,0,2){
        // ll x,y;
        // cin>>x>>y;
        // vp.pb(make_pair(x,y))
    }
    fo(i,0,vp.size()){
        cou(vp[i].first<<" "<<vp[i].second)
    }
    nl



    // **** Auto ****
    cou("-Auto")
    auto a = 1;
    cou(1)
    for(auto &x : vp){
        cou(x.first<<" "<<x.second)
    }
    nl



    // **** Set (No duplicate)****
    cou("-Set")
    set<ll> ASet; // ascending order
    set<ll, greater<ll>> DSet; // descending order
    ASet.insert(40);
    ASet.insert(15);
    ASet.insert(45);
    ASet.insert(45);
    ASet.insert(30);
    ASet.insert(10);
    for(auto &x : ASet){
        co(x) // 10,15,30,40,45
    }nl
    auto it = ASet.find(20);
    if(it!=ASet.end()){
        cou("Value "<<(*it)<<" exists")
    }
    else{
        cou("Value 20 doesn't exist")
    }
    auto itAS = ASet.begin(); // >10,15,30,40,45
    itAS++; // 10,>15,30,40,45
    cou(*itAS) // 15
    itAS = ASet.erase(itAS); // 10,>30,40,45
    cou(*itAS) // 30
    nl



    // **** Multiset (Duplicate)****
    cou("-Multiset")
    multiset<string> MASet; // ascending order
    multiset<string, greater<ll>> MDSet; // descending order
    MASet.insert("abc");
    MASet.insert("zsdf");
    MASet.insert("bcd");
    MASet.insert("abc");
    for(auto &x : MASet){
        co(x)
    }nl
    nl


    
    // **** Unordered set, O(1) (Use only to check presence) ****
    cou("-Unordered set")
    unordered_set<string> USet;
    fo(i,0,3){
        string s;
        cin>>s;
        USet.insert(s);
    }
    if(USet.find("abc")==USet.end()){
        cou("abc is not present")
    }
    else{
        cou("abc is present")
    }
    nl



    // **** Map (ordered) ****
    cou("-Map")
    map<ll,string>Map; // ascending order
    map<ll,string,greater<ll>>GMap; // descending order
    Map[10]="Ten";
    Map[20]="Twenty";
    Map[15]="Fifteen";
    Map[30]="Thirty";
    Map[10]="Ben10";
    for(auto &x : Map){
        cou(x.first<<" "<<x.second)
    }
    auto itM = Map.find(10);
    itM->second = "Lol"; // Update
    if(itM!=Map.end()){
        cou("Value 10 exists and value is: "<<Map[10])
    }
    else{
        cou("Value 10 doesn't exist")
    }


    
    // **** Unordered map (unordered) ****
    cou("-Unordered Map")
    unordered_map<ll,string>UMap;
    UMap[10]="Ten";
    UMap[20]="Twenty";
    UMap[15]="Fifteen";
    UMap[30]="Thirty";
    UMap[10]="Ben10";
    for(auto &x : UMap){
        cou(x.first<<" "<<x.second)
    }
    auto itUM = UMap.find(10);
    itUM->second = "Lol"; // Update
    if(itUM!=UMap.end()){
        cou("Value 10 exists and value is: "<<UMap[10])
    }
    else{
        cou("Value 10 doesn't exist")
    }

    
    return 0;
}