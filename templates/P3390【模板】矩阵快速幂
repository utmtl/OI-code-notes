#include<cstdio>
#define re register
#define int long long
const int mod=1e9+7;
int n,k;
struct jz{
	int v[101][101];
	void csh()
	{
		for(re int i=1;i<=100;i++) v[i][i]=1;
	}//初始化为单位矩阵. 单位矩阵相当于数字1
	void ql()
	{
		for(re int i=1;i<=100;i++)
			for(re int j=1;j<=100;j++)
				v[i][j]=0;
	}//清零, 方便记录乘法结果
	void input()
	{
		for(re int i=1;i<=n;i++)
			for(re int j=1;j<=n;j++)
				scanf("%lld",&v[i][j]);
	}
	void output()
	{
		for(re int i=1;i<=n;i++)
		{
			for(re int j=1;j<=n;j++)
				printf("%lld ",v[i][j]%mod);//为防止结果过大, 取模
			printf("\n");
		}
	}
	jz operator *(const jz &t)
	{
		jz c;
		c.ql();
		for(re int i=1;i<=n;i++)
			for(re int j=1;j<=n;j++)
				for(re int k=1;k<=n;k++)
					c.v[i][j]=c.v[i][j]%mod+v[i][k]*t.v[k][j]%mod;
		return c;
	}//矩阵乘法: A*B的结果矩阵C 第i行第j列的值 = A的第i行的元素 分别乘 B的第j列的元素 的积之和 (不是两两组合, 是每一对元素分别相乘)
	//如C[i][j] = sum_t取1~n(A[i][t]*B[t][j])
	//所以矩阵乘法要求A的行数 = B的列数
};
jz ksm(jz a,int k)//普通快速幂
{
	jz x;
	x.csh();//x初始化为单位矩阵
	if(k==0) return x;//a^0==1(a!=0), 同理A^0==单位矩阵
	if(k&1) return a*ksm(a,k-1);
	x=ksm(a,k>>1);
	return x*x;
}
signed main()
{
	jz x;
	scanf("%lld%lld",&n,&k);
	x.input();
	ksm(x,k).output();
	return 0;
}
