//Dijsktra�ڽӾ���ʵ�� 
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m,map[1100][1100],dis[1100],bo[1100],s,t;
const int maxw=1061109567;
inline int minn(int x,int y)
{
	return x>y?x:y;
}
int main()
{
    while(cin>>n>>m)
    {
        int a,b,w;
        //��ʼ��map���Բ�������for�� 
        memset(map,0x3f,sizeof(map));
        for(int i=0;i<n;i++) map[i][i]=0;
        memset(bo,0,sizeof(bo));
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            map[a][b]=min(map[a][b],w);
            map[b][a]=min(map[b][a],w);
            //�ӵ㣺ͬһ���߿����ظ����룬һ��Ҫȡһ��min 
        }
        scanf("%d%d",&s,&t);
        for(int i=0;i<n;i++) dis[i]=map[s][i];
        dis[s]=0;
        bo[s]=1;
        int u;
        for(int i=0;i<n-1;i++)
        {
        	int minn=maxw;
        	u=-1; 
        	for(int j=0;j<n;j++) if(bo[j]==0 && dis[j]<minn) minn=dis[j],u=j; //�ҵ�dis��С����û���ʹ����Ǹ�����Ϊ�ɳڵ���� 
        	if(u==-1) break; //ȫ���ѷ���������� 
        	bo[u]=1; //���Ϊ�ѷ��� 
        	for(int j=0;j<n;j++) //�ɳ� 
        	{
        		if(map[u][j]+dis[u]<dis[j]) dis[j]=map[u][j]+dis[u];
			}
		}
        if(dis[t]!=maxw) printf("%d\n",dis[t]);
        else printf("-1\n");
	}
    return 0;
}
