
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
        vector<string> tmp = mysplit(line, ' ');
        double a = stod(tmp[0]), b = stod(tmp[1]);
        double hux = b - (100 + a * 10);
        double x = (100 + 85) * (1 - hux / (602 + hux));
        double huy = b * (1 - 0.45);
        double y = (100 + 80) * (1 - huy / (602 + huy));
        if(x > y) cout << "axe" << endl;
        else if(x < y) cout << "bow" << endl;
        else cout << "same" << endl;
    }

    return 0;
}