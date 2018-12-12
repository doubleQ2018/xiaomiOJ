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

int helper(vector<int>& heights) {
    int n = heights.size();
    if(n == 0) return 0;
    vector<int> ld(n), rd(n);
    ld[0] = -1;
    for(int i = 1; i < n; i++){
        int tmp = i-1;
        while(tmp != -1 && heights[i] <= heights[tmp]) tmp = ld[tmp];
        ld[i] = tmp;
    }
    rd[n-1] = n;
    for(int i = n-2; i >= 0; i--){
        int tmp = i+1;
        while(tmp != n && heights[i] <= heights[tmp]) tmp = rd[tmp];
        rd[i] = tmp;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) ans = max(ans, heights[i] * (rd[i]-ld[i]-1));
    return ans;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string> tmp = mysplit(line, ',');
        vector<int> nums;
        for(auto c: tmp) nums.push_back(stoi(c));
        cout << helper(nums) << endl;
    }

    return 0;
}