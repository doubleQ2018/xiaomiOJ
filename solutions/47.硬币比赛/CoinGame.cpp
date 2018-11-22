// Author : Qi Zhang
// Date   : 2018-11-22

#include <iostream>
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
        reverse(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> sums(n+1, 0);
        for(int i = 0; i < n; i++) sums[i+1] = sums[i]+nums[i];
        vector<int> dp(n);
        for(int i = 0; i < n; i++){
            if(i == 0) dp[i] = nums[i];
            else if(i == 1) dp[i] = nums[i] + nums[i-1];
            else{
                dp[i] = max(nums[i] + sums[i] - dp[i-1], nums[i] + nums[i-1] + sums[i-1] - dp[i-2]);
            }
        }
        if(dp[n-1] * 2 > sums.back()) cout << "true" << endl;
        else cout << "false" << endl;
    }

    return 0;
}
