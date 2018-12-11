# Author : Qi Zhang
# Date   : 2018-12-11


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
    while (getline(cin, line)) {
        vector<string> info = mysplit(line, ';');
        int n = stoi(info[0]);
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for(int i = 1; i < info.size(); i++){
            vector<string> tmp = mysplit(info[i], ',');
            int u = stoi(tmp[0]), v = stoi(tmp[1]);
            indegree[v]++;
            graph[u].push_back(v);
        }
        queue<int> q;
        for(int i = 0; i < n; i++)
            if(indegree[i] == 0) {
                q.push(i);
            }
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto next: graph[cur]){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }
        bool ans = true;
        for(auto d: indegree)
            if(d > 0) ans = false;
        cout << (ans? "true": "false") << endl;

    }

    return 0;
}