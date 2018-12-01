#include<cstdio>
int gcd_DestoryStack(int a,int b)
{
    if(!b) return a;
    return gcd_DestoryStack(b,a%b); //原理: gcd(a,b)==gcd(b,a%b)
}
int gcd(int a,int b)
{
    while(b^=a^=b^=a%=b);
    return a;
/*line 4解析:
    (注意b^=...等缩写的运算返回运算后的b值)
    a%=b;
    b^=a^=b^=a;
    即
    a%=b;
    b^=a;
    a^=b;
    b^=a;
    即
    a%=b;
    swap(a,b);
    执行条件是b!=0
    即
    while(b!=0)
    {
    	a%=b; //运算后a<b
	swap(a,b); //要保证a中的值始终比b大
    }
*/
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
	int t=gcd(a,b);
    printf("gcd: %d lcm: %d\n",t,a*b/t);
    return 0;
}
