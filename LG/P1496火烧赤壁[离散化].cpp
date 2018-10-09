#include<cstdio>
#include<algorithm>
long long n,ans;
struct node{
	int f,t;
	bool operator < (const node &that)const
	{
		if(f<that.f) return true;
		else return false;
	}
}a[100000];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].f,&a[i].t);
	std::sort(a+1,a+n+1);
	int x;
	x=1;
	ans=ans+a[1].t-a[1].f;
	for(int i=1;i<=n;i++)
	{
		if(a[i].f>a[x].t) ans=ans+a[i].t-a[i].f,x=i;
		else if(a[i].t>a[x].t) ans=ans+a[i].t-a[x].t,x=i;
		
	}
	printf("%lld\n",ans);
	return 0;
}
