#include<cstdio>
#define re register
#define in inline
#define int long long
in int read()
{
	int s=0,b=0;char ch;
	do{ch=getchar();if(ch=='-')b=1;}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return b?-s:s;
}
int n,m,p,jc[500000];
in int ksm(int ba,int k,int yyb)
{
	int ans=1;
	while(k)
	{
		if(k&1) ans=ans*ba%yyb;
		ba=ba*ba%yyb;
		k>>=1;
	}
	return ans;
}
in int C(int n,int m,int yyb)//1 3 5
{
	if(n<m) return 0;
	if(!n) return 1;
	return jc[n]*ksm(jc[m],yyb-2,yyb)%yyb*ksm(jc[n-m],yyb-2,yyb)%yyb;
}
in int lucas(int n,int m,int yyb)
{
	if(n<m) return 0;
	if(!n) return 1;
	return lucas(n/yyb,m/yyb,yyb)%yyb*C(n%yyb,m%yyb,yyb)%yyb;
}
signed main()
{
	int __=read();
	for(re int _=1;_<=__;++_)
	{
		n=read(),m=read(),p=read();
		jc[1]=1,jc[0]=1;//0的阶乘为1!!! (n+1)!/n!=n+1 => 1!/0!=1 => 0!=1
		for(re int i=2;i<=p;++i) jc[i]=i*jc[i-1]%p;
		printf("%lld\n",lucas(n+m,m,p));
	}
	return 0;
}
