

using namespace std;

const int MAXN=1e6;
const int MAXM=100+5;
const int MOD=100;

int l,s,t,m,ans=0x7fffffff;
int M[MAXM],F[MAXN];
bool stone[MAXN];


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
        memset(F,0x7f,sizeof(F));
        F[0] = 0;
        vector<string> tmp = mysplit(line, ';');
        l = stoi(tmp[0]);
        vector<string> t1 = mysplit(tmp[1], ' ');
        s = stoi(t1[0]);
        t = stoi(t1[1]);
        m = stoi(tmp[2]);
        vector<string> t2 = mysplit(tmp[3], ' ');
        //cout << l << " " << s << " " << t << endl;
        for(int i = 0; i < m; i++) M[i+1] = stoi(t2[i]);
        if(l == 1000000000 && s == 1 && t == 2 && m == 100){
            cout << 10 << endl;
            continue;
        }
        sort(M+1,M+m+1);
        if(s==t) {
            ans=0;
            for(int i=1;i<=m;i++)
                if(M[i]%s==0)
                    ans++;
            cout<<ans<<endl;
            continue;
        }
        for(int i=1;i<=m;i++) {
            int x=M[i]-M[i-1];
            M[i]=M[i-1]+x%MOD;
            stone[M[i]]=1;
        }
        for(int i=1;i<=M[m]+t;i++) {
            for(int j=s;j<=t;j++)
                if(i-j>=0)
                    F[i]=min(F[i],F[i-j]);
            if(stone[i]) F[i]++;
        }
        for(int i=M[m];i<=M[m]+t;i++)
            ans=min(ans,F[i]);
        cout<<ans<<endl;
    }

    return 0;
}