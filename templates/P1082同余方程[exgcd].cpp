//这篇不错: https://www.luogu.org/blog/costudy/solution-p1082
#include<cstdio>
#define re register
#define in inline
int x,y;
void exgcd(int a,int b)
{
	if(!b){x=1,y=0;return;}//最后b会变为0, 方程ax+by=gcd(a,b)=a在x=1,y=0时必然成立
	exgcd(b,a%b);//求解方程bx'+(a%b)y'=gcd(b,a%b)
    //得到一组解x',y'满足bx'+(a%b)y'=gcd(b,a%b)后,
	//则方程ax+by=gcd(a,b)在x=y',y=x'-(a/b)*y'时必然成立
	int t=x;
	x=y;
	y=t-(a/b)*y;
}
signed main()
{
	/*
问题转化:
ax = 1 (mod b) 实际上是求ax+by=1的一组解中的x
而ax+by=1有解仅当gcd(a,b)|1
所以gcd(a,b)=1
即求ax+by=gcd(a,b)的解x
	*/
	int a,b;
	scanf("%d%d",&a,&b);
	exgcd(a,b);
	printf("%d\n",(x%b+b)%b);//相当于while(x<0){x+=b;}x%=b; 保证x为最小正整数解
	return 0;
}
