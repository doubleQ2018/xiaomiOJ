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
        vector<string> tmp = mysplit(line, ',');
        vector<int> nums;
        for(auto c: tmp) nums.push_back(stoi(c));
        unordered_map<int, int> mp;
        int ans = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            if(i == 0){
                mp[nums[i]]++;
                continue;
            }
            if(mp.find(10-nums[i]) != mp.end()) ans += mp[10-nums[i]];
            if(mp.find(nums[i]+10) != mp.end()) ans += mp[nums[i]+10];
            if(mp.find(nums[i]-10) != mp.end()) ans += mp[nums[i]-10];
            mp[nums[i]]++;
        }
        cout << ans << endl;
    }

    return 0;
}