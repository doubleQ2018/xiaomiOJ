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
        int lastreach = 0, ans = 0, reach = nums[0];
        for(int i = 1; i < n && i <= reach; i++){
            if(i > lastreach) {
                ans++;
                lastreach = reach;
            }
            reach = max(reach, i+nums[i]);
        }
        if(reach < n-1) ans = -1;
        cout << ans << endl;
    }

    return 0;
}