// Author : Qi Zhang
// Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

vector<string> mysplit(string s, char t){
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
        vector<string> t1 = mysplit(tmp[0], ' ');
        int n = stoi(t1[0]), m = stoi(t1[1]), r = stoi(t1[2]);
        vector<string> t2 = mysplit(tmp[1], ' '), t3 = mysplit(tmp[2], ' ');
        vector<int> nums, querys;
        for(int i = 0; i < r; i++) nums.push_back(INT_MIN);
        for(auto c: t2) nums.push_back(stoi(c));
        for(int i = 0; i < r; i++) nums.push_back(INT_MIN);
        for(auto c: t3) querys.push_back(stoi(c));
        vector<int> ans;
        //int Max = INT_MIN;
        //for(int i = 0; i < r*2; i++){
        //    Max = max(Max, nums[i]);
        //    if(i >= r) ans.push_back(Max);
        //}
        deque<int> q;
        int k = r*2+1;
        for (int i = 0; i < nums.size(); i++) {
            if (!q.empty() && q.front() == i - k) q.pop_front();
            while (!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if (i >= k - 1) ans.push_back(nums[q.front()]);
        }
        for(int i = 0; i < m; i++){
            cout << ans[querys[i]-1];
            if(i < m-1) cout << " ";
            else cout << endl;
        }
    }

    return 0;
}