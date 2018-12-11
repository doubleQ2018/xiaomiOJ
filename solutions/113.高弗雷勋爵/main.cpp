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
        vector<int> nums;
        for(auto c: tmp) nums.push_back(stoi(c));
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = ((nums.back()+1)/2*2+2)/2;
        unordered_set<int> st;
        for(auto x: nums) st.insert((x+1)/2);
        ans -= st.size();
        cout << ans << endl;
    }

    return 0;
}