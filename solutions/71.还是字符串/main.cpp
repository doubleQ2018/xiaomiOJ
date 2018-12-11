# Author : Qi Zhang
# Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

int magicalString(int n) {
    string s = "122";
    char w = '1';
    int i = 2, t = 3;

    while(t <= n)
    {
        if(w == '1')
        {
            int x = s[i]-'0';
            s += (x==1 ? "1" : "11");
            t += x;
            w = '2';
            i++;
        }
        else
        {
            int x = s[i]-'0';
            s += (x==1 ? "2" : "22");
            t += x;
            w = '1';
            i++;
        }

    }
    int res = 0;
    for(int i = 0; i < n; i++)
        if(s[i] == '1') res++;
    return res;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        int n = stoi(line);
        cout << magicalString(n) << endl;
    }

    return 0;
}