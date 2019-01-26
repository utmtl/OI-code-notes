#include<cstdio>
#include<cstring>
#include<queue>
#define re register
#define in inline
using namespace std;
int n;
char str[1000010];
int trie[1000010][26],endd[1000010],fail[1000010],cnt=1;
in void insert(char *str)
{
	int l=strlen(str),p=1;
	for(re int i=0;i<l;++i)
	{
		if(!trie[p][str[i]-'a']) trie[p][str[i]-'a']=++cnt;
		p=trie[p][str[i]-'a'];
	}
	++endd[p];
}//普通的Trie
in void build()
{
	queue<int> q;
	for(re int i=0;i<26;++i) trie[0][i]=1;//若在根节点失配, p=fail[1]=0, 需要使之重新指向1进行下一次匹配
	q.push(1);
	fail[1]=0;//根节点失配直接无法继续匹配
	while(!q.empty())
	{
		int p=q.front();
		q.pop();
		for(re int i=0;i<26;++i)
		{
			if(trie[p][i]){
				fail[trie[p][i]]=trie[fail[p]][i];
				//若此模式串字符i失配, 则跳转到另一个具有相同前缀的模式串(或根节点)继续匹配
				q.push(trie[p][i]);
			}
			else trie[p][i]=trie[fail[p]][i];
			//若此模式串根本不存在此字符, 则直接跳转到另一个前缀与与此模式串后缀相同的模式串上继续匹配
			//即str=***sbhe s1=***sb s2=sbhe p指向s1[6]时发现不存在, 但s1[4~5]=s2[1~2], 所以直接p指向s2[3]继续匹配
		}
	}
}
in int find(char *str)
{
	int p=1,l=strlen(str),tot=0;
	for(re int i=0;i<l;++i)
	{
		p=trie[p][str[i]-'a'];
		for(re int j=p;(j!=0)&&(endd[j]!=-1);j=fail[j]) tot+=endd[j],endd[j]=-1;
		//j==0: 当前模式串匹配失败;endd[j]==-1: 已统计过该文本串  都要++i匹配文本串的下一起点
	}
	return tot;
}
int main()
{
	scanf("%d",&n);
	for(re int i=1;i<=n;++i)
	{
		scanf("%s",str);
		insert(str);
	}
	scanf("%s",str);
	build();
	printf("%d\n",find(str));
	return 0;
}
