
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
        vector<string> tmp = mysplit(line, ',');
        int n = stoi(tmp[0]);
        int k = stoi(tmp[1]);
        int m = stoi(tmp[2]);
        if(m > k) cout << "0" << endl;
        else{
            int r = (k-m) % 16;
            if(r < 8) cout << "1" <<endl;
            else cout << "0" << endl;
        }
    }

    return 0;
}