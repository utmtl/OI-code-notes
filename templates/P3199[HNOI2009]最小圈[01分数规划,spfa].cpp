#include<cstdio>
#include<cstring>
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
int n,m;
struct edge{
	int t,nxt;
	db w,ww;//ww是原边权
}e[20020];
int head[3001],cnt=0;
in void add(int f,int t,db ww)
{
	e[++cnt].t=t;
	e[cnt].ww=ww;
	e[cnt].nxt=head[f];
	head[f]=cnt;
}
int b[3001];
db dis[3001];
int flag;
in void spfa(int u)
{
	b[u]=1;
	for(re int i=head[u];i;i=e[i].nxt)
	{
		if(dis[u]+e[i].w<dis[e[i].t] && !flag)
		{
			dis[e[i].t]=dis[u]+e[i].w;
			if(!b[e[i].t]) spfa(e[i].t);
			else {flag=1;break;}
		}
	}
	b[u]=0;
}//bfs的spfa会tle, dfs版找负环会快得多, 因为它会沿着负环一直走完, 不是一层层的走完
in bool chk(db ans)
{
	for(re int i=1;i<=m;++i) e[i].w=e[i].ww-ans;
	/*
	  0/1分数规划部分, 详见进阶指南P181, P381
	  这道题令点权为1
	  则 ans=sum(e.w)/sum(v.w)
	  sum(e.w)-ans*sum(v.w)=0
	  sum(e.w-ans*v.w)=0
	  sum(e_1~k.w-ans*v_1~k.w)=0 ek,vk在环上
	  sum(e_1~k.w-ans)=0
	  二分ans
	  chk(mid): 图以e_i-mid为边权, 若存在一个负环, 即
	  存在k使 sum(e_1~k.w-mid)<0
	  sum(e.w)<mid*sum(v.w)
	  mid>sum(e.w)/sum(v.w)
	  即 mid>ans
	  则mid要变小, r=mid
	*/
	flag=0;
	for(re int i=1;i<=n;++i)
	{
		memset(b,0,sizeof(b));
		for(re int i=1;i<=n;++i) dis[i]=0;
		spfa(i);
		if(flag) return false;//只要有一个负环, 就说明mid大了
	}
	return true;
}
in db fabs(db x)
{
	return x>0?x:-x;
}
signed main()
{
	n=read();
	m=read();
	for(re int i=1;i<=m;++i)
	{
		int f,t;
		db ww;
		f=read();
		t=read();
		scanf("%lf",&ww);
		add(f,t,ww);
	}
	db l=-1e6,r=1e6,eps=1e-10;
	while(fabs(l-r)>eps)
	{
		db mid=(l+r)/2;
		if(chk(mid)) l=mid;
		else r=mid;
	}
	printf("%0.8lf\n",l);
	return 0;
}
