#include<iostream>
using namespace std;
int r,c,a[500][500],maxx,mem[500][500];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int dfs(int x,int y)
{
	if(mem[x][y]!=0) return mem[x][y]; //���Ⱦʹ����Ѿ��ѹ������ 
	int maxxx=1;
	for(int i=0;i<4;i++)
	{
		int x1=x+dx[i],y1=y+dy[i];
		if(x1>=0 && x1<r && y1>=0 && y1<c && a[x1][y1]<a[x][y]){
			int t=dfs(x1,y1)+1;
			if(t>maxxx) maxxx=t;
		}
	}
	mem[x][y]=maxxx; //��¼�˵�Ϊ��������� 
	return maxxx; //�����Ǵ˵�Ϊ��������£������������ĸ��������ȡ���ֵ������ѭ����return 
}
int main()
{
	cin>>r>>c;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			cin>>a[i][j];
		}
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<c;j++)
		{
			int t=dfs(i,j);
			if(t>maxx) maxx=t;
		}
	}
	cout<<maxx;
	return 0;
}
