# Author : Qi Zhang
# Date   : 2018-12-11



using namespace std;
typedef long long ll;
const int maxn=1e5;
int tree[maxn*4];
ll n;
struct node
{
	ll x,y;
	int id,num;
	bool operator<(const node& t)const
	{
		if(x>n)
		{
			if(t.x<=n)return false;
			return y*(t.x-n)>t.y*(x-n);
		}
		else
		{
			if(t.x>n)return true;
			return y*(n-t.x)<t.y*(n-x);
		}
	}
	bool operator==(const node& t)const
	{
		return (n-x)*t.y==(n-t.x)*y;
	}
}b[maxn];
struct node1
{
	ll x,y;
	int id,pos,v;
	bool operator<(const node1& t)const
	{
		return t.x*y<t.y*x;
	}
	bool operator==(const node1& t)const
	{
		return x*t.y==y*t.x;
	}
}a[maxn],V[maxn];
int d[maxn];
int query(int o,int l,int r,int k)
{
	if(k==0)return 0;
	if(r<=k)
	return tree[o];
	int ls=o*2,rs=o*2+1,m=(l+r)/2;
	int res=0;
	res=max(res,query(ls,l,m,k));
	if(k>m)res=max(res,query(rs,m+1,r,k));
	return res;
}
void update(int o,int l,int r,int k,int v)
{
	if(l==r)
	{
		tree[o]=max(tree[o],v);
		return;
	}
	int ls=o*2,rs=o*2+1,m=(l+r)/2;
	if(k<=m)update(ls,l,m,k,v);
	else update(rs,m+1,r,k,v);
	tree[o]=max(tree[ls],tree[rs]);
}
int main()
{
	int k;
	while(~scanf("%lld",&n))
	{
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			b[i].x=x,b[i].y=y,b[i].id=i;
			a[i].x=x,a[i].y=y,a[i].id=i;
		}
		sort(a+1,a+1+k);
		sort(b+1,b+1+k);
		int sz=0,tot=0;
		b[1].num=++sz;
		for(int i=2;i<=k;i++)
		if(b[i]==b[i-1])b[i].num=b[i-1].num;
		else b[i].num=++sz;
		for(int i=1;i<=k;i++)
		d[b[i].id]=b[i].num;
		memset(tree,0,sizeof(tree));
		for(int i=1;i<=k;i++)
		{
			if(a[i]==a[i-1])
			{
				V[++tot]=a[i];
				int pos=d[a[i].id];
				int v=query(1,1,k,pos-1);
				V[tot].pos=pos,V[tot].v=v+1;
			}
			else
			{
				for(int j=1;j<=tot;j++)
				update(1,1,k,V[j].pos,V[j].v);
				tot=0;
				V[++tot]=a[i];
				int pos=d[a[i].id];
				int v=query(1,1,k,pos-1);
				V[tot].pos=pos,V[tot].v=v+1;		
			}
		}
		for(int j=1;j<=tot;j++)
		update(1,1,k,V[j].pos,V[j].v);
		printf("%d\n",tree[1]);
	}
}
