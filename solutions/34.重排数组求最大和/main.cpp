
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
        vector<string> info = mysplit(line, ';');
        int n = stoi(info[0]), q = stoi(info[1]);
        vector<int> nums;
        vector<string> tmp = mysplit(info[2], ' ');
        for(auto val: tmp) nums.push_back(stoi(val));
        vector<int> ca(n+1, 0);
        for(int i = 0; i < q; i++){
            string one = info[i+3];
            vector<string> tt = mysplit(one, ' ');
            int l = stoi(tt[0]), r = stoi(tt[1]);
            ca[l-1]++;
            ca[r]--;
        }
        for(int i = 1; i < n; i++) ca[i] += ca[i-1];
        sort(nums.begin(), nums.end());
        sort(ca.begin(), ca.end()-1);
        int ans = 0;
        for(int i = n-1; i >= 0; i--) ans += nums[i] * ca[i];
        cout << ans << endl;
    }

    return 0;
}