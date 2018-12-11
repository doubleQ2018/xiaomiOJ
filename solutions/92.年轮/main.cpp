# Author : Qi Zhang
# Date   : 2018-12-11


#include <bits/stdc++.h>

using namespace std;

struct Point
{
     double x;
     double y;
     Point() : x(0), y(0) {}
     Point(double a, double b) : x(a), y(b) {}
};

double crossProduct(Point A, Point B, Point C)
{
    double BAx = A.x - B.x;
    double BAy = A.y - B.y;
    double BCx = C.x - B.x;
    double BCy = C.y - B.y;
    return BAx * BCy - BAy * BCx;
}

double dist(Point A, Point B)
{
    return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

bool check(unordered_set<int>& res, Point p, vector<Point> &points)
{
    for (auto i: res)
    {
        if (points[i].x == p.x && points[i].y == p.y)
            return false;
    }
    return true;
}

unordered_set<int> convex(vector<Point>& points) {
    unordered_set<int> res;
    Point first = points[0];
    int firstIdx = 0, n = points.size();
    for (int i = 1; i < n; ++i) {
        if (points[i].x < first.x) {
            first = points[i];
            firstIdx = i;
        }
    }
    res.insert(firstIdx);
    Point cur = first;
    int curIdx = firstIdx;
    while (true) {
        Point next = points[0];
        int nextIdx = 0;
        for (int i = 1; i < n; ++i) {
            if (i == curIdx) continue;
            int cross = crossProduct(cur, points[i], next);
            if (nextIdx == curIdx || cross > 0 || (cross == 0 && dist(points[i], cur) > dist(next, cur))) {
                next = points[i];
                nextIdx = i;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (i == curIdx) continue;
            int cross = crossProduct(cur, points[i], next);
            if (cross == 0) {
                if (check(res, points[i], points)) res.insert(i);
            }
        }
        cur = next;
        curIdx = nextIdx;
        if (curIdx == firstIdx) break;
    }
    return res;
}


vector<string> mysplit(string s, char t){
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
        int n = stoi(tmp[0]);
        vector<Point> points(n);
        for(int i = 1; i <= n; i++){
            vector<string> xy = mysplit(tmp[i], ',');
            points[i-1].x = stod(xy[0]);
            points[i-1].y = stod(xy[1]);
        }
        vector<bool> vis(n, false);
        vector<Point> cur = points, bf;
        int ans = 0;
        while(true){
            if(cur.size() < 3) break;
            unordered_set<int> index = convex(cur);
            bf = cur;
            ans++;
            //for(auto i: index) cout << i << " ";
            //cout << endl;
            vector<Point> tmp;
            for(int i = 0; i < cur.size(); i++)
                if(index.find(i) == index.end())
                    tmp.push_back(cur[i]);
            cur = tmp;
        }
        if(cur.size() == 0){
            cur = bf;
            unordered_set<double> st;
            for(int i = 1; i < cur.size(); i++){
                if(cur[i].x == cur[0].x) st.insert(INT_MAX);
                else st.insert((cur[i].y-cur[0].y)/(cur[i].x-cur[0].x));
            }
            if(st.size() == 1) ans--;
        }

        cout << ans << endl;
    }

    return 0;
}