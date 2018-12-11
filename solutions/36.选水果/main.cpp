# Author : Qi Zhang
# Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;


int helper(int n) {
    int total = 2*n, remainder = total, start = 1, next, hit = 0;
    int ans = n+1;
    while(1) {
        next = start + ans - 1;
        next %= remainder;
        if(next > n || next == 0) {
            hit++;
            if(hit == n) return ans;
            remainder--;
            if(next == 0) start = 1;
            else start = next;
        } else {
            remainder = total;
            start = 1;
            hit = 0;
            ans++;
        }
    }
    return -1;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        int n = stoi(line);
        cout << helper(n) << endl;
    }

    return 0;
}