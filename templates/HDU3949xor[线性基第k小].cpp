#include<cstdio>
#include<cstring>
#define in inline
#define int long long
#define ull unsigned long long
#define re register
in int read()
{
	int s=0,b=0;char ch;
	do{ch=getchar();if(ch=='-')b=1;}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return b?-s:s;
}
int T,n,q,cnt,y0;
ull a[10010];
in void ask(ull k)
{
	int ans=0;
	if(y0) --k;//若基底数小于原数个数, 0是可以异或出来的(不允许自己异或自己)
	if(k>=(1llu<<cnt)) {printf("-1\n");return;}
	for(re int i=cnt-1;i>=0;--i)
		if(k>>i&1) ans^=a[cnt-i];//前i个基底构成前2^i大, 把要求的k二进制分解即可
	printf("%I64u\n",ans);
}
signed main()
{
    T=read();
	for(re int _=1;_<=T;++_)
	{
		n=read();
		for(re int i=1;i<=n;++i) a[i]=read();
		cnt=n;
		for(re int i=1;i<=n;++i)//普通高斯消元
		{
			for(re int j=i+1;j<=n;++j)
				if(a[j]>a[i]) a[i]^=a[j],a[j]^=a[i],a[i]^=a[j];
			if(!a[i]){y0=1,cnt=i-1;break;}//若有0行(基底数<原数数), 则可异或出0
			for(re int k=63;k>=0;--k)
			{
				if(a[i]>>k&1){
					for(re int j=1;j<=n;++j)
						if(i!=j&&(a[j]>>k&1)) a[j]^=a[i];
					break;
				}
			}
		}
		q=read();
		printf("Case #%lld:\n",_);
		for(re int i=1;i<=q;++i) ask(read());
		memset(a,0,sizeof(a));
		cnt=y0=0;
	}
	return 0;
}
