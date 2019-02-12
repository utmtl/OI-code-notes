/*
二分所有差值的中位数(在极差范围内)
统计有cnt个差值比当前mid大
通过比较2*cnt与总数目nn判断这个中位数是大了还是小了
理论上中位数满足2*cnt==nn
*/
#include<cstdio>
#include<algorithm>
#define int long long
#define re register
#define in inline
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
int n,a[50010],nn;
in bool chk(int dis)
{
	re int j=1,cnt=0;
	for(re int i=1;i<=n;++i)
	{
		while(a[j]-a[i]<=dis && j<=n) ++j;
		cnt=cnt+n-j+1;
	}//统计多少两两差值比当前中位数dis大. i,j类似莫队的指针, 但不会回跳.
	if(cnt*2>nn) return true;
	else return false;
}
signed main()
{
	n=read();
	nn=n*(n-1)/2;
	for(re int i=1;i<=n;++i) a[i]=read();
	std::sort(a+1,a+n+1);
	int l=0,r=a[n]-a[1];
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(chk(mid)) l=mid+1;
		else r=mid;
	}
	int ans=r;
	--nn;//由于中位数可能是两个数的平均值, 所以要二分两次找到最中间的两个数. 此操作对数目为奇数的情况无影响.
	l=0,r=a[n]-a[1];
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(chk(mid)) l=mid+1;
		else r=mid;
	}
	printf("%lld\n",(ans+r)>>1);
	return 0;
}
