// Author : Qi Zhang
// Date   : 2019-03-27

#include <bits/stdc++.h>

using namespace std;

int main(){
    long long l, r;
    cin >> l >> r;
    long long ans = (l + r) % 15 * (r - l + 1) % 15 * 8 % 15;
    cout << ans << endl;
}