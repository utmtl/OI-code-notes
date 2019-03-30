#include<cstdio>
#include<cstring>
#include<cmath>
#define re register
#define in inline
#define db long double
#define int long long
in int read()
{
	int s=0,b=0;char ch;
	do{ch=getchar();if(ch=='-')b=1;}while(ch<'0'||ch>'9');
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return b?-s:s;
}
int n,m;
db a[511][511],eps=1e-8;
int c[511],ans1,ans2;
signed main()
{
	n=read(),m=read();
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j)
			scanf("%Lf",&a[i][j]);	
	for(re int i=1;i<=n;++i) c[i]=read();
	for(re int i=1;i<=m;++i)
	{
		int x=0;
		for(re int j=i;j<=n;++j)
			if((fabs(a[j][i])>eps)&&(!x||c[j]<c[x])) x=j;//注意每次要寻找所有可能成为基的向量(包括这一行本身)中花费最小的, 不要只在这一行主元系数为0时才找最小!!!
		if(!x) break;
		if(i!=x)
		{
			for(re int j=1;j<=m;++j){db t=a[x][j];a[x][j]=a[i][j],a[i][j]=t;}
			c[i]^=c[x],c[x]^=c[i],c[i]^=c[x];
		}
		++ans1,ans2+=c[i];
		for(re int j=1;j<=n;++j)
		{
			if(i==j) continue;
			db t=a[j][i]/a[i][i];
			for(re int k=1;k<=m;++k) a[j][k]-=t*a[i][k];
		}
	}
	printf("%lld %lld\n",ans1,ans2);
	return 0;
}
