#include<cstdio>
int main()
{
    int x,y;
    scanf("%d%d",&x,&y);
    x^=y;
    y^=x;
    x^=y;
    printf("%d %d\n",x,y);
    return 0;
}
