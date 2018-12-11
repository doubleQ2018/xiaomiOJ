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
        vector<string> tmp = mysplit(line, ';');
        vector<int> nums;
        int target = stoi(tmp[0]);
        tmp = mysplit(tmp[1], ',');
        for(auto c: tmp) nums.push_back(stoi(c));
        int i = 0, j = 0, sums = 0, ans = INT_MAX;
        while(j < nums.size()){
            while(sums < target && j < nums.size()) sums += nums[j++];
            while(sums >= target && i < j){
                ans = min(ans, j-i);
                sums -= nums[i++];
            }
        }
        if(ans == INT_MAX) cout << "0" << endl;
        else cout << ans << endl;
     }

    return 0;
}