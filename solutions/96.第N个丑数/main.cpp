# Author : Qi Zhang
# Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

long long nthUglyNumber(int n) {
    queue<long long> two, three, five;
    two.push(2);
    three.push(3);
    five.push(5);
    long long cur = 1;
    while(n-- > 1){
        long long a = two.front(), b = three.front(), c = five.front();
        if(a < b && a < c){
            cur = a;
            two.pop();
            two.push(cur * 2);
            three.push(cur * 3);
            five.push(cur * 5);
        }
        if(b < a && b < c){
            cur = b;
            three.pop();
            three.push(cur * 3);
            five.push(cur * 5);
        }
        if(c < a && c < b){
            cur = c;
            five.pop();
            five.push(cur * 5);
        }
        //cout << a << ", " << b << ", " << c << endl;
        //if(n < 100) cout << cur << endl;
    }
    return cur;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        int n = stoi(line);
        cout << nthUglyNumber(n) << endl;
    }

    return 0;
}