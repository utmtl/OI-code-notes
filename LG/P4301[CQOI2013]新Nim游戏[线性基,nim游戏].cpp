#include<cstdio>
#include<algorithm>
#define re register
#define in inline
#define int long long
int n,a[101],base[64];
in void insert(int x)
{
	for(re int i=62;i>=0;--i)
	{
		int t=x&(1<<i);
		if(!t) continue;
		if(!base[i]) {base[i]=x;break;}
		x^=base[i];
	}
}
in bool find(int x)
{
	for(re int i=62;i>=0;--i)
	{
		int t=x&(1<<i);
		if(!t) continue;
		if(!base[i]) break;
		x^=base[i];
	}
	if(x) return false;
	return true;
}
signed main()
{
	scanf("%lld",&n);
	for(re int i=1;i<=n;++i) scanf("%lld",&a[i]);
	std::sort(a+1,a+n+1);
	int ans=0;
	for(re int i=n;i>=1;--i)
	{
		if(find(a[i])) ans+=a[i];
		else insert(a[i]);
	}
	printf("%lld\n",ans);
	return 0;
}
