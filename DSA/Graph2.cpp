#include <bits/stdc++.h>
using namespace std;


// **** Cycle Detection in Directed Graph using DFS ****
class CycleDirectedDFS{
public:
    bool dfs(int u, vector<bool> &vis, vector<bool> &dfsVis, vector<vector<int>> &adj){
        vis[u] = 1;
        dfsVis[u] = 1;
        for(auto &v : adj[u]){
            if(!vis[v]){
                if(dfs(v, vis, dfsVis, adj)){
                    return 1;
                }
            }
            else if(dfsVis[v]){
                return 1;
            }
        }
        dfsVis[u] = 0;
        return 0;
    }
    bool isCyclic(int n, vector<vector<int>> &adj){
        vector<bool> vis(n); // to mark all time visited paths
        vector<bool> dfsVis(n); // to mark the current visited path
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                if(dfs(i, vis, dfsVis, adj)){
                    return 1;
                }
            }
        }
        return 0;
    }
};



// **** Topological Sort (DFS) (DAG = Directed Acylic Graph) - O(n + e), O(n) ****
// if u->v, then u appears first in the ordering
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



// **** Topological Sort (BFS) | Kahn's Algorithm - O(n + e), O(n) ****
class TopologicalSortBFS{
public:
    vector<int> topoSort(int n, vector<vector<int>> &adj){
        vector<int> res, indegree(n, 0); // indegree = no. of arrows directed towards
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                indegree[it]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(q.size()){
            int i = q.front();
            q.pop();
            res.push_back(i);
            for(auto &it : adj[i]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        return res;
    }
};



// **** Cycle Detection in Directed Graph using BFS ****
// Topological sort must not generate
class CycleDirectedBFS{
public:
    bool isCyclic(int n, vector<vector<int>> &adj){
        int cnt = 0;
        vector<int> indegree(n, 0); // indegree = no. of arrows directed towards
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            for(auto &it : adj[i]){
                indegree[it]++;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(q.size()){
            int i = q.front();
            q.pop();
            for(auto &it : adj[i]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
            cnt++;
        }
        return cnt != n;
    }
};