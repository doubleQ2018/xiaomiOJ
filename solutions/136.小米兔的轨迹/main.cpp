// Author : Qi Zhang
// Date   : 2019-04-29

#include <bits/stdc++.h>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int m = matrix.size();
    if(m == 0) return {};
    int n = matrix[0].size();
    int step = 0;
    vector<int> ans;
    while(step < (min(m, n)+1)/2){
        int i = step, j = step;
        if(i == m-step-1)
            while(j < n-step) ans.push_back(matrix[i][j++]);
        else if(j == n-step-1)
            while(i < m-step) ans.push_back(matrix[i++][j]);
        else{
            while(j < n-step-1) ans.push_back(matrix[i][j++]);
            while(i < m-step-1) ans.push_back(matrix[i++][j]);
            while(j > step) ans.push_back(matrix[i][j--]);
            while(i > step) ans.push_back(matrix[i--][j]);
        }
        step++;
    }
    return ans;
}

int main(){
   int m, n;
   cin >> m >> n;
   vector<vector<int>> mat(m, vector<int>(n));
   for(int i = 0; i < m; i++)
       for(int j = 0; j < n; j++)
           cin >> mat[i][j];
   vector<int> ans = spiralOrder(mat);
   for(int i = 0; i < ans.size(); i++){
       cout << ans[i];
       if(i < ans.size()-1) cout << " ";
       else cout << endl;
   }
}