#include <bits/stdc++.h>
using namespace std;


// **** Shortest Path in Undirected Graph with Unit Weights - O(N + E), O(N) ****
vector<int> shortestPathUDGraphUnit(int src, int n, vector<int> adj[]) {
    vector<int> dist(n, 1e9);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(auto& v : adj[u]) {
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}



// **** Shortest Path in DAG with Weights - O(N + E), O(N) ****
class ShortestPathDAGraph {
public:
    void tSortDFS(int u, vector<bool>& vis, vector<int>& st, vector<vector<int>> adj[]) {
        vis[u] = 1;
        for(auto& it : adj[u]) {
            int v = it[0];
            if(!vis[v]) {
                tSortDFS(v, vis, st, adj);
            }
        }
        st.push_back(u);
    }
    
    vector<int> topoSort(int n, vector<vector<int>> adj[]) {
        vector<int> st;
        vector<bool> vis(n);
        for (int u = 0; u < n; u++)
        {
            if(!vis[u]) {
                tSortDFS(u, vis, st, adj);
            }
        }
        // reverse(st.begin(), st.end());
        return st;
    }

    vector<int> shortestPath(int src, int n, vector<vector<int>> adj[]) {
        vector<int> st = topoSort(n, adj);
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while(st.size()) {
            int u = st.back();
            st.pop_back();
            if(dist[u] != 1e9) {
                for(auto& it : adj[u]) {
                    int v = it[0], wt = it[1];
                    dist[v] = min(dist[v], dist[u] + wt);
                }
            }
        }
        return dist;
    }
};



// **** Dijkstra's Algorithm - O(Elog(N)), O(N + E) ****
class DijkstrasAlgo {
public:
    vector<int> dijkstra(int src, int n, vector<vector<int>> adj[]) {
        vector<int> dist(n, 1e9);
        vector<int> parent(n); // To find a shortest path
        iota(parent.begin(), parent.end(), 0); // 0-based index
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src}); // dist, node
        while(pq.size()) {
            auto [prev, u] = pq.top();
            pq.pop();
            if (prev > dist[u]) continue; // pruning
            for(auto& it : adj[u]) {
                int v = it[0], wt = it[1];
                if(dist[v] > prev + wt) {
                    dist[v] = prev + wt;
                    pq.push({dist[v], v});
                    parent[v] = u;
                }
            }
        }
        return dist;

        // To find a shortest path
        vector<int> path;
        int node = n - 1; // 0-based index
        while(parent[node] != node) { // Iterate backwards from dest to src through the parent array
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(src);
        reverse(path.begin(), path.end());
        return path;
    }

    vector<int> dijkstraSet(int src, int n, vector<vector<int>> adj[]) {
        vector<int> dist(n, 1e9);
        set<pair<int, int>> st;
        dist[src] = 0;
        st.insert({0, src}); // dist, node
        while(st.size()) {
            auto stIt = *st.begin();
            auto [prev, u] = stIt;
            st.erase(stIt);
            for(auto& it : adj[u]) {
                int v = it[0], wt = it[1];
                if(dist[v] > prev + wt) {
                    if(dist[v] != 1e9){ // edge check
                        st.erase({dist[v], v}); // longer distance not needed
                    }
                    dist[v] = prev + wt;
                    st.insert({dist[v], v});
                }
            }
        }
        return dist;
    }
};



// **** Bellman Ford Algorithm - O(N * E), O(N) ****
// No dist updation should take place after n - 1 iterations
vector<int> bellmanFord(int src, int n, vector<vector<int>>& edges) {
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for(auto& edge : edges) {
            int u = edge[0], v = edge[1], wt = edge[2];
            if(dist[v] > dist[u] + wt) {
                dist[v] = dist[u] + wt;
            }
        }
    }
    for(auto& edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        if(dist[v] > dist[u] + wt){
            cout<<"Negative cycle found!\n";
            break;
        }
    }
    return dist;
}



// **** Floyd Warshall Algorithm - O(N^3), O(N^2) ****
vector<vector<int>> floydWarshall(int n, vector<vector<int>>& edges) {
    vector<vector<int>> dist(n, vector<int> (n, 1e9));
    for(int u = 0; u < n; u++) {
        dist[u][u] = 0;
    }
    for(auto& edge : edges) {
        int u = edge[0], v = edge[1], wt = edge[2];
        dist[u][v] = min(dist[u][v], wt);
        dist[v][u] = min(dist[v][u], wt);
    }
    for (int via = 0; via < n; via++)
    {
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                dist[u][v] = min(dist[u][v], dist[u][via] + dist[via][v]);
            }
        }
    }
    return dist;
}