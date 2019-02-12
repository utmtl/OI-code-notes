/*
ans=(f-sum(c))/sum(ti)
f-sum(c)-ans*sum(ti)=0 f关于ans单调
即 f=sum(c+ans*ti), 二分查找ans即可
chk()中对于每个ans把c_i+ans*ti_i作为e[i]的边权跑最小生成树即可判断与f关系
//本程序中f叫做ct(cost_total)
*/
#include<cstdio>
#include<algorithm>
#define int long long
#define db double
#define in inline
#define re register
in int read()
{
	int s=0,b=0;
	char ch;
	do{
		ch=getchar();
		if(ch=='-') b=1;
	}while(ch<'0' || ch>'9');
	while(ch>='0' && ch<='9')
	{
		s=(s<<3)+(s<<1)+(ch^48);
		ch=getchar();
	}
	return b?-s:s;
}
in db fabs(db x)
{
	return x>0?x:-x;
}
int n,m,ct;
struct edge{
	int f,t,c,ti;
	db w;
	bool operator < (const edge &t)const
		{
			return w<t.w;
		}
}e[10010];
int f[500];
int findd(int x)
{
	if(f[x]!=x)	f[x]=findd(f[x]);
	return f[x];
}
bool chk(db ans)
{
	for(re int i=1;i<=n;++i) f[i]=i;
	for(re int i=1;i<=m;++i) e[i].w=(db)e[i].ti*ans+(db)e[i].c;
	std::sort(e+1,e+m+1);
	int cnt=0;
	db sum=0;
	for(re int i=1;i<=m;++i)
	{
		int r1=findd(e[i].f),r2=findd(e[i].t);
		if(r1==r2) continue;
		f[r1]=r2;
		sum+=e[i].w;
		++cnt;
		if(cnt==n-1) break;
	}
	if(sum>ct) return false;
	else return true;
}
signed main()
{
	n=read();
	m=read();
	ct=read();
	for(re int i=1;i<=m;++i)
		e[i].f=read(),e[i].t=read(),e[i].c=read(),e[i].ti=read();
	db l=0,r=1e20,eps=1e-6;
	while(fabs(l-r)>eps)//实数域二分
	{
		db mid=(l+r)/2;
		if(chk(mid)) l=mid;
		else r=mid;
	}
	printf("%0.4lf\n",l);
	return 0;
}
