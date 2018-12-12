// Author : Qi Zhang
// Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line)) {
        int n = line.size(), ans = 0;
        int i = 0;
        while(i < n && line[i] == '?') i++;
        if(i == n){
            cout << ans << endl;
            continue;
        }
        i++;
        for(; i < n; i++){
            if(line[i] == '?') {
                if(line[i-1] == 'a') line[i] = 'b';
                else line[i] = 'a';
            }
            else{
                if(line[i] == line[i-1]) ans++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}