// Author : Qi Zhang
// Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

vector<string> mysplit(string &s, char t){
    vector<string> info;
    string cur;
    for(auto c: s){
        if(c == t){
            if(cur != "") info.push_back(cur);
            cur = "";
        }
        else cur += c;
    }
    if(cur != "") info.push_back(cur);
    return info;
}

void flood(vector<vector<char>>& grid, int x, int y, vector<vector<bool>> &vis){
    if(vis[x][y]) return;
    vis[x][y] = true;
    vector<vector<int>> d{{-1,0},{1,0},{0,-1},{0,1}};
    for(int i = 0; i < 4; i++){
        int dx = x + d[i][0], dy = y + d[i][1];
        if(dx >= 0 && dx < grid.size() && dy >= 0 && dy < grid[0].size() && grid[dx][dy] == '1') flood(grid, dx, dy, vis);
    }
    return;
}
int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    if(m == 0) return 0;
    int n = grid[0].size();
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] == '0' || vis[i][j]) continue;
            flood(grid, i, j, vis);
            ans++;
        }
    }
    return ans;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string> tmp = mysplit(line, ' ');
        vector<vector<char>> graph;
        for(auto row: tmp){
            vector<string> r = mysplit(row, ',');
            vector<char> rr;
            for(auto c: r) rr.push_back(c[0]);
            graph.push_back(rr);
        }
        cout << numIslands(graph) << endl;
    }
    return 0;
}