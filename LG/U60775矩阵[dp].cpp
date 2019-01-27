//背包问题+过河卒 O(n^3) 记得开滚动数组
#include<cstdio>
#define re register
#define in inline
in int read()
{
	int s=0,b=1;
	char ch;
	do{
		ch=getchar();
		//if(ch=='-') b=-1;
	}while(ch<'0' || ch>'9');
	while(ch>='0' && ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return b*s;
}
in int max(int a,int b,int c,int d)
{
	a=a>b?a:b;
	c=c>d?c:d;
	return a>c?a:c;
}
int n,m,V,v[401][401],w[401][401],f[2][401][410];
signed main()
{
	n=read();
	m=read();
	V=read();
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j)
			v[i][j]=read();
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j)
			w[i][j]=read();
  //不需要再加一重循环枚举背包问题的阶段, 走到的x,y就相当于阶段
	for(re int x=1;x<=n;++x)
	{
		for(re int y=1;y<=m;++y)
		{
			for(re int j=V;j>=0;--j)
			{
				if(j>=v[x][y]) f[x&1][y][j]=max(f[(x-1)&1][y][j],f[x&1][y-1][j],f[(x-1)&1][y][j-v[x][y]]+w[x][y],f[x&1][y-1][j-v[x][y]]+w[x][y]);
				else f[x&1][y][j]=f[(x-1)&1][y][j]>f[x&1][y-1][j]?f[(x-1)&1][y][j]:f[x&1][y-1][j];
        //装不下也可以选择不装而继续往前走, 不能直接像普通01背包一样忽略掉!!!
			}
		}
	}
	printf("%lld\n",f[n&1][m][V]);
	return 0;
}
