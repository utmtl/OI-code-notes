#include<cstdio>
#define int long long
#define db double
#define in inline
#define re register
in int read()
{
    int s=0,b=0;
    char ch;
    do{
        ch=getchar();
        if(ch=='-') b=1;
    }while(ch<'0' || ch>'9');
    while(ch>='0' && ch<='9')
    {
        s=(s<<3)+(s<<1)+(ch^48);
        ch=getchar();
    }
    return b?-s:s;
}
int n,m,a[51];
in bool chk(int ans)
{
    int joker=ans<m?ans:m;
//直接贪心地判断答案是否可行
	//首先由于每套牌只能用一个joker, 所以总共实际有用的joker=min(ans,m)
	//虽然每套牌只能用一个joker,但也可以用joker去替代其他完整的套牌(不含joker)里的牌
	//再把被替代的牌放到缺的地方, 即可把joker看做万能牌
	for(re int i=1;i<=n;++i)
    {
        if(a[i]<ans) joker=joker-(ans-a[i]);//某种牌不够, 用joker来补
        if(joker<0) return false;
    }
    return true;
}
signed main()
{
    n=read();
    m=read();
    for(re int i=1;i<=n;++i) a[i]=read();
    int l=0,r=5000000001,mid;
    while(r-l>3)
    {
        mid=(l+r)>>1;
        if(chk(mid)) l=mid+1;
        else r=mid;
    }
    for(re int i=r+1;i>=l-1;--i)
		if(chk(i)){printf("%lld\n",i);break;}
//我有玄学的二分技巧: 先找出答案所在区间, 再在区间内枚举答案, 不管题怎么边都不会WA
	//记得 break 和 r+1~l-1 !!!
    return 0;
}
