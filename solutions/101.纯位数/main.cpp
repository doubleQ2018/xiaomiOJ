# Author : Qi Zhang
# Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

int main()
{
    string line;
    while (getline(cin, line)) {
        long long n = stoll(line), ans = LLONG_MAX;
        for(long long i = 1; i <= (long long)sqrt(n); i++){
            if(n % i != 0) continue;
            long long sum = n/i;
            //cout << "a = " << i << ", target = " << n/i << endl;
            for(long long j = 2; j <= (long long)(log(sum)/log(i+1))+1; j++){
                //cout << "length = " << j << endl;
                long long l = i+1, r = (int)pow(sum, 1.0/(j-1));
                while(l <= r){
                    long long mid = (r-l)/2 + l, s = 1;
                    for(long long k = 0; k < j; k++) s *= mid;
                    long long cur = (s-1)/(mid-1);
                    //cout << "b = " << mid << " sum = " << cur << endl;
                    if(cur > sum) r = mid-1;
                    else if(cur < sum) l = mid+1;
                    else{
                        ans = min(ans, mid);
                        break;
                    }
                }
            }
        }
        if(ans == LLONG_MAX) cout << n+1 << endl;
        else cout << ans << endl;
    }

    return 0;
}