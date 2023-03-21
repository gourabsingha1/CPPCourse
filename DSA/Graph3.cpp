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
            for(auto &v : adj[u]){
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
    void tSort(int i, vector<bool> &vis, stack<int> &st, vector<vector<int>> adj[]){
        vis[i] = 1;
        for(auto &it : adj[i]){
            if(!vis[it[0]]){
                tSort(it[0], vis, st, adj);
            }
        }
        st.push(i);
    }
    vector<int> shortestPath(int src, int n, vector<vector<int>> adj[]){
        stack<int> st;
        vector<bool> vis(n);
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                tSort(i, vis, st, adj);
            }
        }
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while(st.size()){
            int i = st.top();
            st.pop();
            if(dist[i] != 1e9){
                for(auto &it : adj[i]){
                    int j = it[0], wt = it[1];
                    dist[j] = min(dist[j], dist[i] + wt);
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
            // int prev = pq.top().first, u = pq.top().second;
            pq.pop();
            if (prev > dist[u]) continue;
            for(auto &it : adj[u]){
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
            auto it = *st.begin();
            auto [prev, u] = it;
            // int prev = it.first, u = it.second;
            st.erase(it);
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
    vector<int> bellmanFord(int src, int n, vector<vector<int>> &edges){
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for(auto &it : edges){
                int u = it[0], v = it[1], wt = it[2];
                dist[v] = min(dist[v], dist[u] + wt);
            }
        }
        for(auto &it : edges){
            int u = it[0], v = it[1], wt = it[2];
            if(dist[u] + wt < dist[v]){
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
    void floydWarshall(vector<vector<int>> &matrix){
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
    void solve(vector<vector<int>> &edges){
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