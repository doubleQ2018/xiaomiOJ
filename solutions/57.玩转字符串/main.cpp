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
        vector<string> tmp = mysplit(line, ' ');
        string x = tmp[0], y = tmp[1];
        if(x.size() > y.size()){
            cout << "0" << endl;
            continue;
        }
        int i = y.size()-1;
        for(; i >= x.size(); i--){
            if(y[i] == 'B') reverse(y.begin(), y.begin()+i);
        }
        bool ans = true;
        for(int i = 0; i < x.size(); i++)
            if(x[i] != y[i]){
                ans = false;
                break;
            }
        cout << (ans? "1": "0") << endl;
    }

    return 0;
}