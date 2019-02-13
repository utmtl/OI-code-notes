#include<cstdio>
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
int n,base[64];
in void insert(int x)
{
    for(re int i=62;i>=0;--i)
    {
        if(!(x&((int)1<<i))) continue;//千万记得要把1强制转换成long long!!!不然1默认为int型, 会炸!!!
        if(!base[i]) {base[i]=x;break;}
        x^=base[i];
    }
}	
signed main()
{
    n=read();
    for(re int i=1;i<=n;++i) insert(read());
    int ans=0;
    for(re int i=62;i>=0;--i)
        if((ans^base[i])>ans) ans^=base[i];
    printf("%lld\n",ans);
    return 0;
}
