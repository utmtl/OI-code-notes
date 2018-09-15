#include<iostream>
using namespace std;
int n,m,x;
struct node{
    int a,b,c;
}a[1000];
int s,c,maxx,ans;
void dfs(int step)
{
    if(s>m || c>x || step>n) return;
    s+=a[step].b;
    c+=a[step].c;
    ans+=a[step].a;
    if(s<=m && c<=x)
    {
        if(ans>maxx) maxx=ans;
        dfs(step+1);
    }
    s-=a[step].b;
    c-=a[step].c;
    ans-=a[step].a;
    dfs(step+1);
}
int main()
{
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i].a>>a[i].b>>a[i].c;
    dfs(1);
    cout<<maxx;
    return 0;
}
