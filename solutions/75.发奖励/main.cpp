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
        vector<string> tmp = mysplit(line, ',');
        vector<int> nums;
        for(auto c: tmp) nums.push_back(stoi(c));
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int i = 1; i < n; i++)
            if(nums[i] > nums[i-1])
                dp[i] = dp[i-1]+1;
        for(int i = n-2; i >= 0; i--)
            if(nums[i] > nums[i+1]) dp[i] = max(dp[i], dp[i+1]+1);
        int ans = accumulate(dp.begin(), dp.end(), 0);
        cout << ans << endl;

    }

    return 0;
}