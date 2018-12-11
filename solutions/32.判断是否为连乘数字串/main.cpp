# Author : Qi Zhang
# Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

string multiply(string num1, string num2) {
  string res(num1.size() + num2.size(), '0');
  for (int i = num1.size() - 1; i >= 0; i--) {
    for (int j = num2.size() - 1; j >= 0; j--) {
        int prod =  (num1[i] - '0') * (num2[j] - '0') +  (res[i + j + 1] - '0');
        res[i+j+1] = (prod % 10) + '0';
        res[i+j] = ((prod /10) + (res[i + j] - '0')) + '0';
    }
  }
  int it = res.find_first_not_of("0");
  return ( it < 0  ? "0" : res.substr(it) );
}

bool check(string &s, int p, string a, string b){
    if(p == s.size()) return true;
    string c = multiply(a, b);
    int l = c.size();
    if(p+l <= s.size() && s.substr(p, l) == c) return check(s, p+l, b, c);
    else return false;
}

int main()
{
    string s;
    while (getline(cin, s)) {
        int n = s.size();
        bool ans = false;
        for(int i = 0; i < n; i++){
            if(ans) break;
            for(int j = i+1; j < n; j++){
                string a = s.substr(0, i+1), b = s.substr(i+1, j-i);
                string mul = multiply(a, b);
                int l = mul.size();
                if(j+l < n && s.substr(j+1, l) == mul && check(s, j+1, a, b)) {
                    ans = true;
                    break;
                }
            }
        }
        cout << (ans? "true": "false") << endl;

    }

    return 0;
}