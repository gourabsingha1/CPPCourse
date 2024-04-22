#include <iostream>
#include <algorithm>
using namespace std;
const int V = 4;
const int inf = 1e9;

/*
    6/02/23
    Prims and Krushkals Algorithm
*/

// **** Prims Algorithm - O(V^2), O(E + V) ****

int minDist(int dist[], bool mstSet[])
{
    int min = inf, minInd;
    for (int i = 0; i < V; i++) {
        if (!mstSet[i] && dist[i] < min) {
            min = dist[i], minInd = i;
        }
    }
    return minInd;
}

void prim(int adj[V][V])
{
    int parent[V], dist[V];
    bool mstSet[V];
    for (int i = 0; i < V; i++) {
        dist[i] = inf;
    }
    dist[0] = 0, parent[0] = -1;

    for (int i = 0; i < V - 1; i++) {
        int u = minDist(dist, mstSet);
        mstSet[u] = 1;
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != 0 && !mstSet[v] && adj[u][v] < dist[v]) {
                parent[v] = u, dist[v] = adj[u][v];
            }
        }
    }

    int cost = 0;
    cout<<"Edge \tWeight\n";
    for (int i = 1; i < V; i++) {
        int u = parent[i], v = i, w = adj[u][v];
        cout<<u<<" - "<<v<<"\t"<<w<<"\n";
        cost += w;
    }
    cout<<"Total cost = "<<cost<<endl;
}



// **** Kruskals Algorithm - O(Elog(E)), O(E + V) ****

struct edge {
    int u, v, w;
};

int parent[V], Rank[V];
edge edges[V];

int find(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = find(parent[node]);
}

bool Union(int u, int v){
    u = find(u);
    v = find(v);
    if(u == v){
        return 1;
    }
    if(Rank[u] < Rank[v]){
        parent[u] = v;
    }
    else if(Rank[u] > Rank[v]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        Rank[u]++;
    }
    return 0;
}

bool cmp(edge a, edge b) {
    return a.w < b.w;
}

void kruskal(int n, int m) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        Rank[i] = 1;
    }
    sort(edges, edges + m, cmp);
    int cost = 0;
    cout << "\nEdge \tWeight\n";
    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
        if (find(u) != find(v)) {
            cout << u << " - " << v << " \t" << w << " \n";
            cost += w;
            Union(u, v);
        }
    }
    cout<<"Total cost = "<<cost<<endl;
}



int main(){
    cout<<"---- MST using Prims ----\n";
    int adj[V][V] = { {0, 1, 1, inf},
                      {1, 0, 2, 2},
                      {1, 2, 0, 3},
                      {inf, 2, 3, 0} };
    prim(adj);
    cout<<endl;

    // cout<<"---- MST using Kruskals ----\n";
    // cout<<"Enter no. of vertices and edges: ";
    // int n, m;
    // cin >> n >> m;
    // cout<<"Enter edges: \n";
    // for (int i = 0; i < m; i++) {
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     edges[i] = {u, v, w};
    // }
    // kruskal(n, m);
    // cout<<endl;

    return 0;
}

/*
4 5
0 1 1
0 2 1
1 2 2
1 3 2
2 3 3
*/