// Author : Qi Zhang
// Date   : 2019-03-30

#include <bits/stdc++.h>

using namespace std;

vector<int> tp(1e5+1, 0);

struct people{
    int arr, wa;
    people(int a, int b): arr(a), wa(b) {}
};

int main(){
    int n, k, q;
    cin >> n >> k >> q;
    for(int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        tp[x] += y;
    }
    int last;
    cin >> last;
    tp[last]++;
    int i = 1;
    queue<people> wash, wait;
    for(;; i++){
        //cout << i << endl;
        while(!wash.empty() && i - wash.front().wa == k) wash.pop();
        int num = tp[i];
        while(i <= last && num--) wait.push(people(i, -1));
        while(wash.size() < n && !wait.empty()) {
            wait.front().wa = i;
            wash.push(wait.front());
            wait.pop();
        }
        if(i > last && wash.empty() && wait.empty()) break;
    }
    cout << i << endl;
}