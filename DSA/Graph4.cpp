#include <bits/stdc++.h>
using namespace std;


// **** Prims Algorithm Minimum Spanning Tree - O(elog(n)), O(n + e) ****
class PrimsAlgoMST {
public:
    vector<int> prims(int n, vector<vector<int>> adj[]) {
        int cost = 0;
        vector<int> parent(n);
        vector<bool> vis(n);
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        parent[0] = -1;
        pq.push({0, 0}); // dist, node
        
        while(pq.size()) {
            auto [prev, u] = pq.top();
            pq.pop();
            if(vis[u]) continue;
            vis[u] = 1;
            cost += prev;
            for(auto& it : adj[u]) {
                int v = it[0], wt = it[1];
                if(!vis[v]) {
                    pq.push({wt, v});
                    parent[v] = u;
                }
            }
        }
        return parent;
    }
};



// **** Disjoint set ****
class DSU {
public:
    vector<int> parent, rank, size;
    int n;

    DSU(int n) {
        this->n = n;
        parent.resize(n + 1), rank.resize(n + 1, 0), size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int u) {
        if(u == parent[u]) {
            return u;
        }
        return parent[u] = findParent(parent[u]); // path compression
    }

    bool merge(int u, int v) {
        u = findParent(u), v = findParent(v);
        if(u == v) {
            return 0;
        }

        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        }
        else {
            parent[v] = u;
            size[u] += size[v];
        }
        n--;
        return 1;
    }

    bool mergeByRank(int u, int v) {
        u = findParent(u), v = findParent(v);
        if(u == v) {
            return 0;
        }

        if(rank[u] < rank[v]) {
            parent[u] = v;
        }
        else if(rank[u] > rank[v]) {
            parent[v] = u;
        }
        else {
            parent[v] = u;
            rank[u]++;
        }
        n--;
        return 1;
    }

    int getSize() {
        return n;
    }
};



// **** Kruskals Algorithm Minimum Spanning Tree - O(elog(n)), O(n + e) ****
class KruskalsAlgoMST {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    }

    vector<vector<int>> kruskals(int n, vector<vector<int>> edges) {
        vector<vector<int>> res;
        sort(edges.begin(), edges.end(), cmp); // edge = {u, v, wt}
        vector<int> parent(n);
        int cost = 0;
        DSU dsu(n);
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if(dsu.findParent(u) != dsu.findParent(v)) {
                cost += wt;
                res.push_back({u, v});
                dsu.merge(u, v);
            }
        }

        // if all nodes does not have the same parent, then it is not a MST
        for (int i = 0; i < n; ++i) {
            if (dsu.findParent(i) != dsu.findParent(0)) {
                return {{}};
            }
        }
        return res;
    }
};



// **** Bridges in Graph | Tarjan's Algorithm - O(n + e), O(n) ****
class BridgesInGraph {
public:
    void dfs(int u, int par, vector<bool>& vis, vector<int>& tin, vector<int>& low, int timer, vector<int> adj[], vector<vector<int>>& res) {
        vis[u] = 1;
        tin[u] = low[u] = timer++;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            if(!vis[v]) {
                dfs(v, u, vis, tin, low, timer, adj, res);
                low[u] = min(low[u], low[v]);
                if(low[v] > tin[u]) { // Formula
                    res.push_back({u, v});
                }
            }
            else {
                low[u] = min(low[u], tin[v]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> res;
        vector<int> adj[n], tin(n, -1), low(n, -1); // tin = time of insertion, low = lowest time of insertion
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
            if(!vis[i]) {
                dfs(i, -1, vis, tin, low, timer, adj, res);
            }
        }
        return res;
    }
};



// **** Articulation Point | Tarjan's Algorithm - O(n + e), O(n) ****
class ArticulationPoint {
public:
    void dfs(int u, int par, vector<bool>& vis, vector<int>& tin, vector<int>& low, int timer, vector<int> adj[], set<int>& res) {
        vis[u] = 1;
        tin[u] = low[u] = timer++;
        int child = 0;
        for(auto& v : adj[u]) {
            if(v == par) continue;
            if(!vis[v]) {
                dfs(v, u, vis, tin, low, timer, adj, res);
                low[u] = min(low[u], low[v]);
                if(par != -1 && low[v] >= tin[u]) { // Formula
                    res.insert(u);
                }
                child++;
            }
            else {
                low[u] = min(low[u], tin[v]);
            }
        }
        if(par == -1 && child > 1) {
            res.insert(u);
        }
    }

    vector<int> articulationPoints(int n, vector<vector<int>>& connections) {
        set<int> res;
        vector<int> adj[n], tin(n, -1), low(n, -1); // tin = time of insertion, low = lowest time of insertion
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
            if(!vis[i]) {
                dfs(i, -1, vis, tin, low, timer, adj, res);
            }
        }
        return {res.begin(), res.end()};
    }
};



// **** Kosaraju's Algorithm (No. of SCC's) - O(n + e), O(n) ****
class TopologicalSortDFS {
public:
    void dfs(int u, vector<bool>& vis, vector<int>& st, vector<int> adj[]) {
        vis[u] = 1;
        for(auto& v : adj[u]) {
            if(!vis[v]){
                dfs(v, vis, st, adj);
            }
        }
        st.push_back(u);
    }

    vector<int> topoSort(int n, vector<int> adj[]) {
        vector<int> st;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]) {
                dfs(i, vis, st, adj);
            }
        }
        reverse(st.begin(), st.end());
        return st;
    }
};

class KosarajusAlgo {
public:
    void dfs(int u, vector<bool>& vis, vector<int> adj[]) {
        vis[u] = 1;
        for(auto& v : adj[u]) {
            if(!vis[v]) {
                dfs(v, vis, adj);
            }
        }
    }

    int kosaraju(int n, vector<int> adj[]) {
        int res = 0;
        vector<int> revAdj[n];
        for (int u = 0; u < n; u++)
        {
            for(auto& v : adj[u]) {
                revAdj[v].push_back(u);
            }
        }
        TopologicalSortDFS tps;
        vector<int> topo = tps.topoSort(n, adj);
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if(!vis[topo[i]]) {
                res++;
                dfs(topo[i], vis, revAdj);
            }
        }
        return res;
    }
};