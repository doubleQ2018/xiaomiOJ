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
        vector<string> ab = mysplit(tmp[0], ' ');
        double A = stod(ab[0]);
        double B = stod(ab[1]);
        vector<double> pos;
        vector<string> nn = mysplit(tmp[1], ' ');
        for(auto num: nn) pos.push_back(stod(num));
        sort(pos.begin(), pos.end());
        int n = pos.size();
        vector<double> cost(n+1, INT_MAX);
        cost[0] = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= i; j++)
                cost[i+1] = min(cost[i+1], cost[j] + (pos[i]-pos[j])/2*B+A);
            //cout << cost[i+1] << endl;
        }
        cout << setiosflags(ios::fixed) << setprecision(1) << cost[n] << endl;
    }

    return 0;
}