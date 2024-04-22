#include <iostream>
using namespace std;
const int V = 4;
const int inf = 1e9;

/*
    25/03/23
    Dijkstra's and Floyd Warshall's Algorithm
*/

// **** Dijkstra's Algorithm ****

int minDist(int dist[], bool vis[])
{
    int min = inf, minInd;
    for (int i = 0; i < V; i++) {
        if (!vis[i] && dist[i] < min) {
            min = dist[i], minInd = i;
        }
    }
    return minInd;
}

void dijkstra(int src, int adj[V][V]) {
    int dist[V];
    bool vis[V] = {};
    for (int i = 0; i < V; i++) {
        dist[i] = inf;
    }
    dist[src] = 0;

    for (int i = 0; i < V; i++) {
        int u = minDist(dist, vis);
        vis[u] = 1;
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !vis[v] && dist[v] > dist[u] + adj[u][v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }

    cout<<"Shortest distance from: \n";
    for (int i = 0; i < V; i++)
    {
        cout<<src<<" - "<<i<<": "<<dist[i]<<endl;
    }
}



// **** Floyd Warshall's Algorithm - O(N^3) ****

void floydWarshall(int adj[V][V]){
    for (int via = 0; via < V; via++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
            }
            adj[i][i] = 0;
        }
    }

    cout<<"\nShortest distance from every vertex to every other vertex:\n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if(adj[i][j] == inf) cout<<"inf ";
            else cout<<adj[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    int adj[V][V] = { {0, 1, 1, inf},
                      {1, 0, 2, 2},
                      {1, 2, 0, 3},
                      {inf, 2, 3, 0} };

    dijkstra(0, adj);
    floydWarshall(adj);
    
    return 0;
}