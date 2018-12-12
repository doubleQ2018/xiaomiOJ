// Author : Qi Zhang
// Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

vector<int> getNext(string &p){
    int len = p.size();
    vector<int> next(len);
    next[0] = 0 ;
    int i = 0 , j = 0 ;
    for(j = 1 ; j < len ; j++) {
        while( p[i] != p[j] && i > 0  )
            i = next[i-1] ;
        if(p[i] == p[j])    {
            i++ ;
            next[j] = i ;
        }
        else
            next[j] = 0 ;
    }
    return next;
}

int main()
{
    string s;
    while (getline(cin, s)) {
        vector<int> next = getNext(s);
        //for(auto a: next) cout << a << endl;
        int n = s.size(), count = 1;
        string ans;
        for(int i = 0; i < n; i++){
            if(i == 0){
                ans += s[i];
                next[i] = 1;
                continue;
            }
            if(next[i] == 0){
                count++;
                next[i] = next[i-1] + 1;
                if(next[i] > ans.size()) ans += s[i];
            }
            else{
                if(next[i] > ans.size() && count > 1) ans = s.substr(0, next[i]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}