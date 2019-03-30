// Author : Qi Zhang
// Date   : 2019-03-30

#include <bits/stdc++.h>


using namespace std;

const int maxn = 7400000;
bool vis[maxn+10];
long long pri[maxn+10];
long long n, mod, ni;

struct Matrix {
    long long ma[2][2];
};

Matrix mul(Matrix A,Matrix B) {
    Matrix C;
    C.ma[0][0] = C.ma[0][1] = C.ma[1][0] = C.ma[1][1] = 0;
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            for(int k = 0; k < 2; k++) {
                C.ma[i][j] = (C.ma[i][j] + A.ma[i][k] * B.ma[k][j]) % mod;
            }
        }
    }
    return C;
}
Matrix pow_mod(Matrix A, long long n) {
    Matrix B;
    B.ma[0][0] = B.ma[1][1] = 1;
    B.ma[0][1] = B.ma[1][0] = 0;
    while(n) {
        if(n & 1) B = mul(B,A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
long long quick_fibonacci(long long n) {
        Matrix A;
        A.ma[0][0] = 1; A.ma[0][1] = 1;
        A.ma[1][0] = 1; A.ma[1][1] = 0;
        Matrix ans = pow_mod(A, n);
        return ans.ma[0][1];
}

long long extend_gcd(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    else {
        long long r = extend_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return r;
    }
}
long long inv(long long a, long long n) {
    long long x, y;
    extend_gcd(a, n, x, y);
    x = (x % n + n) % n;
    return x;
}

int main() {
    int cur = 5;
    long long i, j;
    for(i = 2; i <= maxn; i++) vis[i] = false;
    for(i = 2; i <= maxn; i++) {
        if(!vis[i]){
            for(j = i*i; j <= maxn; j += i) vis[j] = 1;
        }
    }
    for(i = 11; i <= maxn; i++)
        if(vis[i] == 0) {
            pri[cur++] = i;
        }
    while(cin >> n >> mod){
        ni = inv(3, mod);
        long long ans;
        if(n == 1) ans = 2*ni%mod;
        else if(n == 2) ans = 3*ni%mod;
        else if(n == 3) ans = 5*ni%mod;
        else if(n == 4) ans = 13*ni%mod;
        else ans = quick_fibonacci(pri[n])*ni%mod;
        string res = to_string(ans);
        if(res.size() < 9) res = string(9-res.size(), '*') + res;
        cout << res << endl;
    }
}