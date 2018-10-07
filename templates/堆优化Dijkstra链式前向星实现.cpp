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
    bool operator < (const node &that)const //���const��֤����Ľṹ���Ա�����޸ģ����ӻ�CE 
	{
        if(dis>that.dis) return true;
        else return false;
    } //��STL���ȶ���Ĭ�ϵĴ���Ѹ�ΪС���� 
};
priority_queue<node> q;
inline void add(int f,int t,int w)
{
	cnt++; //����+1 
    e[cnt].next=head[f]; //ԭ������from�ڵ��ϵĵ�һ���߽����²���ıߵĺ��� 
    e[cnt].to=t;
    e[cnt].w=w;
    head[f]=cnt; //���²���ı���Ϊfrom�ڵ����ĵ�һ���� 
    //ע�⣺���ܰ��±߽���β������Ȼ��Ҫ��O��n����ʱ��������ҵ�β��λ�ã���Ϊ��ֻ����ͷ��λ�ã�head���飩 
}
int main()
{
    scanf("%d%d%d",&n,&m,&s); //sΪ��ʼ�� 
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
    q.push(str;
    int u,v;
    while(!q.empty())
	{
        node x=q.top();
        q.pop();
        u=x.num;
        if(x.dis!=dis[u]) continue;
        /*
		���ڰѸ�����Сֵ��ĵ���Ӻ�û��ɾ��������ԭ���������
		Ϊ��ֹ��������ɵ�Ϊ����ɳڣ�Ҫ�ж�һ��������ǲ������µ���С�㣬������С�����ǲ������µļ��� 
		����ֹ�ظ� 
		*/
        for(re int i=head[u];i!=0;i=e[i].next) //ö�������������ڵı��������ɳ� 
        {
            v=e[i].to;
            w=e[i].w;
            if(dis[u]+w<dis[v]){
                dis[v]=dis[u]+w;
                node x1;
                x1.dis=dis[v];
                x1.num=v;
                q.push(x1); //����Сֵ�����˵ĵ���� 
            }
       }
    }
    for(re int i=1;i<=n;i++) printf("%d ",dis[i]);
    return 0;
}
