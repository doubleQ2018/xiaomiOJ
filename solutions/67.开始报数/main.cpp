
#include <bits/stdc++.h>

using namespace std;


int helper(int time) {
    int n = 500;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) a[i] = i;
    int t = 1, tmp;
    while(n && time > 1) {
        tmp = (t + 3 - 1) % n;
        if(tmp == 0) tmp = n;
        for(int i = tmp; i < n; i++) a[i] = a[i + 1];
        n--;
        time--;
        t = tmp;
    }
    return a[(t+2)%n];
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