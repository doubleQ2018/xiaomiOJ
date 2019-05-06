// Author : Qi Zhang
// Date   : 2019-05-06

#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

#define maxn 1000000
int cc[maxn+5] = {0};
int nums[10000005] = {0};
void init(int n)
{
    int x = sqrt(n);
    for (int i = 1; i <= x; i++){
        for (int j = i + 1; j * i <= n; j++) cc[i * j] += 2;
        cc[i * i]++;
    }
}

int main(){
    init(maxn);
    int k, n;
    cin >> k >> n;
    for(int i = 0; i < n; i++) cin >> nums[i];
    sort(nums, nums+n, [](const int &x, const int &y){
            if(cc[x] != cc[y]) return cc[x] < cc[y]; else return x < y;});
    cout << nums[k-1] << endl;
}
