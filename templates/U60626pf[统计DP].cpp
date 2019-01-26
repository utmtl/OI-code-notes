#include<cstdio>
#define re register
#define in inline
#define int long long
int f[1001][1001],n,m,p;
const int yyb=1000000007;
signed main()
{

    /*
	  本题与斐波拉契数列没有任何关系, 只要知道是n个不同的数填入长为p的序列, 每个数至少填一次且相同数字的最小间距为m即可
	  f[i][j]表示长为i的序列填j种数字的方案数
	  统计方案数的dp类似于递推
	*/
	scanf("%lld%lld%lld",&n,&m,&p);
	f[1][1]=1;
	for(re int i=1;i<=p;++i)
	{
		for(re int j=1;j<=n;++j)
		{
			f[i][j]+=f[i-1][j-1];//累加填一个新数的方案数
			if(j>m) f[i][j]+=f[i-1][j]*(j-m)%yyb;//累加填一个已有的数字的方案数
			//为满足最小间隔要求, 已填序列末尾的m种数不可以放, 且当j>m时才可以填入已有数字
		}
	}
	//之前求的是组合, 现在要求排列, 乘上n!即可, 记得膜yyb
	for(re int i=2;i<=n;++i) f[p][n]*=i,f[p][n]%=yyb;
	printf("%lld\n",f[p][n]%yyb);
	return 0;
}
