#include<iostream>
#include<map>
#include<queue>
using namespace std;
int n=1;
string rules[30][2];
struct node{
	string data;
	int step;
};
node a,b;
queue<node> q;
map<string,bool> book;
string check(const string &s,int i,int j)
{
	//一个神奇的check函数 
	if(rules[j][0].length()+i>s.length()) return ""; //首先判断要匹配的rules是否超出总串s长度 
	for(int v=0;v<rules[j][0].length();v++)
	{
		if(s[i+v]!=rules[j][0][v]) return ""; //匹配中 
	}
	return s.substr(0,i)+rules[j][1]+s.substr(i+rules[j][0].length());
	/*
		important:
		直接重新构造新总串，而不是在原s中替换，避免rules0和rules1长短不同造成替换时的各种麻烦
		妙（尿）啊~ 
		s.substr(i)=取s[i]到s末尾的字符串
		s.substr(i,n)=取从s[i]到s[i+n]的字符串 
	*/
}
int bfs()
{
	do{
		node x;
		x=q.front();
		q.pop();
		if(x.step>10) return -1;
		if(x.data==b.data) return x.step;
		if(book[x.data]==1) continue;
		book[x.data]=1;
		//剪枝：不重复拓展同一x.data，否则MLE 
		for(int i=0;i<x.data.length();i++)
		{//枚举起始位置 
			for(int j=1;j<=n;j++)
			{//枚举不同规则 
				string t=check(x.data,i,j);
				if(t!=""){
					node y;
					y.data=t;
					y.step=x.step+1;
					q.push(y);
				}
			}
		}
	}while(!q.empty());
	return -1; //Don't forget!若队列空了还没变成b则也没有答案 
}
int main()
{
	cin>>a.data>>b.data;
	a.step=0;
	b.step=0;
	while(cin>>rules[n][0]>>rules[n][1]) n++;
	q.push(a);
	int x=bfs();
	if(x==-1) cout<<"NO ANSWER!";
	else cout<<x;
	return 0;
}
