// Author : Qi Zhang
// Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line)) {
        long long n = stoi(line);
        vector<vector<long long>> dp(n, vector<long long>(3, 0));
        for(long long i = 0; i < n; i++){
            for(long long j = 0; j < 3; j++){
                if(i == 0) dp[i][j] = 1;
                else if(i == 1){
                    for(long long k = 0; k < 3; k++) dp[i][j] += dp[i-1][k];
                }
                else {
                    for(long long k = 0; k < 3; k++){
                        if(j != k)
                            dp[i][j] += dp[i-1][k] + dp[i-2][k];
                    }
                }
            }
        }
        long long ans = 0;
        for(auto val: dp[n-1]) ans += val;
        cout << ans << endl;
    }

    return 0;
}