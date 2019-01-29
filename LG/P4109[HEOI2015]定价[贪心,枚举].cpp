#include<cstdio>
#include<cmath>
#define int long long
#define re register
#define in inline
int __,l,r,ans;
signed main()
{
    scanf("%lld",&__);
    while(__--)
    {
        scanf("%lld%lld",&l,&r);
        int minp=2147483647;
        //对于每组数据, 直接从小到大枚举即可, 枚举时通过加10的幂避免降低贡献值(增大荒谬值), 优化时间复杂度
        while(l<=r)
        {
            int l1=l,cnt0=0,p=0;
            while(l1%10==0) l1/=10,++cnt0;
            if(l1%10==5) p=-1;
            while(l1) l1/=10,p+=2;
            //计算当前枚举的这个数的贡献
            if(p<minp) minp=p,ans=l;
            l+=pow(10,cnt0);//由于末尾的0提供最优贡献, 枚举时保留这些0一定最优, 所以l每次加10^(末尾0个数)
        }
        printf("%lld\n",ans);
    }		
    return 0;
}
