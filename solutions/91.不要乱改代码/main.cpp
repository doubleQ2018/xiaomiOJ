// Author : Qi Zhang
// Date   : 2018-11-22

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> mysplit(string s, char t){
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
        vector<string> tmp = mysplit(line, ';');
        string start = tmp[0];
        unordered_map<string, vector<int>> p2n;
        vector<vector<string>> n2p;
        for(int i = 1; i < tmp.size(); i++){
            vector<string> peoples = mysplit(tmp[i], ' '), cur;
            for(int j = 1; j < peoples.size(); j++){
                string p = peoples[j];
                p2n[p].push_back(i-1);
                cur.push_back(p);
            }
            n2p.push_back(cur);
        }
        int n = n2p.size();
        vector<bool> vis(n, false);
        queue<int> q;
        for(auto p: p2n[start]) q.push(p);
        bool ans = false;
        while(!q.empty()){
            if(ans) break;
            int cur = q.front(); q.pop();
            vis[cur] = true;
            for(auto people: n2p[cur]){
                if(people == "neighbor_wang"){
                    ans = true;
                    break;
                }
                for(auto num: p2n[people]){
                    if(!vis[num]) q.push(num);
                }
            }
        }
        if(ans) cout << "go die" << endl;
        else cout << "good programmer" << endl;
    }

    return 0;
}
