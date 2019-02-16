#include<cstdio>
#define re register
#define in inline
#define int long long
#define lc p<<1
#define rc (p<<1)+1
in int read()
{
	int s=0,b=0;char ch;
	do{ch=getchar();if(ch=='-') b=1;}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9'){s=(s<<3)+(s<<1)+(ch^48);ch=getchar();}
	return b?-s:s;
}
const int N=100001;
int n,m,c[N];
struct SegmentTree{
	int l,r,sum,add;
}t[N*4];
void build(int p,int l,int r)
{
	t[p].l=l,t[p].r=r;
	if(l==r) {t[p].sum=c[l];return;}
	int mid=(l+r)>>1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	t[p].sum=t[lc].sum+t[rc].sum;
}
in void spread(int p)
{
	if(!t[p].add) return;
	t[lc].add+=t[p].add,t[rc].add+=t[p].add;
	t[lc].sum+=t[p].add*(t[lc].r-t[lc].l+1);
	t[rc].sum+=t[p].add*(t[rc].r-t[rc].l+1);
	t[p].add=0;
}
int ask(int p,int l,int r)
{
	if(l<=t[p].l&&t[p].r<=r) return t[p].sum;
	spread(p);
	int mid=(t[p].l+t[p].r)>>1,ans=0;
	if(l<=mid) ans+=ask(lc,l,r);
	if(r>mid) ans+=ask(rc,l,r);
	return ans;
}
void upd(int p,int l,int r,int d)
{
	if(l<=t[p].l&&t[p].r<=r) {t[p].add+=d,t[p].sum+=d*(t[p].r-t[p].l+1);return;}
	spread(p);
	int mid=(t[p].l+t[p].r)>>1;
	if(l<=mid) upd(lc,l,r,d);
	if(r>mid) upd(rc,l,r,d);
	t[p].sum=t[lc].sum+t[rc].sum;
}
signed main()
{
	n=read();
	m=read();
	for(re int i=1;i<=n;++i) c[i]=read();
	build(1,1,n);
	for(re int i=1;i<=m;++i)
	{
		int x,y,z;
		x=read();
		if(x==1) {x=read(),y=read(),z=read();upd(1,x,y,z);}
		else {x=read(),y=read();printf("%lld\n",ask(1,x,y));}
	}
	return 0;
}
