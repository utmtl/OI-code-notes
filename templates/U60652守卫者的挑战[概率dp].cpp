#include<cstdio>
#define re register
#define in inline
#define db double
#define ll long long
int n,l,k,a[201];
db f[202][404][202],p[201];
signed main()
{
	scanf("%d%d%d",&n,&l,&k);
	for(re int i=1;i<=n;++i) {scanf("%lf",&p[i]);p[i]/=100.0;}
	for(re int i=1;i<=n;++i) scanf("%d",&a[i]);
	if(k>200) k=200; //最多200项挑战, 最多装满200的背包
	f[1][k+200][0]=1;
    //f[i][j][k]: 经过i项挑战, 背包容量为j-200, 获胜k项挑战  的概率
    //经过一项挑战, 背包容量不变, 肯定是输了, 所以=1
    //由于可能暂时背包装不下, 后续才够装, 把数组的200作为0, 防止越界RE
	for(re int i=1;i<=n;++i)
	{
		for(re int j=1;j<=400;++j)
		{
			for(re int k=0;k<=200;++k)
			{
				f[i+1][j][k]+=f[i][j][k]*(1.0-p[i]); //输的情况
				if(a[i]>=0){//赢得背包容量
					if(j+a[i]>400) f[i+1][400][k+1]+=f[i][j][k]*p[i];
					else f[i+1][j+a[i]][k+1]+=f[i][j][k]*p[i];
				}
				else f[i+1][j-1][k+1]+=f[i][j][k]*p[i]; //赢得地图碎片(滑稽)
			}
		}
	}
	db ans=0.0;
	for(re int i=200;i<=400;++i)
		for(re int j=l;j<=200;++j)
			ans+=f[n+1][i][j];
	printf("%lf\n",ans);
	return 0;
}
