// Author : Qi Zhang
// Date   : 2019-01-16

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
        vector<string> l = mysplit(line, ' ');
        vector<int> nums;
        for(auto s: l) nums.push_back(stoi(s));
        vector<int> count(1000002, 0);
        for(int i = 0; i < nums.size()/4; i++){
            int l = nums[4*i+1], r = nums[4*i+2], k = nums[4*i+3];
            count[l] += k;
            count[r] -= k;
        }
        for(int i = 1; i < 1000002; i++) {
            count[i] += count[i-1];
            //cout << count[i] << endl;
        }
        cout << *max_element(count.begin(), count.end()) << endl;
    }

    return 0;
}