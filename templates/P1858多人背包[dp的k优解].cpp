#include<cstdio>
#define re register
#define in inline
int k,V,n,w[210],v[210],f[5010][55],cache[55];
in int max(int x,int y)
{
	return x>y?x:y;
}
signed main()
{
	scanf("%d%d%d",&k,&V,&n);
	for(re int i=1;i<=n;++i)
		scanf("%d%d",&v[i],&w[i]);
	for(re int i=0;i<5010;++i)
		for(re int j=0;j<55;++j)
			f[i][j]=-19260817;
	f[0][1]=0;
    //记得初始化成极小值, 仅f[0][1]初值为0. 其余不满足恰好装满的要求(若不要求恰好装满, 可初值全为0).
	//f[v][k]:体积为v时的第k优解
	for(re int i=1;i<=n;++i)
	{
		for(re int j=V;j>=v[i];--j)
		{//外层是普通的背包问题
			int c1=1,c2=1;
			for(re int c=1;c<=k;++c)
			{
				cache[c]=max(f[j][c1],f[j-v[i]][c2]+w[i]);
				if(f[j][c1]>f[j-v[i]][c2]+w[i]) ++c1;
				else ++c2;//++c1/2: 最=>次
			}
			for(re int c=1;c<=k;++c) f[j][c]=cache[c];
		}
	}
	int ans=0;
	for(re int i=1;i<=k;++i) ans+=f[V][i];
	printf("%d\n",ans);
	return 0;
}
