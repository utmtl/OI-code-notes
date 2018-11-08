#include<cstdio>
#define re register
#define in inline
#define int long long
inline int read()
{
	int s=0,b=1;
	char ch;
	do{
		ch=getchar();
		if(ch=='-') b=-1;
	}while(ch<'0' || ch>'9');
	while(ch>='0' && ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return b*s;
}//快读是不可能出锅的
int n,a[210],s[210];
int f1[210][210],f2[210][210];
int min(int x,int y)
{
	return x<y?x:y;
}
int max(int x,int y)
{
	return x>y?x:y;
}
signed main()
{
	n=read();
	for(re int i=1;i<=n;++i)
		a[i]=read(),a[i+n]=a[i];//断环为链
	n<<=1;
	for(re int i=1;i<=n;++i)
		s[i]=s[i-1]+a[i];//处理前缀和
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j)
			f1[i][j]=2147483647;//初始化
	for(re int i=1;i<=n;++i)
		f1[i][i]=0,f2[i][i]=0;//边界条件
	for(re int i=n-1;i>=1;--i)
	{
		for(re int j=i+1;j<=n;++j)
		{
			for(re int k=i;k<=j-1;++k)
			{
				f1[i][j]=min(f1[i][j],f1[i][k]+f1[k+1][j]+s[j]-s[i-1]);
				f2[i][j]=max(f2[i][j],f2[i][k]+f2[k+1][j]+s[j]-s[i-1]);
			}
		}
	}
	int ansmin=2147483647,ansmax=0;
	for(re int i=1;i<=n>>1;++i)//由于本来是在环上合并, 断成链后必须枚举每一种成环的方式, 也就是在长为2n的链上选一段长为n的"环"
	{
		if(f1[i][i+(n>>1)-1]<ansmin) ansmin=f1[i][i+(n>>1)-1];
		if(f2[i][i+(n>>1)-1]>ansmax) ansmax=f2[i][i+(n>>1)-1];
	}
	printf("%lld\n%lld\n",ansmin,ansmax);
	return 0;
}
