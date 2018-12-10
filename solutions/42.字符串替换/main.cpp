
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
        string s1 = tmp[0], s2 = tmp[1];
        int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m; i++) dp[i+1][0] = i+1;
        for(int i = 0; i < n; i++) dp[0][i+1] = i+1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j];
                else dp[i+1][j+1] = min(min(dp[i+1][j], dp[i][j+1]), dp[i][j]) + 1;
            }
        }
        cout << dp[m][n] << endl;
    }

    return 0;
}