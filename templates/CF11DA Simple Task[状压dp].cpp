//教会我状压dp的好题
//感谢党和国家~
//%%%
#include<cstdio>
#define re register
#define in inline
#define int long long
int n,m,e[19][19],f[600000][19],ans;
//f[i][j]:走过的节点为i(状态压缩得), 起点为i二进制为1(为1走过代表走过)的最低位(第一个走过的点), 终点为j的路径条数
signed main()
{
	scanf("%lld%lld",&n,&m);
	int u,v;
	for(re int i=1;i<=m;++i)
	{
		scanf("%lld%lld",&u,&v);
		e[u-1][v-1]=e[v-1][u-1]=1;
	}
	for(re int i=0;i<n;++i) f[1<<i][i]=1;//每个节点自己到自己路径条数为1
	for(re int i=1;i<=1<<n;++i)
	{
		for(re int j=0;j<n;++j)
		{
			if(!f[i][j]) continue;//两点根本不联通
			for(re int k=0;k<n;++k)
			{
				//i,j: 起点,终点
				if(e[j][k] && (1<<k)>=(i&-i)){//(1<<k)>=(i&-i):不能走回头路, 保证是简单路径(去重)
					if((1<<k)&i){//k点走过(在i内, 1<<k与i有交集)
						if((1<<k)==(i&-i)) ans+=f[i][j];//构成一个环(k点恰好为起点), f[i][j]的贡献加入ans
						//i&-i:lowbit操作,二进制下的为1的最低位
					}
					else f[i|(1<<k)][k]+=f[i][j];//k点没走过: 标记k(0->1,或运算)点并累加路径条数
				}
			}
		}
	}
	printf("%lld\n",(ans-m)>>1);//一条单独的边也算成了环, 且每个环算了两次(无向图)
	return 0;
}
