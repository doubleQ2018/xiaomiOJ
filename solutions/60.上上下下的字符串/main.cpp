
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line)) {
        int n = line.size();
        string ans;
        for(int i = 0; i <= n; i++) ans += char('1'+i);
        int pre = -1;
        for(int i = 0; i < n; i++){
            char cur = line[i];
            if(cur == '+') {
                if(i - pre > 1){
                    int p = i, len = i-pre;
                    reverse(ans.begin()+p-len+1, ans.begin()+p+1);
                }
                pre = i;
            }
        }
        if(pre < n-1) {
            int p = n, len = n-pre;
            reverse(ans.begin()+p-len+1, ans.begin()+p+1);
        }
        cout << ans << endl;
    }

    return 0;
}