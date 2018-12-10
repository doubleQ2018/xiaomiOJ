
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
        vector<string> tmp = mysplit(line, ';');
        vector<vector<int>> mat;
        for(auto t: tmp){
            vector<int> nums;
            vector<string> tt = mysplit(t, ',');
            for(auto c: tt) nums.push_back(stoi(c));
            mat.push_back(nums);
        }
        int ans = 0;
        for(int i = 0; i < mat.size()-1; i++){
            for(int j = 0; j < mat[i].size()-1; j++)
                ans = max(ans, mat[i][j]+mat[i+1][j+1]);
        }
        cout << ans << endl;
    }

    return 0;
}