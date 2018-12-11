# Author : Qi Zhang
# Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

bool ispow1(long long val){
    double mi = log(double(val)) / log(2);
    cout << mi << endl;
    if(abs(mi-floor(mi)) < 1e-10) return true;
    else return false;
}

bool ispow(long long val){
    while(val > 1){
        if((val & 0x1) == 1) return false;
        val /= 2;
    }
    return true;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        long long n = stoll(line);
        if(n == 0 || n == 1) cout << "Bad" << endl;
        else if(n == 2) cout << "Good" << endl;
        else if(n == 3) cout << "Very Good" << endl;
        else{
            if(ispow(n-1)) cout << "Good" << endl;
            else if(ispow(n+1)) cout << "Bad" << endl;
            else cout << "Normal" << endl;
        }
    }

    return 0;
}