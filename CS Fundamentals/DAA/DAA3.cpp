#include <iostream>
#include <queue>
using namespace std;
const int V = 4;
const int inf = 1e9;

/*
    18/02/23
    DFS and BFS
*/

void dfs(int u, bool vis[], int adj[V][V]){
    cout<<u<<' ';
    vis[u] = 1;
    for (int v = 0; v < V; v++)
    {
        if(adj[u][v] == 1 && !vis[v]){
            dfs(v, vis, adj);
        }
    }
}

void dfsOfGraph(int start, int adj[V][V]) {
    bool vis[V] = {};
    for(int i = start; i < V; i++){
        if(!vis[i]){
            dfs(i, vis, adj);
        }
    }
    cout<<endl;
}

void bfsOfGraph(int start, int adj[V][V]) {
    queue<int> q;
    q.push(start);
    bool vis[V] = {};
    vis[start] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cout<<u<<' ';
        for (int v = 0; v < V; v++) {
            if (adj[u][v] && !vis[v]) {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}

int main() {
    int adj[V][V] = { {0, 0, 1, 1},
                      {0, 0, 1, 1},
                      {1, 1, 0, 1},
                      {1, 1, 1, 0} };
    /*
    (0) - (2)
    |       |
    (3) - (1)
    */

    cout<<"DFS traversal"<<endl;
    dfsOfGraph(0, adj);
    cout<<"BFS traversal"<<endl;
    bfsOfGraph(0, adj);
    
    return 0;
}