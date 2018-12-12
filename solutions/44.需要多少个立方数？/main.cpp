// Author : Qi Zhang
// Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    vector<int> dp(1000005, 1000005);
    dp[0] = 0;
    int maxn = 0;
    while(getline(cin, s)) {
        int n = stoi(s);
        if(n <= maxn) cout << dp[n] << endl;
        else {
            int m = pow(n, 1.0 / 3);
            for(int i = 1; i <= m; ++ i) {
                for(int v = max(maxn, i * i * i); v <= n; ++ v) {
                    dp[v] = min(dp[v], dp[v - i * i * i] + 1);
                }
            }
            cout << dp[n] << endl;
            maxn = n;
        }
    }
}