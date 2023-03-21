#include <bits/stdc++.h>
using namespace std;

/*
    6/02/23
    Prims and Krushkals Algorithm
*/

// **** Prims Algorithm Minimum Spanning Tree - O(elog(n)), O(n + e) ****
class PrimsAlgoMST{
public:
    vector<int> prims(int n, vector<vector<int>> adj[]){
        int cost = 0;
        vector<int> parent(n);
        vector<bool> vis(n);
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        parent[0] = -1;
        pq.push({0, 0}); // dist, node
        while(pq.size()){
            int prev = pq.top().first, u = pq.top().second;
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            cost += prev;
            for(auto &it : adj[u]){
                int v = it[0], wt = it[1];
                if(!vis[v]){
                    parent[v] = u;
                    pq.push({wt, v});
                }
            }
        }
        return parent;
    }
};



// **** Disjoint set ****
class DisjointSet{
public:
    int parent[100001], rank[100001];
    void makeSet(int n){
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]); // path compression
    }
    bool Union(int u, int v){
        u = findParent(u);
        v = findParent(v);
        if(u == v){
            return 1;
        }
        if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else{
            parent[v] = u;
            rank[u]++;
        }
        return 0;
    }
};



// **** Kruskals Algorithm Minimum Spanning Tree - O(elog(n)), O(n + e) ****
class KruskalsAlgoMST{
public:
    static bool sortbyvector(const vector<int> &a, const vector<int> &b){
        return a[2] < b[2];
    }
    vector<pair<int, int>> kruskals(int n, vector<vector<int>> adj[]){
        vector<vector<int>> edges;
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                edges.push_back({i, it[0], it[1]});
            }
        }
        sort(edges.begin(), edges.end(), sortbyvector);
        // vector<int> parent(n);
        vector<pair<int, int>> mst;
        int cost = 0;
        DisjointSet DS;
        DS.makeSet(n);
        for(auto &it : edges){
            int u = it[0], v = it[1], wt = it[2];
            if(DS.findParent(u) != DS.findParent(v)){
                cost += wt;
                // parent[u] = v;
                mst.push_back({u, v});
                DS.Union(u, v);
            }
        }
        return mst;
    }
};

int main(){
    int n, e;
    cout<<"Enter number of vertices: ";
    cin>>n;
    cout<<"Enter number of edges: ";
    cin>>e;
    vector<vector<int>> adj[n];
    cout<<"Enter edges and weights i.e u, v, wt: ";
    for (int i = 0; i < e; i++)
    {
        int u, v, wt;
        cin>>u>>v>>wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    PrimsAlgoMST mst1;
    cout<<"Parent of MST using prims: ";
    for(auto &it : mst1.prims(n, adj)){
        cout<<it<<' ';
    }
    cout<<endl;

    KruskalsAlgoMST mst2;
    cout<<"Edges of MST using kruskals: \n";
    for(auto &[u, v] : mst2.kruskals(n, adj)){
        cout<<u<<' '<<v<<endl;
    }
    cout<<endl;

    return 0;
}
/*
n = 5, e = 6
u v wt
0 2 3
2 4 6
2 1 10
1 3 4
3 4 1
2 3 2
*/