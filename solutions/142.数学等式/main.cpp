// Author : Qi Zhang
// Date   : 2019-03-30

#include <bits/stdc++.h>

using namespace std;

const int N = 50, MAX = N * N * N * N * 4 + 1;
short H[MAX + 7];

int main(){
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    memset(H, 0, sizeof H);
    for (int i = -N; i <= N; ++i) {
        if(i == 0) continue;
        int p = a * i * i * i;
        for (int j = -N; j <= N; ++j) {
            if(j == 0) continue;
            int left = -(p + b * j * j * j);
            if(left < 0) left = left + MAX;
            H[left]++;
        }
    }
    int res = 0;
    for (int i = -N; i <= N; ++i) {
        if(i == 0) continue;
        int p = c * i * i * i;
        for(int j = -N; j <= N; ++j) {
            if(j == 0) continue;
            int q = p + d * j * j * j;
            for (int k = -N; k <= N; ++k) {
                if(k == 0) continue;
                int right = q + e * k * k * k;
                if(right > MAX / 2) continue;
                if(right < 0) right += MAX;
                res += H[right];
            }
        }
    }
    cout << res << endl;
}