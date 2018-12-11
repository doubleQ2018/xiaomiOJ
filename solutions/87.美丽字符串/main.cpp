# Author : Qi Zhang
# Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<int> count(26);
        for(auto c: line) count[int(c-'a')]++;
        unordered_map<int, int> times;
        int num = 0;
        for(auto c: count) {
            if(c > 0){
                num++;
                times[c]++;
            }
        }
        if(times.size() == 1){
            cout << "YES" << endl;
            continue;
        }
        if(times.size() == 2){
            auto it = times.begin();
            pair<int, int> a = *it;
            ++it;
            pair<int, int> b = *it;
            bool ans = false;
            if(a.second == num-1 && abs(b.first - a.first) == 1) ans = true;
            if(b.second == num-1 && abs(b.first - a.first) == 1) ans = true;
            if(ans) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        else cout << "NO" << endl;
    }

    return 0;
}