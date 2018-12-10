
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
        string x = tmp[0];
        int p1 = stoi(tmp[1]), p2 = stoi(tmp[2]);
        int com = 0, d = 1;
        for(int i = x.size()-1; i >= 0; i--){
            char c = x[i];
            int digit = (c >= '0' && c <= '9'? c-'0': c-'a'+10);
            com += digit * d;
            d *= p1;
        }
        string y;
        while(com){
            int r = com % p2;
            char c = (r < 10? '0'+r: 'a'+r-10);
            y += c;
            com /= p2;
        }
        reverse(y.begin(), y.end());
        cout << y << endl;

    }

    return 0;
}