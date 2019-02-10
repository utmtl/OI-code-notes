#include<cstdio>
#include<climits>
#define re register
#define in inline
#define int long long
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
const int N=5001;
int n,d[N];
struct SegmentTree{
    int l,r,minv;
}t[4*N];
void build(int p,int l,int r)
{
    t[p].l=l;
    t[p].r=r;
    if(l==r){
        t[p].minv=d[l];
        return;
    }
    int mid=(l+r)>>1;
    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);
    t[p].minv=t[p<<1].minv<t[(p<<1)+1].minv?t[p<<1].minv:t[(p<<1)+1].minv;
}
int ask(int p,int l,int r)
{
    if(l<=t[p].l && t[p].r<=r) return t[p].minv;
    int ans=LLONG_MAX;
    int mid=(t[p].l+t[p].r)/2;
    if(l<=mid) ans=ask(p<<1,l,r);
    if(r>mid){
        int t=ask((p<<1)+1,l,r);
        ans=ans<t?ans:t;
    }
    return ans;
}
int work(int l,int r,int jian)
{//jian为已涂高度
    if(l==r) return 1;
	int minv=ask(1,l,r);//当前区间最低高度
	int ans=minv-jian;
	for(re int i=l;i<=r;++i)
	{
		re int j=i;
		while(d[j]!=minv && j<=r) ++j;
		ans+=work(i,j-1,minv);
		i=j;
	}//寻找凸出来的每个部分[i,j-1]分别递归消除(以最小值位置为分界点左右分治在一段相等的区间上会出bug)
	return ans<(r-l+1)?ans:(r-l+1);//ans为横着涂次数, r-l+1为竖着涂次数
}
signed main()
{
    n=read();
    for(re int i=1;i<=n;++i)
        d[i]=read();
    build(1,1,n);
    printf("%lld\n",work(1,n,0));
    return 0;
}
