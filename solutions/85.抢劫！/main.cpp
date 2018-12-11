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
        for(auto s: tmp) nums.push_back(stoi(s));
        int n = nums.size();
        vector<int> dp(n+1, 0);
        for(int i = 0; i < n; i++){
            if(i == 0) dp[i+1] = nums[i];
            else dp[i+1] = max(dp[i], dp[i-1]+nums[i]);
        }
        cout << dp[n] << endl;
    }

    return 0;
}