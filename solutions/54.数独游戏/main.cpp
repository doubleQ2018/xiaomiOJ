
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

bool check(vector<vector<string>>& board) {
    vector<unordered_set<string>> row(9), column(9), box(9);
    int m = board.size(), n = board[0].size();
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            string c = board[i][j];
            if(c == "-") continue;
            if(row[i].find(c) != row[i].end()) return false;
            if(column[j].find(c) != column[j].end()) return false;
            int pos = i/3 * 3 + j/3;
            if(box[pos].find(c) != box[pos].end()) return false;
            row[i].insert(c);
            column[j].insert(c);
            box[pos].insert(c);
        }
    }
    return true;
}

int main()
{
    string line;
    while (getline(cin, line)) {
        vector<string> tmp = mysplit(line, ' ');
        vector<vector<string>> chess(9, vector<string>(9));
        for(int b = 0; b < 9; b++){
            vector<string> t = mysplit(tmp[b], ',');
            int startx = b/3*3, starty = (b%3)*3, k = 0;
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++)
                    chess[startx+i][starty+j] = t[k++];
        }
        if(check(chess)) cout << "true" << endl;
        else cout << "false" << endl;
    }

    return 0;
}