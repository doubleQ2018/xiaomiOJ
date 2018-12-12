// Author : Qi Zhang
// Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line)) {
        long long n = stoll(line);
        unordered_set<long long> vis;
        while(n != 1){
            //cout << n << endl;
            long long cur = 0;
            while(n){
                long long d = n % 10;
                cur += d * d;
                n /= 10;
            }
            if(vis.find(cur) != vis.end()) break;
            vis.insert(cur);
            n = cur;
        }
        if(n == 1) cout << "true" << endl;
        else cout << "false" << endl;
    }

    return 0;
}