
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<int> times(3, 0);
        for(auto c: line) times[int(c-'a')]++;
        string ans;
        for(int i = 0; i < times[0]; i++) ans += 'a';
        for(int i = 0; i < times[1]; i++) ans += 'b';
        for(int i = 0; i < times[2]; i++) ans += 'c';
        cout << ans << endl;
    }
    return 0;
}