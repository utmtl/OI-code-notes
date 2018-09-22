#include<cstdio>
#include<cstring>
int n,ha,la,hb,lb;
char a[200][200];
bool b[200][200],flag;
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int x1=x+dx[i],y1=y+dy[i];
		if(x1>=0 && y1>=0 && x1<n && y1<n && b[x1][y1]==0 && a[x1][y1]!='#'){
			b[x1][y1]=1;
			if(x1==hb && lb==y1){
				flag=true;
			}
			else dfs(x1,y1);
			//b[x1][y1]=0;
                        //不用回溯，因为已经试探过的路是不通的,else TLE
		}
	}
}
int main()
{
	int k,i,j;
	scanf("%d",&k);
	for(i=0;i<k;i++)
	{
		memset(b,0,sizeof(b));
		flag=false;
		scanf("%d",&n);
		for(j=0;j<n;j++)
		{
			scanf("%s\n",a[j]);
		}
		scanf("%d%d%d%d",&ha,&la,&hb,&lb);
		if(a[ha][la]=='#' || a[hb][lb]=='#'){
			printf("NO\n");
			continue;
		}
		dfs(ha,la);
		if(flag==true) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
