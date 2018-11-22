// Author : Qi Zhang
// Date   : 2018-11-22

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    while(getline(cin, s)) {
        transform(s.begin(), s.end(), s.begin(), [](char& c) {return c == 'd' ? ' ' : c;});
        istringstream is(s);
        int a, b ,c, d;
        is >> a >> b >> c >> d;
        int se = a * 24 + b;
        if(c > b) se ++;
        if(c == b && d == 59) se ++;
        int res = a * 3600 * 24 + b * 3600 + c * 60 + d - se;
        string r;
        a = res / (3600 * 24);
        r = to_string(a) + "d";
        b = (res - a * 3600 * 24) / 3600;
        if(b / 10 == 0)
            r += "0";
        r += to_string(b);
        r += " ";
        c = (res - a * 3600 * 24 - b * 3600) / 60;
        if(c / 10 == 0)
            r += "0";
        r += to_string(c);
        r += " ";
        d = res - a * 3600 * 24 - b * 3600 - c * 60;
        if(d / 10 == 0)
            r += "0";
        r += to_string(d);
        cout << r << endl;
    }
}
