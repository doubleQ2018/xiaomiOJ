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
    while (getline(cin, line)) {
        vector<string> tmp = mysplit(line, ' ');
        vector<int> nums;
        for(auto c: tmp) nums.push_back(stoi(c));
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) ans = max(ans, nums[i] * (n-i));
        cout << ans << endl;
    }

    return 0;
}