// luogu-judger-enable-o2
#include<cstdio>
#include<cstring>
#define re register
#define int long long
#define in inline
int n,m;
struct edge{
    int t,next;
}e[5010*2];
int head[5010],cnt,shan;
in void add(int f,int t)
{
    e[++cnt].t=t;
    e[cnt].next=head[f];
    head[f]=cnt;
    e[++cnt].t=f;
    e[cnt].next=head[t];
    head[t]=cnt;
}
int b[5010];//标记节点是否已经访问过
void dfs(int now)
{
    int minn;
    do{
        minn=2147483647;
        for(re int i=head[now];i;i=e[i].next)
            if(e[i].t<minn && !b[e[i].t]) minn=e[i].t;
        if(minn!=2147483647){
            printf("%lld ",minn);
            b[minn]=1;
            dfs(minn);
        }
    }while(minn!=2147483647);
}//树的情况直接贪心遍历一次
int path[5001],pc[5001];
//path中存放字典序最小的路径 pc中临时存当前正在生成的路径
int flag,ff;
//flag 一旦当前路径字典序大于最优解 直接return
//ff 在第一次pc[x]<path[x]时变为0 因为这时pc字典序已经比path小 防止后面再有path[y]<pc[y]导致误判
void dfs2(int now)
{
    if(flag) return;
    int minn;
    do{
        minn=2147483647;
        for(re int i=head[now];i;i=e[i].next)
            if(e[i].t<minn && !b[e[i].t] && i!=shan && i!=shan+1) minn=e[i].t;
        if(minn!=2147483647){
            if(minn>path[cnt+1] && ff) {flag=1;return;}
            else if(minn<path[cnt+1]) ff=0;//比较字典序
            pc[++cnt]=minn;//记录路径
            b[minn]=1;
            dfs2(minn);
        }
    }while(minn!=2147483647);
}
signed main()
{
    scanf("%lld%lld",&n,&m);
    int f,t;
    for(re int i=1;i<=m;++i)
    {
        scanf("%lld%lld",&f,&t);
        add(f,t);
    }
    if(m==n-1){
        b[1]=1;
        printf("1 ");
        dfs(1);
    }
    else{
        for(re int i=0;i<5001;++i) path[i]=2147483647;
        for(shan=1;shan<=2*m;shan+=2)//易知基环树的情况下必有环上的一条边不会经过 所以枚举删边当作树就可以处理了
        {
            memset(b,0,sizeof(b));
            b[1]=1;
            flag=0;
            path[1]=1;
            ff=1;
            cnt=1;
            dfs2(1);
            if(!flag && cnt==n){//字典序小(!flag)且是联通的(cnt==n)
                for(re int i=1;i<=n;++i)
                    path[i]=pc[i];
            }
        }
        for(re int i=1;i<=n;++i) printf("%lld ",path[i]);
    }
    return 0;
}
