/*

最直接的思路是 n^2 枚举所有点对计算异或值, LCA预处理一下可以拿满暴力分

在LCA基础上我们很容易发现只要dfs预处理出每个点到根节点路径上的异或之和d[x], 那么x,y两点之间路径异或和就为d[x]^d[y]

这是因为x^x=0, 也就是他们最近公共祖先以上的部分异或和直接抵消了

所以问题就变成了在d[1~n]中任选两个数, 使他们的异或值最大, 愉快的变成了Trie树板子题

详细讲, 基于贪心思想, 选一对数x,y, 从高位到低位, 要尽量满足每一位都不同, 其次暂时考虑让他们相同

把 d[1~n] 构造成一颗trie, 就能方便地把d中的一个数拿出来与其他所有串匹配, 找到异或值最大的那个

把1~n每个数拿出来匹配一次即得最优答案

吐槽:考场上被快读坑了一把, 详见代码, 压行害人不浅!!!
*/
#include<cstdio>
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
        s=(s<<3)+(s<<1)+(ch^'0');
        ch=getchar();
    }
    return b?-s:s;
}
int n;
struct edge{
    int t,w,nxt;
}e[100001*2];
int head[100001],cnt=0;
in void add(int f,int t,int w)
{
    e[++cnt].t=t;
    e[cnt].w=w;
    e[cnt].nxt=head[f];
    head[f]=cnt;
    e[++cnt].t=f;
    e[cnt].w=w;
    e[cnt].nxt=head[t];
    head[t]=cnt;
}
int d[100001];
void dfs(int now,int fa)
{
    for(re int i=head[now];i;i=e[i].nxt)
    {
        if(e[i].t!=fa){
            if(now!=1) d[e[i].t]=d[now]^e[i].w;
            else d[e[i].t]=e[i].w;
            dfs(e[i].t,now);
        }
    }
}
int trie[9999999][2],cntt=1;
in void insert(int a)
{
    int p=1;
    for(re int i=30;i>=0;--i)
    {
        int ch=(a>>i)&1;
        if(!trie[p][ch]) trie[p][ch]=++cntt;
        p=trie[p][ch];
    }
}
in int find(int a)
{
    int p=1,ans=0;
    for(re int i=30;i>=0;--i)
    {
        int ch=!((a>>i)&1);
        if(!trie[p][ch]){
            if(trie[p][!ch]) p=trie[p][!ch];
            else return ans;
        }
        else p=trie[p][ch],ans+=(1<<i);
    }
    return ans;
}
signed main()
{	
    n=read();
    int f,t,w;
    for(re int i=1;i<=n-1;++i)
    {
        //add(read(),read(),read());
        //上面是错误写法!!!三个read()是从右至左执行的, 参数顺序错误!!!
        f=read();
        t=read();
        w=read();
        add(f,t,w);
    }
    dfs(1,0);
    for(re int i=1;i<=n;++i)
        insert(d[i]);
    int ans=0;
    for(re int i=1;i<=n;++i)
    {
        int t=find(d[i]);
        if(t>ans) ans=t;
    }
    printf("%d\n",ans);
    return 0;
}
