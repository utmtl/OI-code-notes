#include<cstdio>
#define in inline
#define re register
#define int unsigned long long
in int gcd(int x,int y)
{
	while(x^=y^=x^=y%=x);
	return y;
}
in int C3(int x)
{
	return x*(x-1)*(x-2)/6;
}
signed main()
{
	int n,m;
	scanf("%lld%lld",&n,&m);
	int ans=C3((n+1)*(m+1))-(n+1)*C3(m+1)-(m+1)*C3(n+1);
	//用选3个点的所有情况先减去横向和纵向的三点共线情况
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=m;++j)
			ans-=(n-i+1)*(m-j+1)*(gcd(i,j)-1)*2;//减去斜向的三点共线
	//这里是枚举斜率为k(0<k<1)的直线(即平面向量方向)
	//在直线(0,0)-(i,j)上的格点共gcd(i,j)-1个. 这里只枚举了方向, 同样的直线(平移得)在整个方格中共(n-i+1)*(m-j+1)条, 再考虑把这些直线翻转, 所以总共要*2
	printf("%lld\n",ans);
	return 0;
}
