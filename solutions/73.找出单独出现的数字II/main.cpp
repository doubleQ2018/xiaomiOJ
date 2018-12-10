
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
        vector<string> tmp = mysplit(line, ',');
        vector<int> nums;
        for(auto c: tmp) nums.push_back(stoi(c));
        unordered_map<int, int> mp;
        for(auto val: nums) mp[val]++;
        int ans;
        for(auto p: mp)
            if(p.second == 1) {
                ans = p.first;
                break;
            }
        cout << ans << endl;
    }

    return 0;
}