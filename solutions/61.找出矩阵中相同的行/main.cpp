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
        vector<string> lines = mysplit(line, ';');
        unordered_map<string, int> mp;
        int x, y;
        for(int i = 0; i < lines.size(); i++){
            if(mp.find(lines[i]) != mp.end()) {
                x = mp[lines[i]];
                y = i+1;
                break;
            }
            else mp[lines[i]] = i+1;
        }
        cout << x << "," << y << endl;
    }

    return 0;
}