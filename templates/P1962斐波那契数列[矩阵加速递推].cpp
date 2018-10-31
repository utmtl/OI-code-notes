/*
矩阵加速斐波拉契数列递推原理:
|f[n-2],f[n-1]|       |f[n-1],f[n-1]+f[n-2]|
|             | * A = |                    |
|0     ,0     |       |0     ,0            |
由f[n-2]到f[n-1] 即 当前状态的矩阵*矩阵A = 下一状态的矩阵
容易构造出A:
|0,1|
|1,1|
所以连续这一操作, 即: |f[1],f[2]|*A^(n-1)=|f[n],f[n-1]|
用快速幂即可
*/
#include<cstdio>
#define re register
#define int long long
const int mod=1000000007;
const int size=2;
int n;
struct jz{
	int v[size+1][size+1];
	void csh()
	{
		for(re int i=1;i<=size;i++) v[i][i]=1;
	}
	void ql()
	{
		for(re int i=1;i<=size;i++)
			for(re int j=1;j<=size;j++)
				v[i][j]=0;
	}
	void input()
	{
		for(re int i=1;i<=size;i++)
			for(re int j=1;j<=size;j++)
				scanf("%lld",&v[i][j]);
	}
	void output()
	{
		for(re int i=1;i<=size;i++)
		{
			for(re int j=1;j<=size;j++)
				printf("%lld ",v[i][j]%mod);
			printf("\n");
		}
	}
	jz operator *(const jz &t)
	{
		jz c;
		c.ql();
		for(re int i=1;i<=size;i++)
			for(re int j=1;j<=size;j++)
				for(re int k=1;k<=size;k++)
					c.v[i][j]=c.v[i][j]%mod+v[i][k]*t.v[k][j]%mod;
		return c;
	}
};
jz ksm(jz a,int k)
{
	jz x;
	x.ql();
	x.csh();
	if(k==0) return x;
	if(k&1) return a*ksm(a,k-1);
	x=ksm(a,k>>1);
	return x*x;
}
signed main()
{
	scanf("%lld",&n);
	jz csjz,zyjz;//初始矩阵(递推边界) 和 转移矩阵(乘上它便可转移到下一状态)
	csjz.v[1][1]=1;
	csjz.v[1][2]=1;
	csjz.v[2][1]=0;
	csjz.v[2][2]=0;
	zyjz.v[1][1]=0;
	zyjz.v[1][2]=1;
	zyjz.v[2][1]=1;
	zyjz.v[2][2]=1;
	printf("%lld\n",(csjz*ksm(zyjz,n-1)).v[1][1]%mod);
	return 0;
}
