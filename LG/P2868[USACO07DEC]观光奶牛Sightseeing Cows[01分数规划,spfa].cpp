#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#define re register
#define in inline
#define db double
#define ll long long
using namespace std;
int n,m;
struct edge{
	int t,nxt,w;
}e[5001];
int head[1001],cnt,fun[1001],b[1001],step[1001];
db dis[1001];
in void add(int f,int t,int w){e[++cnt].w=w,e[cnt].t=t,e[cnt].nxt=head[f],head[f]=cnt;}
in bool chk(db ans)
{
	memset(dis,0,sizeof(dis));
	memset(b,0,sizeof(b));
	memset(step,0,sizeof(step));
	queue<int> q;
	for(re int i=1;i<=n;++i){b[i]=1;q.push(i);}//注意图可能不连通!!!
	while(!q.empty())
	{
		int u=q.front();
		q.pop();
		b[u]=0;
		for(re int i=head[u];i;i=e[i].nxt)
		{
			int v=e[i].t;
			if(ans*(db)e[i].w-(db)fun[u]+dis[u]<dis[v])
			{
				dis[v]=ans*e[i].w-fun[u]+dis[u];			
				if(!b[v]){
					q.push(v);
					b[v]=1,step[v]=step[u]+1;
					if(step[v]>=n) return true;
				}
			}
		}
	}
	return false;	
}
signed main()
{
	scanf("%d%d",&n,&m);
	for(re int i=1;i<=n;++i) scanf("%d",&fun[i]);
	for(re int i=1;i<=m;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
	}
	db l=0.0,r=2147483647.0,mid;
	while(fabs(l-r)>1e-4)
	{
		mid=(l+r)/2;
		if(chk(mid)) l=mid;
		else r=mid;
	}
	if(n<2) printf("0\n");
	else if(l!=0.0) printf("%.2lf\n",l);
	else printf("0\n");
	return 0;
}
