
#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;

long long cal(long long n){
    if(n == 0) return 1;
    long long ans = cal(n/2) % mod;
    if(n % 2 == 0) return ans*ans % mod;
    else return 3*ans*ans % mod;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        long long n = stoi(line);
        long long ans = cal(n+1);
        ans = (ans - 1 + mod) % mod;
        if(ans % 2 == 0) ans /= 2;
        else ans = (ans+mod) / 2;
        cout << ans << endl;
    }

    return 0;
}