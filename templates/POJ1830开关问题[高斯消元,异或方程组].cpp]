#include<cstdio>
#define re register
#define int long long
#define db double
#define in inline
in int read()
{
    int s=0,b=0;char ch;
    do{ch=getchar();if(ch=='-')b=1;}while(ch<'0'||ch>'9');
    while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
    return b?-s:s;
}
int a[101],n;
signed main()
{
    int __=read();
	for(re int _=1;_<=__;++_)
	{
		n=read();
		for(re int i=1;i<=n;++i) a[i]=read();
		for(re int i=1;i<=n;++i)
		{
			int t=read();
			a[i]^=t,a[i]|=(1<<i);//a[i][i]=1
		}
		while(1)
		{
			int x=read(),y=read();
			if(x==0&&y==0) break;
			a[y]|=(1<<x);//a[y][x]=1
		}
		int f=0;
		for(re int i=1;i<=n;++i)
		{
			for(re int j=i+1;j<=n;++j)
				if(a[j]>a[i]) a[i]^=a[j],a[j]^=a[i],a[i]^=a[j];//找主元最靠左的一行, 即a[]最大的一行
			if(!a[i]){printf("%lld\n",1ll<<(n-i+1));f=1;break;}//消元完毕, 共i-1个主元, n-i+1个自由元, 所以共2^(n-i+1)种方案
			if(a[i]==1){printf("Oh,it's impossible~!!\n");f=1;break;}//出现0=1
			for(re int j=n;j>0;--j)//以a[i]最高位的1为主元, 消去其他行这一列的其他系数(j为列, k为行)
			{
				if((a[i]>>j)&1){
					for(re int k=1;k<=n;++k)
						if(i!=k&&((a[k]>>j)&1)) a[k]^=a[i];
					break;
				}
			}
		}
		if(!f) printf("1\n");
	}
    return 0;
}
