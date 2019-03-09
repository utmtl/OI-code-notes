//https://www.cnblogs.com/zjp-shadow/p/7773566.html
#include<cstdio>
#define re register
#define in inline
#define int long long
int x,y,n,p;
void exgcd(int a,int b)
{
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b);
	int t=x;
	x=y,y=t-(a/b)*y;
}
in int ksm(int base,int k)
{
	int ans=1;
	while(k)
	{
		if(k&1) ans*=base,ans%=p;
		base*=base;
		base%=p;
		k=k>>1;
	}
	return ans;
}
int inv[3000010];
signed main()
{
	scanf("%lld%lld",&n,&p);
    /*
	for(re int i=1;i<=n;++i)
	{
	    //exgcd:
		//exgcd(i,p);
		//printf("%d\n",(x%p+p)%p);
		//费马:
		//printf("%lld\n",ksm(i,p-2));
	}
	*/
	inv[1]=1;
	for(re int i=2;i<=n;++i) inv[i]=((-p/i*inv[p%i])%p+p)%p;
	for(re int i=1;i<=n;++i) printf("%lld\n",inv[i]);
	return 0;
}
