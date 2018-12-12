// Author : Qi Zhang
// Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

vector<string> mysplit(string &s, char t){
    vector<string> info;
    string cur;
    for(auto c: s){
        if(c == t){
            if(cur != "") info.push_back(cur);
            cur = "";
        }
        else cur += c;
    }
    if(cur != "") info.push_back(cur);
    return info;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string> vv = mysplit(line, ' ');
        stack<int> nums;
        stack<string> ops;
        bool err = false;
        for(auto v: vv){
            if(v == "+" || v == "-" || v == "*" || v == "/") ops.push(v);
            else{
                int val = stoi(v);
                if(!ops.empty() && (ops.top() == "*" || ops.top() == "/")){
                    if(ops.top() == "*") {
                        int tmp = val * nums.top();
                        nums.pop();
                        nums.push(tmp);
                    }
                    if(ops.top() == "/") {
                        if(val == 0){
                            err = true;
                            break;
                        }
                        int tmp = nums.top() / val;
                        nums.pop();
                        nums.push(tmp);
                    }
                    ops.pop();
                }
                else nums.push(val);
            }
        }
        if(err){
            cout << "err" << endl;
            continue;
        }
        int ans = 0;
        while(!ops.empty()){
            int b = nums.top(); nums.pop();
            if(ops.top() == "+") ans += b;
            else ans -= b;
            ops.pop();
        }
        cout << ans + nums.top() << endl;

    }

    return 0;
}