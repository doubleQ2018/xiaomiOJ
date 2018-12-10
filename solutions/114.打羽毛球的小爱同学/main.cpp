
#include <bits/stdc++.h>

using namespace std;

const long long mod = 998244353;

long long mypow(long long n){
    if(n < 0) return 0;
    else if(n == 0) return 1;
    else{
        long long tmp = mypow(n/2) % mod;
        if((n & 0x1) == 1) return 2*tmp*tmp % mod;
        else return tmp*tmp % mod;
    }
}

int main(){
    long long a, b, c, d;
    while(cin >> a >> b >> c >> d){
        long long ans = mypow(c) * ((mypow(d) + mod - 1 - d)%mod) % mod;
        //cout << ans << endl;
        if(b >= 1) ans += (b * mypow(c) % mod) * (mypow(d)-1) % mod;
        //cout << ans << endl;
        if(b >= 2) ans += ((mypow(b)+mod-1-b) % mod) * (mypow(c+d)-1) % mod;
        ans *= mypow(a);
        ans %= mod;
        ans = (mypow(a+b+c+d) + mod - ans) % mod;
        cout << ans << endl;
    }
}