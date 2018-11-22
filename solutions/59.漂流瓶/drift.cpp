// Author : Qi Zhang
// Date   : 2018-11-22

#include <iostream>
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

vector<int> dx{1,0,-1,0};
vector<int> dy{0,-1,0,1};

void dfs(int n,int m,vector<vector<int>>& matrix,vector<vector<int>> &vis,int height,int x,int y){
    if(x<0||y<0||x>=n||y>=m||vis[x][y]||matrix[x][y]<height)return;
    vis[x][y]=1;
    for(int k=0;k<4;k++){
        int xx=x+dx[k];
        int yy=y+dy[k];
        dfs(n,m,matrix,vis,matrix[x][y],xx,yy);
    }
}
vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if(matrix.empty())return {};
    int n=matrix.size(),m=matrix[0].size();
    vector<pair<int, int>>res;
    vector<vector<int>> pacific(n,vector<int>(m,0));
    vector<vector<int> >atlantic(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        dfs(n,m,matrix,pacific,0,i,0);
        dfs(n,m,matrix,atlantic,0,i,m-1);
    }
    for(int i=0;i<m;i++){
        dfs(n,m,matrix,pacific,0,0,i);
        dfs(n,m,matrix,atlantic,0,n-1,i);
    }
   for(int i=0;i<n;i++){
       for(int j=0;j<m;j++){
           if(pacific[i][j]&&atlantic[i][j]){
               res.push_back({i,j});
           }
       }
   }
   return res;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string> tmp = mysplit(line, ';');
        vector<vector<int>> mat;
        for(auto l: tmp){
            vector<int> nums;
            vector<string> t = mysplit(l, ',');
            for(auto c: t) nums.push_back(stoi(c));
            mat.push_back(nums);
        }
        vector<pair<int, int>> res = pacificAtlantic(mat);
        for(int i = 0; i < res.size(); i++){
            cout << res[i].first << "," << res[i].second;
            if(i < res.size()-1) cout << ";";
            else cout << endl;
        }
    }

    return 0;
}
