
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



void permulation(vector<int> nums, int p){
    if(p == nums.size()){
        bool isend = true;
        for(int i = 0; i < nums.size()-1; i++)
            if(nums[i] < nums[i+1]){
                isend = false;
                break;
            }
        for(int i = 0; i < nums.size(); i++){
            cout << nums[i];
            if(i < nums.size() -1) cout << ",";
            else {
                if(isend) cout << endl;
                else cout << ";";
            }
        }
        return;
    }
    for(int i = p; i < nums.size(); i++){
        swap(nums[p], nums[i]);
        permulation(nums, p+1);
    }
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string> tmp = mysplit(line, ',');
        vector<int> nums;
        for(auto c: tmp) nums.push_back(stoi(c));
        sort(nums.begin(), nums.end());
        permulation(nums, 0);
    }

    return 0;
}