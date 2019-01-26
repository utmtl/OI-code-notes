//AC机原理见简单版
//复杂版的意义在于告诉你如何统计各字符串出现次数并排序
#include<cstdio>
#include<cstring>
#include<queue>
#define re register
#define in inline
using namespace std;
int n;
char str[160][75];
int trie[100010][26],endd[100010],fail[100010],cnt=1,ans[100010];
in void insert(char *str,int num)
{
    int l=strlen(str),p=1;
    for(re int i=0;i<l;++i)
    {
        if(!trie[p][str[i]-'a']) trie[p][str[i]-'a']=++cnt;
        p=trie[p][str[i]-'a'];
    }
    endd[p]=num;
}
in void build()
{
    queue<int> q;
    for(re int i=0;i<26;++i) trie[0][i]=1;
    q.push(1);
    fail[1]=0;
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(re int i=0;i<26;++i)
        {
            if(trie[p][i]){
                fail[trie[p][i]]=trie[fail[p]][i];
                q.push(trie[p][i]);
            }
            else trie[p][i]=trie[fail[p]][i];
        }
    }
}
in void find(char *str)
{
    int p=1,l=strlen(str);
    for(re int i=0;i<l;++i)
    {
        p=trie[p][str[i]-'a'];
        for(re int j=p;(j!=0)&&(endd[j]!=-1);j=fail[j])
            if(endd[j]) ++ans[endd[j]];
    }
}
int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n==0) break;
        for(re int i=1;i<=n;++i)
        {
            scanf("%s",str[i]);//因为要输出出现得最多的字符串们, 所以要把这些模式串都存起来, 而不是仅存在于Trie中(不好输出)
            insert(str[i],i);//插入的时候把该字符串的编号标记在末尾节点上, 检索到此字符串时就可以直接输出或引用而不是沿着Trie找整个串
        }
        char s[1000001];
        scanf("%s",s);
        build();
        find(s);
	    	int maxx=0;//这里只找了出现的最多的, 也可以sort一下, 但要把ans开成结构体, 记录字符串编号和出现次数
	    	for(re int i=1;i<=n;++i)
			      if(ans[i]>maxx) maxx=ans[i];
		    printf("%d\n",maxx);
		    for(re int i=1;i<=n;++i)
			      if(ans[i]==maxx) printf("%s\n",str[i]);
        memset(trie,0,sizeof(trie));
        memset(endd,0,sizeof(endd));
        memset(fail,0,sizeof(fail));
        memset(ans,0,sizeof(ans));
        cnt=1;
    }
    return 0;
}
