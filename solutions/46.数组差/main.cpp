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


int helper(vector<int> nums)
{
    int n = nums.size();
    vector<int> leftMax(n,0);
    vector<int> rightMin(n,0);
    int sum = 0;
    int mx = INT_MIN;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        mx = max(sum,mx);
        if(sum<0)
            sum = 0;
        leftMax[i] = mx;
    }
    sum = 0;
    mx = INT_MAX;
    for(int i=n-1;i>=0;i--)
    {
        sum+=nums[i];
        mx = min(sum,mx);
        if(sum>0)
            sum = 0;
        rightMin[i]=mx;
    }
    int ret = 0;
    for(int i=1;i<n;i++)
    {
        ret = max(ret,abs(leftMax[i-1]-rightMin[i]));
    }
    return ret;
}

int maxDiffSubArrays(vector<int> nums) {
    int x1 = helper(nums);
    reverse(nums.begin(),nums.end());
    int x2 = helper(nums);
    return max(x1,x2);
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string> tmp = mysplit(line, ',');
        vector<int> nums;
        for(auto c: tmp) nums.push_back(stoi(c));
        cout << maxDiffSubArrays(nums) << endl;
    }

    return 0;
}