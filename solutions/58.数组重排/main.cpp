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

int findUnsortedSubarray(vector<int>& nums) {
    int n = nums.size();
    int l = n-1, min_num = INT_MAX;
    for(int i = n-1; i >= 0; i--){
        min_num = min(min_num, nums[i]);
        if(nums[i] > min_num) l = i;
    }
    int r = 0, max_num = INT_MIN;
    for(int i = 0; i < n; i++){
        max_num = max(max_num, nums[i]);
        if(nums[i] < max_num) r = i;
    }
    return l < r? r-l+1: 0;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string> tmp = mysplit(line, ',');
        vector<int> nums;
        for(auto c: tmp) nums.push_back(stoi(c));
        cout << findUnsortedSubarray(nums) << endl;
    }

    return 0;
}