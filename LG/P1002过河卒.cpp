#include<iostream>
using namespace std;
long long a[25][25],endx,endy,maxx,may;
bool map[26][26];
int main()
{
    cin>>endx>>endy>>maxx>>may;
    int dx[10]={-2,-2,-1,-1,2,2,1,1};
    int dy[10]={-1,1,-2,2,-1,1,-2,2};
    for(int i=0;i<8;i++){
    	if(maxx+dx[i]>=0 && may+dy[i]>=0) map[maxx+dx[i]][may+dy[i]]=1;
	}
	map[maxx][may]=1;
    a[0][0]=1;
    for(int i=0;i<=endx;i++)
    {
        for(int j=0;j<=endy;j++)
        {
            if(i==0 && j==0) continue;
            if(i==0 && map[i][j]==0) a[i][j]=a[i][j-1];
            else if(j==0 && map[i][j]==0) a[i][j]=a[i-1][j];
            else if(map[i][j]==0) a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    cout<<a[endx][endy];
    return 0;
}
