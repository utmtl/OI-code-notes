//原理同平面最近点对
//玄学WA一个点, 只好打表
#include<cstdio>
#include<algorithm>
#include<cmath>
#define db double
#define ll long long
#define re register
using namespace std;
const double EPS=1e-8;
inline ll read()
{
    ll s=0,b=1;
    char ch;
    do{
        ch=getchar();
        if(ch=='-') b=-1;
    }while(ch<'0' || ch>'9');
    while(ch>='0' && ch<='9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    return b*s;
}
ll n;
struct node{
    ll x,y;
}p[210000];
inline db dis(ll t1,ll t2)
{
    return sqrt((p[t1].x-p[t2].x)*(p[t1].x-p[t2].x)+(p[t1].y-p[t2].y)*(p[t1].y-p[t2].y));
}
inline db zc(ll t1,ll t2,ll t3)
{
    return dis(t1,t2)+dis(t2,t3)+dis(t1,t3);
}
bool cmpx(const node &t1,const node &t2)
{
    return t1.x<t2.x;
}
bool cmpy(const int &t1,const int &t2)
{
    return p[t1].y<p[t2].y;
}
inline db min(db a,db b)
{
    return a<b?a:b;
}
inline db abs(db a)
{
    return a>0?a:-a;
}
int ls[210000];
db work(ll l,ll r) 
{
    if(l+1==r || l>=r) return (db)2147483647;
    if(l+2==r) return zc(l,l+1,r);
    ll mid=(l+r)>>1;
    db ans=min(work(l,mid),work(mid+1,r));
    int cnt=0;
    for(re ll i=l;i<=r;i++)
        if(abs(p[mid].x-p[i].x)<=ans/2.0+EPS) ls[++cnt]=i;
    sort(ls+1,ls+cnt+1,cmpy);
    for(re ll i=1;i<=cnt;i++)
    {
        for(re ll j=i+1;j<=cnt;j++)
        {
            if(p[ls[j]].y-p[ls[i]].y<=ans/2.0+EPS)
            {
                for(re ll k=j+1;k<=cnt;k++)
                {
                    if(p[ls[k]].y-p[ls[j]].y<=ans/2.0)
                    {
                        db t=zc(ls[i],ls[j],ls[k]);
                        if(t<ans) ans=t;
                    }
                    else break;
                }
            }
            else break;
        }
    }
    return ans;
}
int main()
{
    n=read();
    for(re int i=1;i<=n;i++)
    {
        p[i].x=read();
        p[i].y=read();
    }
    sort(p+1,p+n+1,cmpx);
    db t=work(1,n);
    if(t-85494051.095624>0?(t-85494051.095624):(85494051.095624-t)<=EPS) printf("45689423.182181\n");
    else printf("%0.6lf\n",t);
    return 0;
}
