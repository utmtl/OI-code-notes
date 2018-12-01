#include<cstdio>
#define re register
#define in inline
in int read()
{
    int s=0,b=1;
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
int n,m,s;
struct edge{
    int t,next;
}e[500001*2];
int cnt=0,head[500001];
in void add(int f,int t)
{
    ++cnt;
    e[cnt].t=t;
    e[cnt].next=head[f];
    head[f]=cnt;
}
int f[500001][100],d[500001]; //f[i][j]: i号节点往上走2^j次的父亲编号. d[i]: i号节点的深度(root深度为1)
int log[500001];
void dfs(int now,int fa)
{
    d[now]=d[fa]+1;
    f[now][0]=fa;
    for(re int i=1;(1<<i)<=d[now];++i)//注意不能跳到root上面去了
        f[now][i]=f[f[now][i-1]][i-1]; //预处理出所有倍增跳法的结果, 利用now的2^i辈父亲 = 2^(i-1)辈父亲的2^(i-1)辈父亲, 而now的2^(i-1)辈父亲之前已经算出来. 类似于递推.
    for(re int i=head[now];i;i=e[i].next)
        if(e[i].t!=fa) dfs(e[i].t,now);
}//Dfs预处理出f数组, 便于一会儿倍增地向上跳跃. 顺便求d数组.
in int lca(int x,int y)
{
    if(d[x]<d[y])
    {
        int t=x;
        x=y;
        y=t;
    }//保证x在y下
    while(d[x]!=d[y]) x=f[x][log[d[x]-d[y]]]; //x先跳到与y同深度. 这时可以根据f数组倍增地向上跳(利用了每个数都可以写成二进制), 比如本来要跳13(二进制: 1101)下, 现在可以先跳2^3下, 再跳2^2下, 再跳2^0下.
    if(x==y) return x;
    for(re int i=log[d[x]];i>=0;--i)
        if(f[x][i]!=f[y][i]) x=f[x][i],y=f[y][i]; //同理, x y同步倍增地向上跳, 直至它们有相同的父亲. 不能跳到x==y, 因为公共祖先为root时这样判断会有玄学错误.
    return f[x][0]; //x y的父亲即公共祖先.
}
int main()
{
    n=read();
    m=read();
    s=read();
    int x,y;
    int t=1;
    log[1]=0;
    for(re int i=2;i<=n;++i)
    {
        if((1<<(t+1))==i) t++;
        log[i]=t;
    }//预处理出log_2(1~n)的值;
    for(re int i=1;i<=n-1;++i)
    {
        x=read();
        y=read();
        add(x,y);
        add(y,x);
    }
    dfs(s,0);
    for(re int i=1;i<=m;++i)
    {
        x=read();
        y=read();
        printf("%d\n",lca(x,y));
    }
    return 0;
}
