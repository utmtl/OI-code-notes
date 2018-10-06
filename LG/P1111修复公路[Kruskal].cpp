#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,f[999999],s,cnt;
struct edge
{
	int f;
	int t;
	int w;
}e[999999];
int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void u(int r1,int r2)
{
	r1=find(r1);
	r2=find(r2);
	if(r1!=r2) f[r1]=r2;
}
int cmp(const edge &a,const edge &b)
{
	if(a.w<b.w) return true;
	else return false;
}
inline int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	int x;
	scanf("%d%d",&n,&m);
	if(n==0) return 0;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&e[i].f,&e[i].t,&e[i].w);
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=m;i++)
	{
		if(find(e[i].f)!=find(e[i].t)){
			u(e[i].t,e[i].f);
			s=max(e[i].w,s);
			cnt++;
		}
		if(cnt==m-1) break;
	}
	printf("%d\n",s);
	return 0;
}
