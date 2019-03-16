#include<cstdio>
#include<map>
#include<cmath>
#define re register
#define in inline
#define int long long
using namespace std;
in int ksm(int a,int k,int yyb)
{
    int ans=1,base=a;
    while(k)
    {
        if(k&1) ans=ans*base%yyb;
        base=base*base%yyb;
        k>>=1;
    }
    return ans;
}
int bsgs(int a,int b,int p)//拔山盖世算法
{
	/*
	  求解a^x=b(mod p)
	  设x=i*t-j, t=sqrt(n)向上取整, 0<=j<=t-1
	  则方程为a^(i*t-j)=b(mod p)
	  (a^t)^i=b*a^j(mod p)
	  对于每个j把所有b*a^j%p插入hash表
	  再枚举所有的i[0,t]算出(a^t)^i在hash表里查找对应的j即可
	  解即为i*t-j
	*/
	map<int,int> hash;
	hash.clear();
	b%=p;
	int t=sqrt(p)+1,s=1;
	for(re int i=0;i<t;++i)	hash[b*s%p]=i,s=s*a%p;//j即i, s为a^i, 插入b*a^j%p对应的j值
	a=s;//a=a^t
	s=1;//s为a^i
	for(re int i=0;i<=t;++i)
	{
		if(hash.find(s)!=hash.end())
		{
			int v=i*t-hash[s];
			if(v>=0) return v;//最小非负整数解
		}
		s=s*a%p;
	}
	return -1;
}
signed main()
{
	int a,b,c;
	scanf("%lld%lld%lld",&c,&a,&b);
	int t=bsgs(a,b,c);
	if(t==-1) printf("no solution\n");
	else printf("%lld\n",t);
	return 0;
}
