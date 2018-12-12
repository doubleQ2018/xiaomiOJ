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

int main()
{
    string line;
    vector<vector<int>> dic{{1,2},{2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1}};
    while (getline(cin, line)) {
        vector<string> tmp = mysplit(line, ';');
        int n = stoi(tmp[0]), m = stoi(tmp[1]), x1 = stoi(tmp[2]), y1 = stoi(tmp[3]), x2 = stoi(tmp[4]), y2 = stoi(tmp[5]);
        vector<vector<int>> vis(n + 1, vector<int>(m + 1, 0));
        queue<pair<int, int>> q;
        q.push({x1 * (m + 1) + y1, 0});
        vis[x1][y1] = 1;
        vector<int> nx = {1, 2, 2, 1, -1, -2, -2, -1};
        vector<int> ny = {2, 1, -1, -2, -2, -1, 1, 2};
        int ans = -1;
        while(!q.empty()) {
            auto cur = q.front();
            int a = cur.first / (m + 1), b = cur.first % (m + 1), d = cur.second;
            if(a == x2 && b == y2) {
                ans = d;
                break;
            }
            else {
                for(int i = 0; i < 8; ++ i) {
                    int xx = a + nx[i], yy = b + ny[i];
                    if(xx >= 0 && xx <= n && yy >= 0 && yy <= m && vis[xx][yy] == 0) {
                        q.push({xx * (m + 1) + yy, d + 1});
                        vis[xx][yy] = 1;
                    }

                }
            }
            q.pop();
        }
        cout << ans << endl;
    }

    return 0;
}