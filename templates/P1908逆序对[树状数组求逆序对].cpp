/*
树状数组求逆序对模板 
简单来说,逆序数就是找 每一个数的前面有几个比他的大的数,加起来的和就是逆序对的总数
基于类似桶排的思想,a[n]=x则代表要求逆序数的数组里有x个数为n,=0代表没有n 
再用一个树状数组c维护a的前缀和,就可以知道a中的每个数n前面有几个数比它小
用这是第几个数(循环变量i)减去前面比这个数小的数的个数,即可的它的前面有多少数比它大
对于每个数这样做然后加起来即可得总逆序数 
--- 
逆序数和数据的具体大小无关,只和它们之间的相对大小关系有关,因此可以用离散化防止n过大炸数组(类似于桶排) 
*/
//十年竞赛一场空,没开longlong见祖宗 
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
long long c[200000],lsh_cp[200000],n,k;
struct node{
	long long id,data;
	bool operator < (const node &that)const
	{
		if(data<that.data) return true;
		else return false;
	}
}lsh[200000];
inline long long lowbit(long long x)
{
	return (x&(-x));
}
inline void add(long long i,long long x)
{
	while(i<=n)
	{
		c[i]+=x;
		i+=lowbit(i);
	}
}
inline long long sum(long long i)
{
	long long ans=0;
	while(i>=1)
	{
		ans+=c[i];
		i-=lowbit(i);
	}
	return ans;
}
inline long long max(long long x,long long y)
{
	return x>y?x:y;
}
int main()
{
	long long s;
	cin>>n>>k;
	s=0;
	//memset(c,0,sizeof(c));
	//memset(lsh,0,sizeof(lsh));
	//memset(lsh_cp,0,sizeof(lsh_cp));
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&lsh[i].data);
		lsh[i].id=i; //记录这个数的原位置 
	}
	sort(lsh+1,lsh+n+1); //先按数值大小排序 
	long long cnt=1;
	for(long long i=1;i<=n;i++)
	{
		if(i!=1 && lsh[i].data!=lsh[i-1].data) cnt++; //离散化注意去重 
		lsh_cp[lsh[i].id]=cnt; //再按数值从小到大的顺序依次赋上值1~n, 既保证了相对大小关系不变, 又防止了n过大数组越界 
	}
	//整个离散化过程相当于把lsh拷贝到lsh_cp中,保持相对大小关系不变,收缩极差 
	for(long long i=1;i<=n;i++)
	{
		add(lsh_cp[i],1);
		s=s+i-sum(lsh_cp[i]);
	}
	printf("%lld\n",max(s-k,0));
	return 0;
}
