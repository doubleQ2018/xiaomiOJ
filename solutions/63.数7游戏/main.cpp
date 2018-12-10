
#include <bits/stdc++.h>

using namespace std;

bool check(int val){
    if(val % 7 == 0) return true;
    while(val){
        if(val % 10 == 7) return true;
        val /= 10;
    }
    return false;
}

int main()
{
    vector<int> nums;
    int val = 1;
    while(nums.size() < 100000){
        if(!check(val)) nums.push_back(val);
        val++;
    }
    string line;
    while (getline(cin, line)) {
        int n = stoi(line);
        cout << nums[n-1] << endl;
    }

    return 0;
}