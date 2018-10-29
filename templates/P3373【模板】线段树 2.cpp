//同时资瓷区间加和区间乘的线段树模板
#include<cstdio>
#define ll long long
#define re register
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
const int n_max=110000;
struct SegmentTree{
	ll l,r;
	ll sum;
	ll add,times;
}t[4*n_max];
ll n,m,p1,a[n_max]; //为防止答案过大,统一对p1取模('//'处)
void build(ll p,ll l,ll r)
{
	t[p].l=l;
	t[p].r=r;
	t[p].times=1; //别忘了初始化times!不是全局变量默认的0
	if(l==r)
	{
		t[p].sum=a[l];
		return;
	}
	ll mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
	t[p].sum%=p1; //
}
void spread(ll p)
{
	if(t[p].add!=0 || t[p].times!=1){
    //重点部分:
		t[p*2].sum=t[p*2].sum*t[p].times+(t[p*2].r-t[p*2].l+1)*t[p].add;
		t[p*2+1].sum=t[p*2+1].sum*t[p].times+(t[p*2+1].r-t[p*2+1].l+1)*t[p].add;
		t[p*2].add=t[p*2].add*t[p].times+t[p].add;
		t[p*2+1].add=t[p*2+1].add*t[p].times+t[p].add;
		t[p*2].times*=t[p].times;
		t[p*2+1].times*=t[p].times;
    t[p*2].sum%=p1; //
		t[p*2+1].sum%=p1; //
		t[p*2].add%=p1;  //
		t[p*2+1].add%=p1; //
		t[p*2].times%=p1; //
		t[p*2+1].times%=p1; //
		t[p].add=0;
		t[p].times=1;
	}
}
void change_add(ll p,ll l,ll r,ll v)
{
	if(l<=t[p].l && t[p].r<=r){
		t[p].sum+=v*(t[p].r-t[p].l+1);
		t[p].add+=v; //区间加不变
		t[p].sum%=p1; //
		t[p].add%=p1; //
		return;
	}
	spread(p);
	ll mid=(t[p].l+t[p].r)/2;
	if(l<=mid) change_add(p*2,l,r,v);
	if(r>mid) change_add(p*2+1,l,r,v);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
	t[p].sum%=p1; //
}
void change_times(ll p,ll l,ll r,ll v)
{
	if(l<=t[p].l && t[p].r<=r){
		t[p].sum*=v; //区间同乘v,等于sum乘v
		t[p].add*=v; //加数也要乘v
		t[p].times*=v; //乘数也要乘v
		t[p].sum%=p1; //
		t[p].add%=p1; //
		t[p].times%=p1; //
		return;
	}
	spread(p);
	ll mid=(t[p].l+t[p].r)/2;
	if(l<=mid) change_times(p*2,l,r,v);
	if(r>mid) change_times(p*2+1,l,r,v);
	t[p].sum=t[p*2].sum+t[p*2+1].sum;
	t[p].sum%=p1; //
}
ll ask(ll p,ll l,ll r)
{
	if(l<=t[p].l && t[p].r<=r) return t[p].sum%p1; //
	spread(p);
	ll mid=(t[p].l+t[p].r)/2,v=0;
	if(l<=mid) v+=ask(p*2,l,r);
	if(r>mid) v+=ask(p*2+1,l,r);
	return v%p1; //
}
int main()
{
	n=read();
	m=read();
	p1=read();
	for(re int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	ll x,y,z;
	for(re int i=1;i<=m;i++)
	{
		x=read();
		if(x==1){
			x=read();
			y=read();
			z=read();
			change_times(1,x,y,z);
		}
		else if(x==2){
			x=read();
			y=read();
			z=read();
			change_add(1,x,y,z);
		}
		else{
			x=read();
			y=read();
			printf("%lld\n",ask(1,x,y)%p1);
		}
	}	
	return 0;
}
