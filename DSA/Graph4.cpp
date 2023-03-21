#include <bits/stdc++.h>
using namespace std;


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
    vector<int> parent, rank;
    DisjointSet(int n){
        parent.resize(n + 1), rank.resize(n + 1);
        for (int i = 0; i <= n; i++)
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
        u = findParent(u), v = findParent(v);
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
    vector<vector<int>> kruskals(int n, vector<vector<int>> adj[]){
        vector<vector<int>> edges, res;
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                edges.push_back({i, it[0], it[1]});
            }
        }
        sort(edges.begin(), edges.end(), sortbyvector);
        vector<int> parent(n);
        int cost = 0;
        DisjointSet DS(n);
        for(auto &it : edges){
            int u = it[0], v = it[1], wt = it[2];
            if(DS.findParent(u) != DS.findParent(v)){
                cost += wt;
                res.push_back({u, v});
                DS.Union(u, v);
            }
        }
        return res;
    }
};



// **** Bridges in Graph | Tarjan's Algorithm - O(n + e), O(n) ****
class BridgesInGraph{
public:
    void dfs(int node, int parent, vector<bool> &vis, vector<int> &tin, vector<int> &low, int timer, vector<int> adj[], vector<vector<int>> &res){
        vis[node] = 1;
        tin[node] = low[node] = timer++;
        for(auto &it : adj[node]){
            if(it == parent){
                continue;
            }
            if(!vis[it]){
                dfs(it, node, vis, tin, low, timer, adj, res);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]){ // Formula
                    res.push_back({node, it});
                }
            }
            else{
                low[node] = min(low[node], tin[it]); // vertex with two or more nodes
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> res;
        vector<int> adj[n], tin(n, -1), low(n, -1); // adj, time of insertion, low
        vector<bool> vis(n);
        for (int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0], v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int timer = 0;
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                dfs(i, -1, vis, tin, low, timer, adj, res);
            }
        }
        return res;
    }
};



// **** Kosaraju's Algorithm (No. of SCC's) - O(n + e), O(n) ****
class TopologicalSortDFS{
public:
    void dfs(int u, vector<bool> &vis, vector<int> &st, vector<vector<int>> &adj){
        vis[u] = 1;
        for(auto &v : adj[u]){
            if(!vis[v]){
                dfs(v, vis, st, adj);
            }
        }
        st.push_back(u);
    }
    vector<int> topoSort(int n, vector<vector<int>> &adj){
        vector<int> st;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                dfs(i, vis, st, adj);
            }
        }
        reverse(st.begin(), st.end());
        return st;
    }
};
class KosarajusAlgo{
public:
    void dfs(int u, vector<bool> &vis, vector<vector<int>> &adj){
        vis[u] = 1;
        for(auto &v : adj[u]){
            if(!vis[v]){
                dfs(v, vis, adj);
            }
        }
    }
    int kosaraju(int n, vector<vector<int>> &adj){
        int res = 0;
        vector<vector<int>> revAdj(n);
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                revAdj[it].push_back(i);
            }
        }
        TopologicalSortDFS Topo;
        vector<int> topo = Topo.topoSort(n, adj);
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if(!vis[topo[i]]){
                res++;
                dfs(topo[i], vis, revAdj);
            }
        }
        return res;
    }
};