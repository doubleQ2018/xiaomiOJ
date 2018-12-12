// Author : Qi Zhang
// Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

long long helper(string s){
    if(s.size() == 1){
        if(stoi(s) < 3) return 0;
        else return 1;
    }
    long long len = s.size();
    long long first = s[0] - '0', firsttime = 0;
    if(first == 3) firsttime = (stoi(s.substr(1)) + 1)/2;
    if(first > 3) firsttime = pow(10, len-1)/2;
    long long othertimes = first * ((len-2)*pow(10, len-2)/2+pow(10, len-2));
    return firsttime + othertimes + helper(s.substr(1));
}

int main()
{
    string line;
    while (getline(cin, line)) {
        cout << helper(line) << endl;
    }

    return 0;
}