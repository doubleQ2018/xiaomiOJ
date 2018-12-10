
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line)) {
        int n = line.size(), ans = 0;
        vector<int> times(n+1, 0);
        for(int i = 0; i < n; i++){
            int cur = line[i] - '0';
            if((cur+times[i+1]) % 2 != 0){
                ans++;
                for(int j = i+1; j <= n; j += i+1) times[j]++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}