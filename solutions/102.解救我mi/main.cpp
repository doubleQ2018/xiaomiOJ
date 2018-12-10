
#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line)) {
        stack<char> st;
        for(auto c: line){
            if(c == 'i' && !st.empty() && st.top() == 'm') st.pop();
            else st.push(c);
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }

    return 0;
}