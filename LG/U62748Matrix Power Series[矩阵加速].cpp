#include<cstdio>
#include<cstring>
#define in inline
#define re register
#define ll long long
#define db double
int n,k,yyb;
struct jz{
	int a[31][31];
	jz operator * (const jz &b)const
		{
			jz c;
			memset(c.a,0,sizeof(c.a));
			for(re int i=1;i<=n;++i)
				for(re int j=1;j<=n;++j)
					for(re int k=1;k<=n;++k)
						c.a[i][j]+=(ll)a[i][k]*(ll)b.a[k][j]%(ll)yyb;
			return c;
		}
	void operator += (const jz &b)
		{
			for(re int i=1;i<=n;++i)
				for(re int j=1;j<=n;++j)
					a[i][j]=(a[i][j]+b.a[i][j])%yyb;
		}
}A,I;
struct jzjz{
	jz a[3][3];
	jzjz operator * (const jzjz &b)const
		{
			jzjz c;
			memset(c.a,0,sizeof(c.a));
			for(re int i=1;i<=2;++i)
				for(re int j=1;j<=2;++j)
					for(re int k=1;k<=2;++k)
						c.a[i][j]+=a[i][k]*b.a[k][j];
			return c;
		}
}cs,zy,II;
jzjz ksm(int k)
{
	if(k==0) return II;
	if(k&1) return zy*ksm(k-1);
	jzjz res=ksm(k>>1);
	return res*res;
}
signed main()
{
	//freopen("T1.in","r",stdin);
	//freopen("T1.out","w",stdout);
	scanf("%d%d%d",&n,&k,&yyb);
	for(re int i=1;i<=n;++i)
		for(re int j=1;j<=n;++j)
			scanf("%d",&A.a[i][j]);
	for(re int i=1;i<=n;++i) I.a[i][i]=1;
	cs.a[1][1]=A,cs.a[1][2]=I;
	II.a[1][1]=I,II.a[2][2]=I;
	zy.a[1][1]=A,zy.a[2][1]=A,zy.a[2][2]=I;
	/*
	  设f[n]=A^1+A^2+A^3+...+A^n
	  则f[n]=A+f[n-1]*A
	  转化成矩阵加速递推(矩阵套矩阵):
	  [f[n],1] = [f[n-1],1] * [A 0]
	                          [A 1]
	  所以:
	  [f[n],1] = [A,1] * [A 0]^(k-1)
	                     [A 1]
	*/
	jzjz ans=cs*ksm(k-1);
	for(re int i=1;i<=n;++i)
	{
		for(re int j=1;j<=n;++j) printf("%d ",ans.a[1][1].a[i][j]);
		printf("\n");
	}
	return 0;
}
