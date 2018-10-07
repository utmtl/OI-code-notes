//可AC的神仙代码 
#include<iostream>
#include<cstdio>
#include<cstring>
#define mmp int
using namespace std;
mmp n,m,_____[1100][1100],____[1100],______[1100],_______,________;
const mmp maxw=1061109567;
inline mmp $(mmp x,mmp y)
{
	return x>y?x:y;
}
mmp main()
{
    while(cin>>n>>m)
    {
        mmp a,b,w;
        memset(_____,0x3f,sizeof(_____));
        for(mmp _=0;_<n;_++) _____[_][_]=0;
        memset(______,0,sizeof(______));
        for(mmp _=1;_<=m;_++)
        {
            scanf("%d%d%d",&a,&b,&w);
            _____[a][b]=min(_____[a][b],w);
            _____[b][a]=min(_____[b][a],w);
        }
        scanf("%d%d",&_______,&________);
        for(mmp _=0;_<n;_++) ____[_]=_____[_______][_];
        ____[_______]=0;
        ______[_______]=1;
        mmp u;
        for(mmp _=0;_<n-1;_++)
        {
        	mmp $=maxw;
        	u=-1;
        	for(mmp __=0;__<n;__++) if(______[__]==0 && ____[__]<$) $=____[__],u=__;
        	if(u==-1) break;
        	______[u]=1;
        	for(mmp __=0;__<n;__++)
        	{
        		if(_____[u][__]+____[u]<____[__]) ____[__]=_____[u][__]+____[u];
			}
		}
        if(____[________]!=maxw) printf("%d\n",____[________]);
        else printf("-1\n");
	}
    return 0;
}
