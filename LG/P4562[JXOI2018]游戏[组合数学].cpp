#include<cstdio>
#define in inline
#define re register
#define ll long long
int l,r,n;
const int yyb=1e9+7;
int jc[10000001],b[10000001],invjc[10000001],sum;
int ksm(int ba,int k)
{
	int ans=1;
	while(k)
	{
		if(k&1) ans=(ll)ans*ba%yyb;
		ba=(ll)ba*ba%yyb;
		k>>=1;
	}
	return ans;
}
int C(int n,int m)
{
	if(n<m) return 0;
	if(!n) return 1;
	return (ll)jc[n]*invjc[m]%yyb*invjc[n-m]%yyb;
}
signed main()
{
	scanf("%d%d",&l,&r);
	n=r-l+1;
	jc[0]=1;
	for(re int i=1;i<=r;++i) jc[i]=(ll)jc[i-1]*i%yyb;
	invjc[r]=ksm(jc[r],yyb-2);
	for(re int i=r-1;i>=0;--i) invjc[i]=(ll)invjc[i+1]*(i+1)%yyb;
	for(re int i=l;i<=r;++i)
	{
		if(b[i]) continue;
		++sum;
		for(re int j=2;i*j<=r;++j) b[i*j]=1;
	}
	int ans=0;
	for(re int i=sum;i<=n;++i)
		ans=((ll)ans+(ll)i*sum%yyb*C(n-sum,n-i)%yyb*jc[i-1]%yyb*jc[n-i]%yyb)%yyb;
	printf("%d\n",ans);
	return 0;
}
