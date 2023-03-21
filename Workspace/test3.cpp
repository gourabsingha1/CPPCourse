#include <bits/stdc++.h>
using namespace std;
#define lcou(v) {for(auto &x : v) cout<<x<<' '; cout<<"\n";}
#define ll long long

vector<int> dir = {0, 1, 0, -1, 0};
int dijkstra(vector<vector<int>>& grid){
    int res = 0, n = grid.size(), m = grid[0].size();
    vector<vector<int>> dist(n, vector<int> (m, 1e9));
    vector<vector<bool>> vis(n, vector<bool> (m));
    priority_queue <vector<int>, vector<vector<int>>, greater<>> pq;
    pq.push({0, 0, 0}); // dist, curr_cell
    dist[0][0] = grid[0][0];
    vis[0][0] = 1;

    while(pq.size()){
        auto cur = pq.top();
        pq.pop();
        int prev = cur[0], x = cur[1], y = cur[2];
        res += prev;
        for (int i = 0; i < 4; i++)
        {
            int dx = x + dir[i], dy = y + dir[i + 1];
            if(dx >= 0 && dy >= 0 && dx < n && dy < m && !vis[dx][dy]){
                int wt = grid[dx][dy];
                if(dist[dx][dy] > prev + wt){
                    dist[dx][dy] = prev + wt;
                    pq.push({dist[dx][dy], dx, dy});
                    vis[dx][dy] = 1;
                }
            }
        }
    }
    return res;
}
