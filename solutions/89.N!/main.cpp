// Author : Qi Zhang
// Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line)) {
       int n = stoi(line);
       int r = 5, ans = 0;
       while(n >= 5){
           ans += n/5;
           n /= 5;
       }
       cout << ans << endl;

    }

    return 0;
}