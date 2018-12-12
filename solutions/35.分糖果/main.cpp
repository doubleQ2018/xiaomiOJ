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
        vector<string> tmp = mysplit(line, ',');
        int m = stoi(tmp[0]), n = stoi(tmp[1]);
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(m+1, vector<int>(m+1, 0)));
        dp[0][0][0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j <= m; j++){
                for(int k = 0; k <= j; k++){
                    for(int t = 0; t <= k; t++)
                        dp[i+1][j][k] += dp[i][j-k][t];
                }
            }
        }
        int ans = 0;
        for(auto x: dp[n][m]) ans += x;
        cout << ans << endl;
    }

    return 0;
}