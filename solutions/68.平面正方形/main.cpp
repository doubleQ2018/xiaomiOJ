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

int d(vector<int>& p1, vector<int>& p2) {
    return (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
}
bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
    unordered_set<int> s({ d(p1, p2), d(p1, p3), d(p1, p4), d(p2, p3), d(p2, p4), d(p3, p4) });
    return !s.count(0) && s.size() == 2;
}
int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string> tmp = mysplit(line, ';');
        vector<vector<int>> points;
        for(auto t: tmp){
            vector<string> nums = mysplit(t, ',');
            points.push_back(vector<int>{stoi(nums[0]), stoi(nums[1])});
        }
        cout << (validSquare(points[0], points[1], points[2], points[3])? "1": "0") << endl;
    }

    return 0;
}