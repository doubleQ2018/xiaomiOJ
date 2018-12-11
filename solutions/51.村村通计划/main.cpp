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

struct cmp{
    bool operator()(pair<int, int> x, pair<int, int> y){
        return x.second > y.second; //小顶堆用大于
    }
};

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string> tmp = mysplit(line, ';');
        int n = stoi(tmp[0]);
        vector<vector<pair<int, int>>> next(n+1);
        for(int i = 1; i < tmp.size(); i++){
            vector<string> one = mysplit(tmp[i], ',');
            int s = stoi(one[0]), t = stoi(one[1]), w = stoi(one[2]);
            next[s].push_back(make_pair(t, w));
            next[t].push_back(make_pair(s, w));
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
        unordered_set<int> u;
        u.insert(1);
        for(auto r: next[1]) q.push(r);
        int res = 0, cnt = n-1;
        while(!q.empty() && cnt){
            pair<int, int> p = q.top(); q.pop();
            if(u.find(p.first) != u.end()) continue;
            u.insert(p.first);
            cnt--;
            res += p.second;
            for(auto r: next[p.first]){
                if(u.find(r.first) == u.end()) q.push(r);
            }
        }
        cout << res << endl;
    }

    return 0;
}