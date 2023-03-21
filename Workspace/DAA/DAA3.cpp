#include <bits/stdc++.h>
using namespace std;

class DFSRecursive{
public:
    void dfs(int i, int u, bool vis[], int adj[][1000], int res[]){
        res[i] = u;
        vis[u] = 1;
        for(auto &v : adj[u]){
            if(!vis[v]){
                dfs(i + 1, v, vis, adj, res);
            }
        }
    }
    int* dfsOfGraph(int n, int adj[][1000]){
        int res[n];
        bool vis[n];
        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, i, vis, adj, res);
            }
        }
        return res;
    }
};

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

int main() {
    int n, m;
    cin>>n>>m;
    int adj[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin>>adj[i][j];
        }
    }
    
    return 0;
}