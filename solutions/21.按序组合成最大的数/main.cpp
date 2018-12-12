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

bool compare(vector<int>& nums1, int i,vector<int>& nums2,int j) {
    while (i < nums1.size() && j < nums2.size() && nums1[i] == nums2[j]) {
        i++;
        j++;
    }
    return j == nums2.size() || (i < nums1.size() && nums1[i] > nums2[j]);
}



vector<int> merge(vector<int>& nums1, vector<int>& nums2,int k) {
    vector<int> res(nums1.size()+nums2.size());
    for (int i = 0, j = 0, r = 0; r < k; ++r)
        res[r] = compare(nums1, i, nums2, j) ? nums1[i++] : nums2[j++];
    return res;
}

vector<int> maxNumber1(vector<int>& nums1,int k){
    int n = nums1.size();
    vector<int> ans(k);
    for (int i = 0, j = 0; i < n; ++i) {
        while (n - i + j > k && j > 0 && ans[j - 1] < nums1[i])
            j--;
        if (j < k)
            ans[j++] = nums1[i];
    }
    return ans;
}

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
    int n = nums1.size();
    int m = nums2.size();
    vector<int> res(k);
    for (int i = max(0, k - m); i <= k && i <= n; ++i) {
        vector<int> temp1 = maxNumber1(nums1, i);
        vector<int> temp2 = maxNumber1(nums2, k-i);
        vector<int> candidate = merge(temp1,temp2, k);
        if (compare(candidate, 0, res, 0))
            res = candidate;
    }
    return res;

}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string> tmp = mysplit(line, ' ');
        int k = stoi(tmp.back());
        vector<string> s1 = mysplit(tmp[0], ','), s2 = mysplit(tmp[1], ',');
        vector<int> nums1, nums2;
        for(auto v: s1) nums1.push_back(stoi(v));
        for(auto v: s2) nums2.push_back(stoi(v));
        vector<int> ans = maxNumber(nums1, nums2, k);
        string res;
        for(auto a: ans) res += to_string(a);
        cout << res << endl;
    }

    return 0;
}