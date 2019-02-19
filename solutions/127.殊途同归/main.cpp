// Author : Qi Zhang
// Date   : 2019-02-19

#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<vector<int>> &graph){
    vector<int> dist(n+1, -1);
    vector<bool> vis(n+1, false);
    for(int i = 1; i <= n; i++){
        graph[i][i] = 0;
        // start at point 1
        dist[i] = graph[1][i];
    }
    vector<int> path(n+1);
    path[1] = 1; // used to record shortest path
    int cnt = n;
    while(cnt){
        int Min = INT_MAX, p;
        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            if(dist[i] < Min){
                Min = dist[i];
                p = i;
            }
        }
        vis[p] = true;
        //cout << "min dist " << p << endl;
        for(int i = 1; i <= n; i++){
            if(vis[i]) continue;
            if(graph[p][i] != INT_MAX && dist[p] + graph[p][i] < dist[i])
                dist[i] = dist[p] + graph[p][i];
            path[i] = p;
        }
        cnt--;
    }
    return dist[n];
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g1(n+1, vector<int>(n+1, INT_MAX));
    vector<vector<int>> g2(n+1, vector<int>(n+1, 1));
    for(int i = 0; i < m; i++){
        int s, t;
        cin >> s >> t;
        g1[s][t] = 1;
        g1[t][s] = 1;
        g2[s][t] = INT_MAX;
        g2[t][s] = INT_MAX;
    }
    int a = solve(n, g1), b = solve(n, g2);
    //cout << a << " " << b << endl;
    int ans = max(a, b);
    if(ans == INT_MAX) cout << -1 << endl;
    else cout << ans << endl;
}