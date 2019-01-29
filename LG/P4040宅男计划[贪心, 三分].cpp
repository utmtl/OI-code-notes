#include<cstdio>
#include<algorithm>
#define int long long
#define re register
#define in inline
struct node{
    int p,s;
    bool operator <(const node &t)
        {
            if(p!=t.p) return p<t.p;//每次送货时, 每种食物的贡献都是1天, 肯定先选便宜的
            else return s>t.s;//其次再考虑保质期
        }
}a[211];
int m,f,n;
in int min(int a,int b)
{
    return a<b?a:b;
}
in int max(int a,int b)
{
    return a>b?a:b;
}
in int chk(int t)//求送t次外卖的最长存活天数
{
    int aver=(m-t*f)/t,res=m-aver*t-t*f,day=0;
    //易知把所有的钱减去外送费后均分到每次是最优的, 这样每次选取最优方案即可整体最优
    //注意不能整除可能剩钱(res)
    if(aver<0) return 0;
    int x;
    for(re int i=1;i<=n;++i)
    {
        if(aver<a[i].p) break;//排序后p是单调的, 买不起直接break
        x=i;
        if((aver>=a[i].p)&&(a[i].s>=day)){//买得起且不会过期
            int cnt=min(a[i].s-day+1,aver/a[i].p);//最多还要吃a[i].s-day+1个食物, 买太多会浪费
            day+=cnt;
            aver-=cnt*a[i].p;
        }
    }
    res+=aver*t;//注意aver也可能有剩余
    int ans=t*day;//注意day是平均分之后每次送外卖活多久, 记得乘t
    for(re int i=x;i<=n;++i)
    {
        if((a[i].s>=day)&&(res>=a[i].p)){
                ans+=res/a[i].p;
                break;//剩下的钱最多再买一次
        }
    }
    return ans;
}
signed main()
{
    scanf("%lld%lld%lld",&m,&f,&n);
    for(re int i=1;i<=n;++i) scanf("%lld%lld",&a[i].p,&a[i].s);
    std::sort(a+1,a+n+1);
    int l=1,r=m/f+1,t1,t2;
    //只要知道了送外卖的次数, 就可以通过贪心算出最大存活天数
    //外卖次数少: 不能尽量多买价格低的种类(每次每种只能买一份), 而且还要买保质期长的	
    //外卖次数多: 付给送外卖的的钱太多
    //所以易知最大存活天数与送外卖次数的关系是个单峰函数, 三分法找最值即可
    while(l<r)
    {
        int lmid=l+(r-l)/3,rmid=r-(r-l)/3;
        t1=chk(lmid),t2=chk(rmid);
        if(t1<t2) l=lmid+1;
        else r=rmid-1;
    }//三分法板子, 注意三分要l+block,r-block, block=ans所在区间最小长度. 此题整数域上block=1.
    //三分法在不方便确定边界条件时还有一种奇技淫巧: while(l+x<r), x适当即可, 再枚举[l,r]这个长度为x区间上的每一个点选取最优答案
    printf("%lld\n",max(t1,t2));
    return 0;
}
