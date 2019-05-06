// Author : Qi Zhang
// Date   : 2019-05-06

#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<pair<long long, long long>> pp(n);
    for(long long i = 0; i < n; i++) cin >> pp[i].first >> pp[i].second;
    sort(pp.begin(), pp.end());
    priority_queue<long long, vector<long long>, greater<long long>> q;
    long long ans = 0;
    for(long long i = 0; i < n; i++){
        long long l = pp[i].first, r = pp[i].second;
        if(q.empty() || l <= q.top()) ans++;
        else q.pop();
        q.push(r);
    }
    cout << ans << endl;
}