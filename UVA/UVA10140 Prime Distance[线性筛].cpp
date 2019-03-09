//[l,r]区间很小, 先求出1~sqrt(r)内的质数, 再乘出并标记出l~r的合数即可得l~r的质数
#include<cstdio>
#include<cstring>
#define in inline
#define re register
#define int long long
const int N=1000010;
int p[N],v[N],cnt;
int l,r,lr[N];
signed main()
{
    for(re int i=2;i<N;++i)
    {
        if(!v[i]) p[++cnt]=i,v[i]=i;
        for(re int j=1;j<=cnt;++j)
        {
            if(p[j]>v[i]||i*p[j]>=N) break;
            v[i*p[j]]=p[j];
        }
    }
    while(~scanf("%lld%lld",&l,&r))
    {
        memset(lr,0,sizeof(lr));
        int t=0,minn=0,maxx=(int)9223372036854775807,amin1=0,amin2=0,amax1=0,amax2=0;
        if(l==1) lr[0]=1;//WA的原因: 1不是质数!!!
        for(re int i=1;i<=cnt;++i)
            for(re int j=l/p[i];p[i]*j<=r;++j)
                if(j>1&&p[i]*j>=l) lr[p[i]*j-l]=1;
        for(re int i=l;i<=r;++i)
        {
            if(lr[i-l]) continue;
            if(t){
                if(i-t>minn) minn=i-t,amax1=t,amax2=i;
                if(i-t<maxx) maxx=i-t,amin1=t,amin2=i;
            }
            t=i;
        }
        if(!amin1) printf("There are no adjacent primes.\n");
        else printf("%lld,%lld are closest, %lld,%lld are most distant.\n",amin1,amin2,amax1,amax2);
    }
    return 0;
}
