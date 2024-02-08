#include <bits/stdc++.h>
using namespace std;


// **** Shortest Path in Undirected Graph with Unit Weights ****
class ShortestPathUDGraphUnit{
public:
    vector<int> bfs(int src, int n, vector<int> adj[]){
        vector<int> dist(n, 1e9);
        queue<int> q;
        dist[src] = 0;
        q.push(src);
        while(q.size()){
            int u = q.front();
            q.pop();
            for(auto& v : adj[u]){
                if(dist[v] > dist[u] + 1){
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
};



// **** Shortest Path in DAG with Weights - O(n + e), O(n) ****
class ShortestPathDAGraph{
public:
    void tSortDFS(int u, vector<bool>& vis, vector<int>& st, vector<vector<int>> adj[]){
        vis[u] = 1;
        for(auto& it : adj[u]){
            int v = it[0];
            if(!vis[v]){
                tSortDFS(v, vis, st, adj);
            }
        }
        st.push_back(u);
    }
    
    vector<int> topoSort(int n, vector<vector<int>> adj[]){
        vector<int> st;
        vector<bool> vis(n);
        for (int u = 0; u < n; u++)
        {
            if(!vis[u]){
                tSortDFS(u, vis, st, adj);
            }
        }
        // reverse(st.begin(), st.end());
        return st;
    }

    vector<int> shortestPath(int src, int n, vector<vector<int>> adj[]){
        vector<int> st = topoSort(n, adj);
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while(st.size()){
            int u = st.back();
            st.pop_back();
            if(dist[u] != 1e9){
                for(auto& it : adj[u]){
                    int v = it[0], wt = it[1];
                    dist[v] = min(dist[v], dist[u] + wt);
                }
            }
        }
        return dist;
    }
};



// **** Dijkstra's Algorithm - O(elog(n)), O(n + e) ****
class DijkstrasAlgo{
public:
    vector<int> dijkstra(int src, int n, vector<vector<int>> adj[]){
        vector<int> dist(n, 1e9);
        priority_queue <pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src}); // dist, node
        while(pq.size()){
            auto [prev, u] = pq.top();
            pq.pop();
            if (prev > dist[u]) continue; // pruning
            for(auto& it : adj[u]){
                int v = it[0], wt = it[1];
                if(dist[v] > prev + wt){
                    dist[v] = prev + wt;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist;
    }

    vector<int> dijkstraSet(int src, int n, vector<vector<int>> adj[]){
        vector<int> dist(n, 1e9);
        set<pair<int, int>> st;
        dist[src] = 0;
        st.insert({0, src}); // dist, node
        while(st.size()){
            auto stIt = *st.begin();
            auto [prev, u] = stIt;
            st.erase(stIt);
            for(auto &it : adj[u]){
                int v = it[0], wt = it[1];
                if(dist[v] > prev + wt){
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



// **** Bellman Ford Algorithm - O(n * e), O(n) ****
class BellmanFord{
public:
    vector<int> bellmanFord(int src, int n, vector<vector<int>>& edges){
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for(auto& edge : edges){
                int u = edge[0], v = edge[1], wt = edge[2];
                if(dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
        for(auto& edge : edges){
            int u = edge[0], v = edge[1], wt = edge[2];
            if(dist[v] > dist[u] + wt){
                cout<<"Negative cycle found!\n";
                break;
            }
        }
        return dist;
    }
};



// **** Floyd Warshall Algorithm - O(n^3), O(n^2) ****
class FloydWarshall{
public:
    void floydWarshall(vector<vector<int>>& matrix){
        int n = matrix.size();
        for (int via = 0; via < n; via++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
                }
            }
        }
    }
    
    void solve(vector<vector<int>>& edges){
        int n = edges.size();
        vector<vector<int>> matrix(n, vector<int> (n, 1e9));;
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            matrix[u][v] = wt;
            matrix[v][u] = wt;
        }
        floydWarshall(matrix);
    }
};