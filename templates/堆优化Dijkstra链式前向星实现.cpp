#include<cstdio>
#include<queue>
#define re register
using namespace std;
int n,m,cnt,s,head[600000],dis[600000];
struct edge{
    int next;
    int to;
    int w;
}e[600000];
struct node{
    int num;
    int dis;
    bool operator < (const node &that)const //这个const保证下面的结构体成员不被修改，不加会CE 
	{
        if(dis>that.dis) return true;
        else return false;
    } //将STL优先队列默认的大根堆改为小根堆 
};
priority_queue<node> q;
inline void add(int f,int t,int w)
{
    cnt++; //边数+1 
    e[cnt].next=head[f]; //原先连在from节点上的第一条边接在新插入的边的后面 
    e[cnt].to=t;
    e[cnt].w=w;
    head[f]=cnt; //把新插入的边设为from节点连的第一条边 
    //注意：不能把新边接在尾部，不然又要花O（n）的时间遍历来找到尾部位置，因为你只存了头部位置（head数组） 
}
int main()
{
    scanf("%d%d%d",&n,&m,&s); //s为起始点 
    int a,b,w;
    for(re int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&w);
        add(a,b,w);
        //add(b,a,w);
    }
    for(re int i=1;i<=n;i++) dis[i]=2147483647;
    dis[s]=0;
    node str;
    str.num=s;
    str.dis=0;
    q.push(str);
    int u,v;
    while(!q.empty())
	{
        node x=q.top();
        q.pop();
        u=x.num;
        if(x.dis!=dis[u]) continue;
        /*
		由于把更新最小值后的点入队后没有删除队列中原来的这个点
		为防止再以这个旧点为起点松弛，要判断一下这个点是不是最新的最小点，看看最小距离是不是最新的即可 
		即防止重复, 本质就是懒惰删除法 
	*/
        for(re int i=head[u];i!=0;i=e[i].next) //枚举这个最近点相邻的边来进行松弛 
        {
            v=e[i].to;
            w=e[i].w;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                node x1;
                x1.dis=dis[v];
                x1.num=v;
                q.push(x1); //把最小值更新了的点入队 
            }
       }
    }
    for(re int i=1;i<=n;i++) printf("%d ",dis[i]);
    return 0;
}
