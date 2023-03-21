#include <bits/stdc++.h>
using namespace std;


// **** Input Undirected graph ****
void inputUndirectedGraph(int n, vector<int> adj[])
{
    for(int i = 0; i < n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

// **** Input Directed graph ****
void inputDirectedGraph(int n, vector<int> adj[])
{
    for(int i = 0; i < n; i++){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
}

// **** Print adjacent nodes ****
void printNodes(int n, vector<int> adj[])
{
    for(int i = 0; i < n; i++){
        cout<<i<<": ";
        for(auto &x : adj[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

// **** Create graph ****
vector<vector<int>> createGraph(int n, vector<vector<int>>& edges){
    vector<vector<int>> adj(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0], v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return adj;
}


// **** Breadth First Search (BFS) ****
vector<int> bfs(int n, vector<int> adj[]) {
    vector<int> res;
    vector<bool> vis(n);
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            q.push(i); vis[i] = 1;
        }
        while(q.size()){
            int u = q.front();
            q.pop();
            res.push_back(u);
            for(int &v : adj[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    return res;
}


// **** Depth First Search (DFS) ****
class DFSRecursive{
public:
    void dfs(int u, vector<bool> &vis, vector<int> adj[], vector<int> &res){
        res.push_back(u);
        vis[u] = 1;
        for(auto &v : adj[u]){
            if(!vis[v]){
                dfs(v, vis, adj, res);
            }
        }
    }
    vector<int> dfsOfGraph(int n, vector<int> adj[]){
        vector<int> res;
        vector<bool> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, vis, adj, res);
            }
        }
        return res;
    }
};

vector<int> dfs(int n, vector<int> adj[]){
    vector<int> res;
    vector<bool> vis(n, 0);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            st.push(i), vis[i] = 1;
        }
        while(st.size()){
            int t = st.top();
            res.push_back(t);
            st.pop();
            for(int &x : adj[t]){
                if(!vis[x]){
                    st.push(x);
                    vis[x] = 1;
                }
            }
        }
    }
    return res;
}


// **** Cycle Detection in Undirected Graph using BFS ****
class CycleUndirectedBFS{
public:
    bool bfs(int i, vector<bool> &vis, vector<int> adj[]){
        queue<pair<int, int>> q;
        vis[i] = 1;
        q.push({i, -1}); // first node doesn't have a parent node. so, -1
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto &it : adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push({it, node}); // it = node, node = parent node
                }
                else if(it != parent){ // the node is marked visited by some other way. this means that a cycle is formed
                    return 1;
                }
            }
        }
        return 0;
    }
    bool isCyclic(int n, vector<int> adj[]){
        vector<bool> vis(n, 0);
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                if(bfs(i, vis, adj)){
                    return 1;
                }
            }
        }
        return 0;
    }
};


// **** Cycle Detection in Undirected Graph using DFS ****
class CycleUndirectedDFS{
public:
    bool dfs(int i, int parent, vector<bool> &vis, vector<int> adj[]){
        vis[i] = 1;
        for(auto &it : adj[i]){
            if(!vis[it]){
                dfs(it, i, vis, adj);
            }
            else if(it != parent){
                return 1;
            }
        }
        return 0;
    }
    bool isCyclic(int n, vector<int> adj[]){
        vector<bool> vis(n, 0);
        for (int i = 0; i < n; i++)
        {
            if(!vis[i]){
                if(dfs(i, -1, vis, adj)){ // first node doesn't have a parent node. so, -1
                    return 1;
                }
            }
        }
        return 0;
    }
};