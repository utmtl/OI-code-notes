//真正的pollard_pho大质因数分解: https://www.luogu.org/blog/user7035/solution-p4718
#include<cstdio>
#include<time.h>
#include<cstdlib>
#define re register
#define in inline
#define int long long
int n,x1,x2,c,e,C,x,y;
in int abs(int a)
{
	if(a>=0) return a;
	return -a;
}
in int ch(int a,int b,int yyb)
{
    int res=0;
    while(b)
	{
        if(b&1) res=(res+a)%yyb;
        a=(a+a)%yyb;
        b>>=1;
    }
    return res;
}//快速乘原理: a*11=a*(2^3+2^1+2^0) 然后分配律展开(类似于快速幂)
in int ksm(int a,int b,int yyb)
{
	int ans=1;
	while(b){
		if(b&1)	ans=ch(ans,a,yyb);
		a=ch(a,a,yyb);
		b>>=1;
	}
	return ans;
}
in int gcd(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
}
void exgcd(int a,int b)
{
	if(!b){x=1,y=0;return;}
	exgcd(b,a%b);
	int t=x;
	x=y,y=t-a/b*y;
}
signed main()
{
	srand(time(NULL));
	scanf("%lld%lld%lld",&e,&n,&C);
	int x1=rand()%(n-1)+1,x0=x1,i=1,k=2,c=rand()%n,r,d,t;
	//先随机钦定x1,x2,常数c
	while(1)
	{
		x1=(ch(x1,x1,n)+c)%n;//x1通过伪随机算法生成:x=(x^2+c)%n
		t=gcd(abs(x1-x0)%n,n);
        //pollard_rho分解两质数乘积:
		//通过在2~n-1内随机生成两个数x0,x1看gcd(x0-x1,n)是不是在2~n-1中, 而不是一个个试除
		//原理同生日悖论, 在一堆人中钦定一个确切的生日符合的概率远小于两个人生日重复的概率
		if(1<t&&t<n) break;
		if(x1==x0) x1=rand()%(n-1)+1,x0=x1,i=1,k=2,c=rand()%n;//若x1=x0则随机数生成器遇到了环, 重置一下
		++i;
		if(i==k) x0=x1,k<<=1;
//内存不够不能记录所有随机值来判断随机数生成是否陷入环
//判断环时, 限制环的长度为k, 做了k次后没遇到环就认为没有, 重置环的起点x0, 并把k倍增
		//玄学部分: 钦定的伪随机算法加上k倍增限制可以获得较好的效率
	}
	r=(t-1)*(n/t-1);
	exgcd(e,r);//分解完之后用exgcd解线性同余方程即可
	d=(x%r+r)%r;
	printf("%lld %lld\n",d,ksm(C,d,n));
	return 0;
}
