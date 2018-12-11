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
        vector<string> tmp = mysplit(line, ' ');
        int k = stoi(tmp.back());
        tmp = mysplit(tmp[0], ',');
        vector<int> nums;
        for(auto x: tmp) nums.push_back(stoi(x));
        unordered_map<int, int> mp;
        for(auto val: nums) mp[val]++;
        vector<pair<int, int>> pp;
        for(auto p: mp) pp.push_back(p);
        sort(pp.begin(), pp.end(), [](const pair<int, int> &x, const pair<int, int> &y){
                return x.second > y.second;});
        vector<int> ans;
        for(int i = 0; i < k && i < pp.size(); i++) ans.push_back(pp[i].first);
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++){
            cout << ans[i];
            if(i < ans.size()-1) cout << ",";
            else cout << endl;
        }

    }

    return 0;
}